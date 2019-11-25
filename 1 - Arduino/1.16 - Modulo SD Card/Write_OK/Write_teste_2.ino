/*
  SD card read/write

 This example shows how to read and write data to and from an SD card file
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)

 created   Nov 2010
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */

#include <SPI.h>
#include <SD.h>

File myFile;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial.print(F("Initializing SD card..."));
  if (!SD.begin(4)) {
    Serial.println(F("initialization failed! OFF"));
    while (1);
  }
  Serial.println(F("initialization ON."));

myFile = SD.open("test.txt", FILE_WRITE);
  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print(F("-------INICIO----3---"));
    myFile.println("-------INICIO---3----");
myFile.close();
    Serial.println("done.");
    } else {
      Serial.println(F("error opening test.txt"));
    }

}
int x = 0;
void loop() {
  x +=1;
myFile = SD.open("test.txt", FILE_WRITE);
  if (myFile) {
      myFile.println(x);
 myFile.close();
      Serial.println(x);
    } else {
      // if the file didn't open, print an error:
      Serial.println("error opening test.txt");
    }
    delay(1000);
}


