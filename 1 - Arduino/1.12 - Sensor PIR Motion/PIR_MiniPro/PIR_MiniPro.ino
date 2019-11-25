/*  
    Arduino with PIR motion sensor
    For complete project details, visit: http://RandomNerdTutorials.com/pirsensor
    Modified by Rui Santos based on PIR sensor by Limor Fried
*/
 
int rede = 5;                // the pin that the LED is atteched to
int led = 9;
int sensor = 3;              // the pin that the sen
int val = 0;                 // variable to store the sensor status (value)

void setup() {
  pinMode(rede, OUTPUT);      // initalize LED as an output
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);    // initialize sensor as an input
}

void loop(){

  val = digitalRead(sensor);   // read sensor value
  
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(rede, LOW);   // turn LED ON
   digitalWrite(led, HIGH);
    delay(100);                // delay 100 milliseconds 
  
  } 
  else {
    digitalWrite(rede, HIGH); // turn LED OFF
    digitalWrite(led, LOW);
      delay(1000);             // delay 200 milliseconds 
      
  }
    delay(1000);
}
