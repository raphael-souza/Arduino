//////////////////////////////////////
//                                   *
//    TESTE de acionamento de Rel e  *
//    ligar rele saida 12            *
//////////////////////////////////////

int rele = A3;

void setup(){
  pinMode(rele,OUTPUT);
  
}

void loop(){
  
  digitalWrite(rele,HIGH);
  delay(3000);
  digitalWrite(rele,LOW);
  delay(2000);
  
}
