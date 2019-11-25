#include <ESP8266WiFi.h>         
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         

void setup() {
    Serial.begin(115200);
    //WiFi
    WiFiManager wifiManager;
    wifiManager.autoConnect("AutoConnectAP");
    Serial.println("connected...WiFi.... :)");
}

void loop() {  }
