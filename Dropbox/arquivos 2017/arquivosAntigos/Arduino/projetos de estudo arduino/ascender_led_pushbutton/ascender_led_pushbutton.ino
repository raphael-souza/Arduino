//projeto ascender led com pushbutton- 01 robocore

int ledpin = 13;
int botao =2;
int estadobotao= 0;

void setup(){
    pinMode(ledpin,OUTPUT);
    pinMode(botao,INPUT);
}

void loop(){
  estadobotao= digitalRead(botao);
  if(estadobotao== HIGH){
    digitalWrite(ledpin,HIGH);
  }
  else{
    digitalWrite(ledpin, LOW);
  }
}
