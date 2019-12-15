// EmonLibrary examples openenergymonitor.org, Licence GNU GPL V3
/*
I = P / E
Onde I � a corrente (em Amp�res), P � a pot�ncia (em Watts) e E � a tens�o (em Volts). 
Aplicando a f�rmula em um aparelho cuja pot�ncia � de 2200 Watts, 
ligado � rede el�trica de 220V, 
teremos uma corrente de 10A (amp�res).
A = W / V
W = V * A
Lampada 100W tem 0,45A com 220voltos
30A
30*1.414 = 42,42A
42,42*2000 = 0,02121A
2,5v/0,02121A = 117 Ohm --> resistencia entre fios do sensor
100 Ohm Castanho | preto | vermelho
*/
#include "EmonLib.h"             // Include Emon Library
EnergyMonitor sensor;             // Create an instance
int pin = A0;

int tensao = 220; //tens�o electrica
int potencia;

void setup()
{  
  Serial.begin(9600);
  sensor.current(pin, 20);  
  //valor de calibra��o com o resistor calculado
  // 2000/33 = 60.606 -> 2000 espirais do secundario e 33 da resistencia no arduino 
  //2000/100 = 20 calibra��o por causa da resistencia
  //est� calibrado Lampada 18W indica 18 e 19W, com 0,09A !!
}

void loop()
{
  double Irms = sensor.calcIrms(1480); //n�mero de amostras 
  potencia = Irms * tensao;

Serial.print("Corrente: ");
Serial.print(Irms);
Serial.println(" A");

Serial.print("Potencia: ");
Serial.print(potencia);
Serial.println(" W");
Serial.println("-----------------------");
delay(3000);
}