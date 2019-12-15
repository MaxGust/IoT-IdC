#include <ESP8266WiFi.h>         
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>   
      
//192.168.4.1 

void setup() {
    Serial.begin(115200);
    //WiFi
    WiFiManager wifiManager;
    //Comentar depois de configurar a rede, 
    //serve para fazer o reset anterior e aparecer no SSID 
    wifiManager.resetSettings();
    wifiManager.autoConnect("ESP-Estufa");
    Serial.println("connected...WiFi.... :)");
}

void loop() {  }
