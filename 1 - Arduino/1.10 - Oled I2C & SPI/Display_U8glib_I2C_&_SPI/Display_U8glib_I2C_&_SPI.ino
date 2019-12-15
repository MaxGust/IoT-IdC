#include <SPI.h>
//----------OLed ---------------
#include "U8glib.h"
//..........mudar I2C para SPI..............................
//U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);
U8GLIB_SSD1306_128X64 u8g(10, 9, 12, 11, 13);   // SW SPI Com: SCK = 10, MOSI = 9, CS = 12, A0 = 11, RST = 13
//---- fontes no ficheiro u8g.h na pasta U8glib/src/clib
//...................... ÁGUA ........................
void agua(void) {
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr( 0, 20, "Proxima:");
  u8g.setPrintPos(62, 20);
  u8g.print(proxima);
//...........................
  u8g.setFont(u8g_font_gdb14);
  u8g.drawStr( 0, 45, "ON:");
  u8g.setPrintPos(40, 45);
  u8g.setFont(u8g_font_gdb14);
  u8g.print(estacao);
  //..........
  u8g.setFont(u8g_font_unifont);
  u8g.setPrintPos(40, 60); 
  u8g.print(desc);
}
//.................. INICIO ........................
void myPM(void) {  
  u8g.setFont(u8g_font_gdb14);
  u8g.drawStr( 0, 20, "Pedro");
  u8g.setFont(u8g_font_osb18);
  u8g.drawStr( 20, 45, "MATOS");
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr( 60, 60, "2019");  
}

void setup() {
   //--------DISPLAY-------------------
  // assign default color value
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }
  //---------------------------------
    u8g.firstPage();
  do {
    myPM();
  } while( u8g.nextPage() );
  delay(5000);
  //--------------------------------
  //-------FIM Oled-----
}
// 12 minutos é 700 segundos
// 5 MINUTOS 300 segundos

void loop() {
/*
 *    FRENTE
 */
//----------------------
        u8g.firstPage();
      do {
        agua();
      } while( u8g.nextPage());
//---------------------------------------

}



