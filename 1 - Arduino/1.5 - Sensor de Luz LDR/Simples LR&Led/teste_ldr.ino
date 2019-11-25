// Teste - LDR c/ LED
// Miguel Dias nº6 AC4

int LedPin = 10; // Pin para ligar o led
int sensorPin = A5; // Seleção do pin de entrada do LDR
int sensorValor = 0; // Variavel de armazenamento do LDR inicializada a 0

void setup() {
Serial.begin(9600); // Define a porta serie para comunicação
pinMode(LedPin, OUTPUT); // Define o pin do Led como saída
}
void loop() {
int sensorValor = analogRead(sensorPin); // Lê o valor fornecido pelo LDR
Serial.println(sensorValor); //Imprime os valores provenientes do sensor na ecrã
// Caso o valor lido na porta analógica A5 seja maior do que
// 800, acende o LED
// Ajuste o valor abaixo de acordo com o circuito
if (sensorValor > 800)
{
digitalWrite(LedPin, HIGH);
}
else //Caso contrário, apaga o led
{
digitalWrite(LedPin, LOW);
}
}