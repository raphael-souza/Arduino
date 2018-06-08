const int ldr=1;
int led=2;

int valorldr=0;

void setup(){
  pinMode(led,OUTPUT);
}

void loop(){
  valorldr= analogRead(ldr);
  if(valorldr>0){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
}

   
