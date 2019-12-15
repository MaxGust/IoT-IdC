#include "DHT.h"
#define DHTPIN D6
#define DHTTYPE DHT11
// Wifi
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>  


DHT dht(DHTPIN, DHTTYPE);

//Variaveis
int ventoinha = D7; //Ventoinha
int irrigacao = D8; //Rega
float solo;
float h = 0; //Ler a Humidadde do Ar
float t = 0;//Ler a Temperatura

const char* host = "dweet.io";

void setup() {
  Serial.begin(9600);
  
  //Ventoinha
  pinMode(ventoinha, OUTPUT);
  digitalWrite(ventoinha, LOW); //Ventoinha Desligado
  dht.begin(); //Iniciar o Sensor DHT11

  //Rega
  pinMode(irrigacao, OUTPUT);
  digitalWrite(irrigacao, LOW);
  
  //WiFi
  WiFiManager wifiManager;
  wifiManager.autoConnect("AutoConnectAP");
  Serial.println("connected...WiFi.... :)");
  delay(10);
  //Init DHT 
  //dht.begin();
}
void loop() {
  
  //Mostar os Valores de Humidade do Ar e Temperatura na Consola de 10 em 10 Segundo 
  delay(2000);
  h = dht.readHumidity(); //Ler a Humidadde do Ar
  t = dht.readTemperature(); //Ler a Temperatura
  
  Serial.print(F("Humidade do Ar: "));
  Serial.print(h);
  Serial.print(F("%  Temperatura: "));
  Serial.print(t);
  Serial.println(F("°C "));

  //Se a Temperatura da Estufa for maior ou igual que ...
  if(t >= 25){
    //Ligar Ventoinha 
    digitalWrite(ventoinha, HIGH);
    
  }else{
    //Desligar Ventoinha 
    digitalWrite(ventoinha, LOW);
    
  }
  delay(1000);
  
  solo = analogRead(0);
  Serial.print("A Humidade do Solo é:");
  Serial.println(solo);
  
  
  //Se a Humidade do Solo for menor ou igual que ...
  if(solo <= 400){
    //Ligar Irrigação
    digitalWrite(irrigacao, HIGH);
    
  }else{
    //Desligar Irrigação
    digitalWrite(irrigacao, LOW);
  }
  

  //Wifi
  Serial.print("Connecting to ");
  Serial.println(host);
  // Use WiFiClient class to create TCP connections
   WiFiClient client;
   const int httpPort = 80;
    if (!client.connect(host, httpPort)) {
      Serial.println("connection failed");
      return;
  }

  client.print(String("GET /dweet/for/ESP-12E?Temp=") + String(t) + "&Hum=" + String(h) + "&Solo=" + String(solo) + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(10);

    while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  
  Serial.println();
  Serial.println("closing connection");
  
  // Repeat every 10 seconds
  delay(10000);
}
