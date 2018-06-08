//projeto ascender 3 leds pushbuttom;

int ledpin1= 13;
int ledpin2= 8;
int ledpin3= 11;
int botao1= 2;
int botao2= 3;
int botao3= 4;
int estadobotao1=0;
int estadobotao2=0;
int estadobotao3=0;

void setup() {
  pinMode(ledpin1,OUTPUT);
  pinMode(botao1,INPUT);
  pinMode(ledpin2,OUTPUT);
  pinMode(botao2,INPUT);
  pinMode(ledpin3,OUTPUT);
  pinMode(botao3,INPUT);
}

void loop() {
  estadobotao1= digitalRead(botao1);
  estadobotao2= digitalRead(botao2);
  estadobotao3= digitalRead(botao3);
  if(estadobotao1 == HIGH){
    digitalWrite(ledpin1,HIGH);
  }
  else{
    digitalWrite(ledpin1,LOW);
  }
  if(estadobotao2 == HIGH){
    digitalWrite(ledpin2,HIGH);
  }
  else{
    digitalWrite(ledpin2,LOW);
  }
  if(estadobotao3 == HIGH){
    digitalWrite(ledpin3,HIGH);
  }
  else{
    digitalWrite(ledpin3,LOW);
  }
}
  
