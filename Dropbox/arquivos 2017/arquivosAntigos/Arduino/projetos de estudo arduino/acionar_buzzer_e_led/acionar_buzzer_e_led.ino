int b= 2;
int botao= 3;
int led= 8;

void setup() {
  pinMode(b,OUTPUT);
  pinMode(botao,INPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  int estado_botao=0;
  estado_botao=digitalRead(botao);
  if(estado_botao==HIGH){
    digitalWrite(b,LOW);
  }
  else{
    digitalWrite(b,HIGH);
    digitalWrite(led,HIGH);
    delay(100);
    digitalWrite(b,LOW);
    digitalWrite(led,LOW);
    delay(1000);
  }   
}
