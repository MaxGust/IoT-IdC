// EmonLibrary examples openenergymonitor.org, Licence GNU GPL V3
/*
I = P / E
Onde I é a corrente (em Ampéres), P é a potência (em Watts) e E é a tensão (em Volts). 
Aplicando a fórmula em um aparelho cuja potência é de 2200 Watts, 
ligado à rede elétrica de 220V, 
teremos uma corrente de 10A (ampéres).
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

int tensao = 220; //tensão electrica
int potencia;

void setup()
{  
  Serial.begin(9600);
  sensor.current(pin, 20);  
  //valor de calibração com o resistor calculado
  // 2000/33 = 60.606 -> 2000 espirais do secundario e 33 da resistencia no arduino 
  //2000/100 = 20 calibração por causa da resistencia
  //está calibrado Lampada 18W indica 18 e 19W, com 0,09A !!
}

void loop()
{
  double Irms = sensor.calcIrms(1480); //número de amostras 
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