#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif
//---------sensor de Temperatura e Humidade
#include "dht.h"
dht DHT; 
#define DHT11_PIN 7
//----botão------
int bot = 0;
#define bot1 6
//--------------
//---Potenciometro---
const int pinoPOT = A5;
float temp = 37.6;
float humi = 50;
//-------------------
void setup()   {                
  Serial.begin(9600);
  pinMode(bot1, INPUT_PULLUP);
  pinMode(pinoPOT, INPUT);
  display.begin(SSD1306_SWITCHCAPVCC);
  display.display();
  delay(2000);
  display.clearDisplay();

  // text display tests --------- EXEMPLO---------
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Chocadeira");
  
  //display.setTextColor(BLACK, WHITE); // 'inverted' text
  //display.println(3.141592);
  
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.println("PedroMatos");
  display.display();
  delay(2000);
  display.clearDisplay();

}


void loop() {
  //Botão para alterar apresentação no munitor
  //para regular temperatura com potenciometro
bot = digitalRead(bot1); 
//Ler o sensor temp e hum
 int chk = DHT.read11(DHT11_PIN);
//Potenciometro regolar temperatura
float valor = analogRead(pinoPOT);
//Serial.println(valor);
if (valor > 500 & valor < 1023){  
  temp = temp + 0.1;
  humi = humi - 2.25; 
} 
else if (valor < 500 & valor > 100) {
  temp = temp - 0.1;
  humi = humi + 2.25;
}
 Serial.println(temp);
//------Display-------
 if (bot < 1){
//Display
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Temp:");
  display.println(temp);
  display.print(" ");
  display.print("Hum");
  display.println(humi);
  display.display();
  delay(2000);            //depois alterar paragens
  display.clearDisplay();
 } 
 else {
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Temp:");
  display.print(DHT.temperature); 
  display.print(" ");
  display.print("Hum:");
  display.println(DHT.humidity);
  display.display();
  delay(2000);        //depois alterar paragens
  display.clearDisplay();
 }
 //--------- Fazer a condição da temperatura escolhida com a do sensor----
 // Temp 37.4 a 37.8 nos 18 dias
 // Temp 36.8 no 19 a 21 dias pintos
 // 21 dias = 504 horas
 // DHT.temperature detectada estiver abaixo 0.2 (-) da escolhida ligar rele
 //DHT.temperatura detectada estiver 0.2 (+) acima da escolhida desligar rele
 //--------
 // DHT.humidity deve estar no intervalo 50 a 60% de humidadde
 // Baixar a temperatura e aumentar a humidade Ex: tem 36.8º & humi 70% PINTOS
  //PINTOS até 18 dias a 50% a 19 a 21 a 70% 
}

