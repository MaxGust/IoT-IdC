#include <Wire.h>
// Cooking API libraries
#include <arduinoUtils.h>
// Include the SX1272 and SPI library:
#include "arduinoLoRa.h"
#include <SPI.h>
//Sensor biblioteca
#include <Ultrasonic.h>
//Variaveis
int e;
//char message1 [] = "#GO2,32.00,-8.32,21,80";
char message2 [] = "";
//int sonic;
//Defenição de Pins de entrada (IN) Trig - 13 e Echo - 12
Ultrasonic ultrasonic(8, 9);

//String Ultra = String(sonic);

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  // Print a start message
  Serial.println(F("SX1272 module and Arduino: send packets with ACK"));
  // Power ON the module
  e = sx1272.ON();
  Serial.print(F("Setting power ON: state "));
  Serial.println(e, DEC);
  // Set transmission mode and print the result
  e |= sx1272.setMode(4);
  Serial.print(F("Setting Mode: state "));
  Serial.println(e, DEC);
  // Set header
  e |= sx1272.setHeaderON();
  Serial.print(F("Setting Header ON: state "));
  Serial.println(e, DEC);
  // Select frequency channel
  e |= sx1272.setChannel(CH_10_868);
  Serial.print(F("Setting Channel: state "));
  Serial.println(e, DEC);
  // Set CRC
  e |= sx1272.setCRC_ON();
  Serial.print(F("Setting CRC ON: state "));
  Serial.println(e, DEC);
  // Select output power (Max, High or Low)
  e |= sx1272.setPower('H');
  Serial.print(F("Setting Power: state "));
  Serial.println(e, DEC);
  // Set the node address and print the result
  e |= sx1272.setNodeAddress(3);
  Serial.print(F("Setting node address: state "));
  Serial.println(e, DEC);
  // Print a success message
  if (e == 0)
    Serial.println(F("SX1272 successfully configured"));
  else
    Serial.println(F("SX1272 initialization failed"));
}

void loop(void)
{
  //Variaveis para guardar e converter Int em Array char
  String str;         //Variavel de texto
  char c [] = "";     //Array em branco
  int sonic;          //Variavel de inteiro para guardar valor do UltraSonic
  sonic = ultrasonic.distanceRead(); //Ler e guardar na variavel do UltraSonic
  
  //Serial.println(ultrasonic.distanceRead()); //Mostra o valor do Ultrasonic
  str = String(sonic);    //Converte inteiro em texto
  str.toCharArray(c,5);   //Coloca o texto no Array
  
  // Send message1 and print the result
  e = sx1272.sendPacketTimeoutACK(8, c);
  Serial.print("Pacote enviado, estado ");
  Serial.println(e, DEC);
  Serial.println(sonic);

  delay(4000);  
}


