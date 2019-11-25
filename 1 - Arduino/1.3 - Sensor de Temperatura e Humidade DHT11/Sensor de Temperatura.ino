#include "DHT.h"
#define DHTPIN A0
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

//Variaveis
int led = 5; //Led

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW); //Led Desligado
  dht.begin(); //Iniciar o Sensor DHT11
}

void loop() {
  //Mostar os Valores de Humidade do Ar e Temperatura na Consola de 1 em 1 Segundo 
  delay(1000);

  float h = dht.readHumidity(); //Ler a Humidadde do Ar
  float t = dht.readTemperature(); //Ler a Temperatura

  Serial.print(F("Humidade do Ar: "));
  Serial.print(h);
  Serial.print(F("%  Temperatura: "));
  Serial.print(t);
  Serial.println(F("°C "));

  //Se a Temperatura da Estufa for mair ou igual que ...
  if(t >= 28){
    //Ligar Led
    digitalWrite(led, HIGH);
    //Ligar Ventoinha 
  }else{
    //Desligar Led
    digitalWrite(led, LOW);
    //Desligar Ventoinha 
  }

  
}
