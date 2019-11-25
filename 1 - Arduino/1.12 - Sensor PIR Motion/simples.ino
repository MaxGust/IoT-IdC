// (HC-SR501) PIR Sensor

int PIRpin = 8; // PIR connected pin
int value;

void setup() {
Serial.begin(9600);
pinMode(2, OUTPUT); //For Led
}

void loop() {
value = digitalRead(PIRpin); //Read PIR state

if (value == LOW) {
Serial.println("No Movement");
digitalWrite (2, LOW);
}
else {
Serial.println("Movement!");
digitalWrite (2, HIGH);

}

delay(100); //Wait
}