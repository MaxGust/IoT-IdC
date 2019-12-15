#include <SPI.h>
#include <Wire.h>
//--------------------------OK---- preparado para ir juntar ao MEGA ----------------
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
//--------FIM Oled--------------
void setup()   {                
  Serial.begin(9600);
  //-------Oled----------
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  //-------FIM Oled-----
}

int cont = 0;
void loop() {
  //-------------------------------
  cont ++; //para teste
  
  if(cont > 50 ){
  //--------Alerta valores fora dos parametros-------
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println("User: A1");
    display.setTextColor(WHITE);
     display.setTextSize(2);
    display.print("SpO2: ");
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.print(cont); //-----SPO2Msg---Variavel do SpO2------
    display.invertDisplay(0);
    display.display();
    delay(1000);
    display.clearDisplay();
    display.invertDisplay(1);
    display.display();
    delay(1000);
    display.clearDisplay();
    //-----------------FIM------------------------
  } else {
    //--------Alerta valores fora dos parametros-------
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println("User: A1");
    display.setTextColor(WHITE);
     display.setTextSize(2);
    display.print("SpO2: ");
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.print(cont); //----SPO2Msg---Variavel do SpO2------
    display.display();
    delay(1000);
    display.clearDisplay();
    //-----------------FIM------------------------
  }


  
  } //Loop
  


