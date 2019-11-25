int led1v = 7;
int led1a = 6;
int led1vo = 5;
int led2v = 4;
int led2a = 3;
int led2vo = 2;

void setup()
{
  //defenir tipo pinOut
  pinMode(led1v, OUTPUT);
  pinMode(led1a, OUTPUT);
  pinMode(led1vo, OUTPUT);
  pinMode(led2v, OUTPUT);
  pinMode(led2a, OUTPUT);
  pinMode(led2vo, OUTPUT);
  
  //led estão todos OFF
  digitalWrite(led1v, LOW);
  digitalWrite(led1a, LOW);
  digitalWrite(led1vo, LOW);
  digitalWrite(led2v, LOW);
  digitalWrite(led2a, LOW);
  digitalWrite(led2vo, LOW);
  
}

void loop()
{
  //SEMAFRO 
  // Verde 1 ON e Vermelho 2 ON
  digitalWrite(led1v, HIGH); //ON
  digitalWrite(led2vo, HIGH);
  delay(2000);
  // Verde 1 OFF e Amarelo 1 ON
  digitalWrite (led1v, LOW); //OFF
  digitalWrite (led1a, HIGH);
  delay(2000);
  // Amarelo 1 OFF e vermelho 1 ON
  digitalWrite (led1a, LOW);
  digitalWrite (led1vo, HIGH);
  delay(1000);
  // Vermelho 2 OFF e Verde 2 ON
  digitalWrite (led2vo, LOW);
  digitalWrite (led2v, HIGH); //verde
  delay(2000);
  // ---- amarelo 2 ON verde 2 OFF
  digitalWrite (led2a, HIGH);
  digitalWrite (led2v, LOW);
  delay(2000);
  digitalWrite(led2a, LOW);
  digitalWrite(led1vo, LOW);  
}