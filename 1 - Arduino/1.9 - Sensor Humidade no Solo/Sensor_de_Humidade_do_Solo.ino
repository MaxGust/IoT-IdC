/*
  # Version    : 1.0
  # Connect the sensor to the A0(Analog 0) pin on the Arduino board
  
  # the sensor value description
  # 0  ~300     dry soil
  # 300~700     humid soil
  # 700~950     in water
*/
float solo;
int irrigacao = 6;

void setup(){
  Serial.begin(9600);
  pinMode(irrigacao, OUTPUT);
  digitalWrite(irrigacao, LOW);
}

void loop(){
  
  delay(2000);
  solo = analogRead(0);
  Serial.print("A Humidade do Solo é:");
  Serial.println(analogRead(0));
  Serial.println(solo);
  
  
  //Se a Humidade do Solo for maior ou igual que ...
  if(solo >= 400){
    //Ligar Irrigação
    digitalWrite(irrigacao, HIGH);
    
  }else{
    //Desligar Irrigação
    digitalWrite(irrigacao, LOW);
  }
}
