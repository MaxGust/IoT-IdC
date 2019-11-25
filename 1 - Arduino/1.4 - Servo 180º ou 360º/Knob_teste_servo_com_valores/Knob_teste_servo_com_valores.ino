/*
Posição do serve com valores fixos
*/
#include <Servo.h>

Servo myservo;  

int val;    

void setup() {
  myservo.attach(9); 
}

void loop() {
  val = 0; 
  val = map(val, 0, 1023, 0, 180);    
  myservo.write(val);                 
  delay(3000);                           
 val = 50;
 delay(3000);
 myservo.write(val); 
 delay(3000);
  val = 100;
 delay(3000);
 myservo.write(val); 
delay(3000);
  val = 110;
 delay(3000);
 myservo.write(val); 
delay(3000);
  val = 150;
 delay(3000);
 myservo.write(val); 
delay(3000);
  val = 180;
 delay(3000);
 myservo.write(val); 
delay(3000);
}
