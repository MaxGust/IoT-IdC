
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>  

//#include "DHT.h"
// Pin ---- VER
//#define DHTPIN 5
// Use DHT11 sensor
//#define DHTTYPE DHT11
// Initialize DHT sensor
//DHT dht(DHTPIN, DHTTYPE, 15);

const char* host = "dweet.io";

int cont = 0;

void setup() {
  // Start Serial
  Serial.begin(115200);
      //WiFi
  WiFiManager wifiManager;
  wifiManager.autoConnect("AutoConnectAP");
  Serial.println("connected...WiFi.... :)");
  delay(10);
  // Init DHT 
 // dht.begin();
}

void loop() {
 cont +=1;
  Serial.print("Connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  // Reading temperature and humidity
 // int h = dht.readHumidity();
  // Read temperature as Celsius
//  int t = dht.readTemperature();

int t = 2 + cont;
int h = 99 - cont;
  
  // This will send the request to the server
  //POST !
  //MEU
  // https://dweet.io/dweet/for/ESP-12E?Temp=10&Hum=80
  
  client.print(String("GET /dweet/for/ESP-12E?Temp=") + String(t) + "&Hum=" + String(h) + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(10);
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  
  Serial.println();
  Serial.println("closing connection");
  
  // Repeat every 10 seconds
  delay(10000);
 
}
