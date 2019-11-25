//#include <Wire.h>
#include "MAX30105.h"
#include "spo2_algorithm.h"

MAX30105 particleSensor;

#define MAX_BRIGHTNESS 255

#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__)
//Arduino Uno doesn't have enough SRAM to store 100 samples of IR led data and red led data in 32-bit format
//To solve this problem, 16-bit MSB of the sampled data will be truncated. Samples become 16-bit data.
uint16_t irBuffer[100]; //infrared LED sensor data
uint16_t redBuffer[100];  //red LED sensor data
#else
uint32_t irBuffer[100]; //infrared LED sensor data
uint32_t redBuffer[100];  //red LED sensor data
#endif

int8_t bufferLength; //data length
int32_t spo2; //SPO2 value
int8_t validSPO2; //indicator to show if the SPO2 calculation is valid
int32_t heartRate; //heart rate value
int8_t validHeartRate; //indicator to show if the heart rate calculation is valid

byte pulseLED = 11; //Must be on PWM pin
byte readLED = 13; //Blinks with each data read
byte SPO2Msg; //guardar valor 

void setup()
{
  Serial.begin(115200); // initialize serial communication at 115200 bits per second:

  pinMode(pulseLED, OUTPUT);
  pinMode(readLED, OUTPUT);

  // Initialize sensor
  particleSensor.begin(Wire, I2C_SPEED_FAST); //Use default I2C port, 400kHz speed
   while(Serial.available())
  Serial.read();
  byte ledBrightness = 60; //Options: 0=Off to 255=50mA ---- 60 está calibrado
  byte sampleAverage = 4; //Options: 1, 2, 4, 8, 16, 32
  byte ledMode = 2; //Options: 1 = Red only, 2 = Red + IR, 3 = Red + IR + Green
  byte sampleRate = 100; //Options: 50, 100, 200, 400, 800, 1000, 1600, 3200
  int pulseWidth = 411; //Options: 69, 118, 215, 411
  int adcRange = 4096; //Options: 2048, 4096, 8192, 16384

  particleSensor.setup(ledBrightness, sampleAverage, ledMode, sampleRate, pulseWidth, adcRange); //Configure sensor with these settings
}

void loop()
{
  //Tem de acumular registo para poder fazer SPO2 porque exige acumulação de valores - Formula
  bufferLength = 100; 
  for (byte i = 0 ; i < bufferLength ; i++)
  {
    while (particleSensor.available() == false) //do we have new data?
    particleSensor.check(); //Check the sensor for new data
    redBuffer[i] = particleSensor.getRed();
    irBuffer[i] = particleSensor.getIR();
    particleSensor.nextSample(); //We're finished with this sample so move to next sample
    Serial.print(F("red="));
    Serial.print(redBuffer[i], DEC);
    Serial.print(F(", ir="));
    Serial.print(irBuffer[i], DEC);
    Serial.print(F(", SPO2="));
    Serial.println(spo2, DEC);  
  }
 maxim_heart_rate_and_oxygen_saturation(irBuffer, bufferLength, redBuffer, &spo2, &validSPO2, &heartRate, &validHeartRate);
 Serial.println(F("--------------------------------------"));
 Serial.println(F("-----FIM Acumular 100 Registos-------")); 
 Serial.println(F("--------------------------------------"));
    for (byte i = 50; i < 100; i++)
    { //Vai ler os sensores
      redBuffer[i] = particleSensor.getRed();
      irBuffer[i] = particleSensor.getIR();
      particleSensor.nextSample(); //We're finished with this sample so move to next sample
      // Amostra os sensores
      Serial.print(F("red="));
      Serial.print(redBuffer[i], DEC);
      Serial.print(F(", ir="));
      Serial.print(irBuffer[i], DEC);
      Serial.print(F(", SPO2="));         //Valor acumulado do red e ir
      Serial.println(spo2, DEC);
      SPO2Msg = spo2;
    }
    Serial.println(F("--------------------------------------"));
    Serial.println(F("-----NOVOS Acumular 50 Registos-------"));
    Serial.println(F("--------------------------------------"));
    //GUarda as leituras
  maxim_heart_rate_and_oxygen_saturation(irBuffer, bufferLength, redBuffer, &spo2, &validSPO2, &heartRate, &validHeartRate);
    // Fazer o ciclo de 3 segundos para enviar mensagem
    //if (bufferLength = 100) e redBuffer maior que 20000 então 
    // byte x += 100
    //?!!!!!!!!
    //teste de variavel sair do ciclo For
    Serial.println(F("----------------------------------Msg-"));
    Serial.println(SPO2Msg, DEC);
    Serial.println(F("----------------------------------Msg-"));
} //FIM do Loop

// de 100 a 200 registos para obter uma leirua após retirar o dedo
// POrque o SPO2 pode estar acumulado do anterior

