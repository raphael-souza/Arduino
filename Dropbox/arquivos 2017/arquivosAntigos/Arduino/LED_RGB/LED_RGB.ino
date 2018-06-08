

int ledvermelho = 8;
int ledverde = 9;
int ledazul = 10;

void setup()  { 
  pinMode(ledvermelho,OUTPUT);
  pinMode(ledverde,OUTPUT);
  pinMode(ledazul,OUTPUT);
  digitalWrite(ledvermelho,HIGH);
  digitalWrite(ledverde,HIGH);
  digitalWrite(ledazul,HIGH);  
} 


void loop()  { 
  //VERMELHA
  digitalWrite(ledvermelho,LOW);
  digitalWrite(ledverde,HIGH);
  digitalWrite(ledazul,HIGH);  
  delay(1000);
  
  //VERDE
  digitalWrite(ledvermelho,HIGH);
  digitalWrite(ledverde,LOW);
  digitalWrite(ledazul,HIGH);  
  delay(1000);  
  
  //AZUL
  digitalWrite(ledvermelho,HIGH);
  digitalWrite(ledverde,HIGH);
  digitalWrite(ledazul,LOW);  
  delay(1000);
  
  //AMARELO 
  digitalWrite(ledvermelho,LOW);
  digitalWrite(ledverde,LOW);
  digitalWrite(ledazul,HIGH);  
  delay(1000);
  
  //ROXO
  digitalWrite(ledvermelho,LOW);
  digitalWrite(ledverde,HIGH);
  digitalWrite(ledazul,LOW);  
  delay(1000);
  
  //turn LED 
  digitalWrite(ledvermelho,HIGH);
  digitalWrite(ledverde,LOW);
  digitalWrite(ledazul,LOW);  
  delay(1000);
  
  //AZUL CEU
  digitalWrite(ledvermelho,LOW);
  digitalWrite(ledverde,LOW);
  digitalWrite(ledazul,LOW);  
  delay(1000);
}




