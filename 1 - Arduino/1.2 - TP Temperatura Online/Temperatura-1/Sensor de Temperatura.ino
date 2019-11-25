//Programa sensor de temperatura
//$incluid <TMP36>

float tmp = 0; //Receber os valores do sensor

//PinOut
int PinTMP= A0; //Pin sensor
int ledvo = 9; //Led vermelho
int ledv = 7; //Led verde

void setup()
{
  Serial.begin(9600); //Iniciar comunicação PC-Placa
  pinMode(ledvo, OUTPUT); // Pin saída led VermelhO
  pinMode(ledv, OUTPUT); //Pin saída led Verde
  pinMode(PinTMP, INPUT);  //Pin entrada de valores do sensor
  digitalWrite(ledv, LOW);
  digitalWrite(ledvo, LOW);
}

void loop()
{
  //Ler o valor do sensor
  tmp = analogRead(PinTMP);
  float volt = (tmp/1024.0)*5.0;
  float tempC = (volt - .5)*100;
  Serial.print(tempC);
  Serial.println("*C");
  delay(1000);
  
  //Vermelho += 40
  if(tempC >= 40){
    digitalWrite(ledv, LOW);
    digitalWrite(ledvo, HIGH);
  }else{
    digitalWrite(ledvo, LOW);
    digitalWrite(ledv, HIGH);
  }
}