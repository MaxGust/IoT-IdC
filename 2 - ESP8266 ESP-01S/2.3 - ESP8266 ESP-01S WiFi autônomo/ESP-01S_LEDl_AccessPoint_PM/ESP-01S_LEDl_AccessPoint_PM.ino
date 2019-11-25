/*
 * connect to the ESP8266 AP then
 * use web broswer to go to 192.168.4.1
 * Código adaptado por Pedro Matos
 * Access Point - Ligação directa PC/Mobile -to- ESP-01S
 */
#include <ESP8266WiFi.h>
const char WiFiPassword[] = ""; //para segurança colocar password
const char SSID_My[] = "LED_Esp-01S" ; //Nome da rede (access Point)
WiFiServer server(80);

//Construção da página 
String header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
String html_1 = "<!DOCTYPE html><html><head><meta name='viewport' content='width=device-width, initial-scale=1.0'/><meta charset='utf-8'><style>body {font-size:140%;} #main {display: table; margin: auto;  padding: 0 10px 0 10px; } h2,{text-align:center; } .button { padding:10px 10px 10px 10px; width:100%;  background-color: #4CAF50; font-size: 120%;}</style><title>LED Controle</title></head><body><div id='main'><h2>LED Controle</h2>";
String html_LED = "";
String html_2 = "<form id='F1' action='LEDON'><input class='button' type='submit' value='LED ON' ></form><br>";
String html_3 = "<form id='F2' action='LEDOFF'><input class='button' type='submit' value='LED OFF' ></form><br>";
String html_4 = "<p>Pedro Matos</p>";
String html_5 = "</div></body></html>";
//Receber valores vindo da página
String request = "";
//Pin do Led
int LED_Pin = 2;

void setup() 
{
    pinMode(LED_Pin, OUTPUT); //pin saida de voltagem
    //Cardenciais de autenticação
    boolean conn = WiFi.softAP(SSID_My, WiFiPassword);
    //inicio do servidor
    server.begin();
}
//Ciclo continuo
void loop() 
{
    // Verificar se está connectado
    WiFiClient client = server.available();
    if (!client)  {  return;  }
  
    // Ler a primeira linha do request
    request = client.readStringUntil('\r');
    //Verifica na condição IF o valor vindo da página pelo request
    if       ( request.indexOf("LEDON") > 0 )  { digitalWrite(LED_Pin, HIGH);  }
    else if  ( request.indexOf("LEDOFF") > 0 ) { digitalWrite(LED_Pin, LOW);   }

    // Obter o status do LED e crie a mensagem de status do LED
    if (digitalRead(LED_Pin) == HIGH) { html_LED = "The LED is on<br><br>"; }
    else                              { html_LED = "The LED is off<br><br>"; }

    client.flush();
    //Constroi a página
    client.print( header );
    client.print( html_1 );    
    client.print( html_LED );
    client.print( html_2 );
    client.print( html_3 );
    client.print( html_4 );
    client.print( html_5 );
    
    delay(5); 
}
