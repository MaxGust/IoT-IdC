#include <Wire.h>
#include "SparkFunMPL3115A2.h"
MPL3115A2 myPressure;
//---------TCA9548A---------
#define TCAADDR 0x70
void TCA_channel(uint8_t i) {
  if (i > 7) return; 
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission(); 
}
//--------------------------
void setup()
{
  Wire.begin(1);      //atribuir endereço para 2ºteste comunicar master
  Serial.begin(9600);
TCA_channel(2);
//------------ Sensor de Altitude e Pressão MPL3115A2-------
  myPressure.begin(); // Get sensor online
  myPressure.setModeBarometer(); // Measure pressure in Pascals from 20 to 110 kPa
  myPressure.setOversampleRate(7); // Set Oversample to the recommended 128
  myPressure.enableEventFlags(); // Enable all three pressure and temp event flags
  //-------------FIM Sensor ALT e PA ------MPL3115A2
//--- Ler UNO--------
TCA_channel(7);
}

void loop()
{
//---------- Sensor Pressão MPL3115A2 -------
 TCA_channel(2);
 float temperature = myPressure.readTemp();
 Serial.print(F(" Temp(c):"));
 Serial.println(temperature, 2);
 float pressure = myPressure.readPressure() * 0.01;
  Serial.print(F(" Pressure(mb):")); //milibares
  Serial.println(pressure, 2);
  pressure = round(pressure);
  float altitude = (1-pow(pressure/1013.25,0.190284))*145366.45;
  Serial.print(F(" Altitude(ft):"));
  Serial.println(altitude, 2);
Serial.println("-------------");
//-------------------------------------------
  delay(1000);
  //-------------------------
  //--- tentar ler UNO--------
  TCA_channel(7);
  Wire.requestFrom(5,10); //endereço 5 e 10 tamanho de caracteres
  while(Wire.available())   //se o endereço for valido
  {
    char c = Wire.read();   //então pede a informação
    Serial.print(c);        //Mostra a informação
   }
  Serial.println("--");
  delay(1000);
//------------------------------
  
}

  
