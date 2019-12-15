#include <Servo.h>

Servo servoB; // servo da base - Serve baixo - rotação
int posB = 90; // posição inicial 
int sens1 = A0; // LRD1 - CIMA ESQUERDA
int sens2 = A1; // LDR2 - BAIXO DIREITA

Servo servoT; // servo do topo - serve cima - inclinação
int posT = 1; // posição inicial
int sens3 = A2; // LDR3 - CIMA DIREITA
int sens4 = A3; // LDR4 - BAIXO ESQUERDA

int tolerancia = 50; // valor da variável da tolerância

void setup()
{
  Serial.begin(9600);
servoB.attach(8); // Liga o servo da base ao pino 8 do arduino
pinMode(sens1, INPUT);
pinMode(sens2, INPUT);
servoB.write(posB);
servoT.attach(9); // Liga o servo do topo ao pino 9 do arduino
pinMode(sens3, INPUT);
pinMode(sens4, INPUT);
servoT.write(posT);
delay(3000); // 3 segundos de espera evita o ajuste permanente do painel
}

void loop()
{
 
int val1 = analogRead(sens1); // faz a leitura do sensor 1
int val2 = analogRead(sens2); // faz a leitura do sensor 2
int val3 = analogRead(sens3); // faz a leitura do sensor 3
int val4 = analogRead(sens4); // faz a leitura do sensor 4
Serial.print("LuzA0: ");Serial.print(val1);Serial.print(" LuzA1: ");Serial.print(val2);
Serial.print(" LuzA2: ");Serial.print(val3);Serial.print(" LuzA3: ");Serial.println(val4);
//---------------ROTAÇÃO----------------
if((abs(val1 - val2) <= tolerancia) || (abs(val2 - val1) <= tolerancia)) {
//nao faz nada se os valores da leitura estão dentro do limite de tolerancia
} else {
if(val1 > val2) { posB = --posB; }
if(val1 < val2) { posB = ++posB; }
}

if(posB > 180) { posB = 180; } // reset para 180 se for acima
if(posB < 0) { posB = 0; } // reset para 0 se descer abaixo

servoB.write(posB); // escreve a posição do servo motor
Serial.print("ServeB-Rotação: ");Serial.println(posB);
//-----------INCLINAÇÃO-------------------
if((abs(val3 - val4) <= tolerancia) || (abs(val4 - val3) <= tolerancia)) {
//nao faz nada se os valores da leitura estão dentro do limite de tolerancia
} else {
if(val3 > val4) { posT = --posT; }
if(val3 < val4) { posT = ++posT; }
}
if(posT > 80) { posT = 80; } // reset para 80 se for acima
if(posT < 1) { posT = 1; } // reset para 1 se descer abaixo

servoT.write(posT); // escreve a posição do servo motor
Serial.print("ServeB-Inclinação: ");Serial.println(posT);
delay(50);

}
