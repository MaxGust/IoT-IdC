/*
Title Comments 1
Title Comment 2 
*/
#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>

/*
Additional Comment If Required
*/

//  Variables
const int PulseSensorPurplePin = 0;        // Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0
const int LED13 = 13;                     //  The on-board Arduion LED
int Threshold = 550;            // Determine which Signal to "count as a beat", and which to ingore.

/*
   All the PulseSensor Playground functions.
*/
PulseSensorPlayground pulseSensor;  // Creates an instance of the PulseSensorPlayground Object called "pulseSensor"

void setup() {

  Serial.begin(9600);  // For Serial Monitor

  // Configure the PulseSensor manager.
  pulseSensor.analogInput(PulseSensorPurplePin);
  pulseSensor.blinkOnPulse(LED13);
  pulseSensor.setThreshold(Threshold);

   if (pulseSensor.begin()) {
    Serial.println("We created a pulseSensor Object !");
  }
}


void loop() {
  delay(20);  

// int myInt = pulseSensor.getBeatsPerMinute

if (pulseSensor.sawStartOfBeat()) {
 Serial.println("♥  A HeartBeat Happened ! ");
 Serial.print("BPM: ");
 Serial.println(pulseSensor.getBeatsPerMinute());

}


}

  
