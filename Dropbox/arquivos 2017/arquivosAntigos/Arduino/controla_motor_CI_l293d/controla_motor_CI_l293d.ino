#include <IRremote.h>
#include <IRremoteInt.h>

//projeto CI ponte H l 293d Raphael Souza

int pinovelocidade = 2; //pino 1 enable1
int entrada1 = 12;//pino 2 input1
int entrada2 = 11;//pino 7 input2
int pinovelocidade2 = 8; //pino 9 enable2
int entrada3 = 9; //pino 15 input4
int entrada4 = 10; //pino 10 input 3
int RECV_PIN = 14;// pino para receber valores IR
IRrecv irrecv (RECV_PIN); // contrlole remoto
decode_results resultados; //IR
boolean sinal =  false;
int led_G = 4;
int led_Y = 5;
int led_R = 6;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); //inicia receptor IR
  pinMode(pinovelocidade,OUTPUT);
  pinMode(entrada1,OUTPUT);
  pinMode(entrada2,OUTPUT);
  pinMode(pinovelocidade2,OUTPUT);
  pinMode(entrada3,OUTPUT);
  pinMode(entrada4,OUTPUT);
  pinMode(led_G,INPUT);
  pinMode(led_Y,INPUT);
  pinMode(led_R,INPUT);  
}

void loop() {
  calcula_tensao(); 
  
  if(sinal == false){
      parar_motor();
  }
  if(irrecv.decode(&resultados)){
    Serial.println(resultados.value,DEC);
    //define velocidade
    int velocidade = 500;
    analogWrite(pinovelocidade,velocidade);
    analogWrite(pinovelocidade2,velocidade);
    //aciona Motor
    switch(resultados.value){
       case 16754775:
       
        para_tras();
        break;
      case 16736925:
        
        para_frente();
        break;
      case 16720605:
       
        para_direita();
        break;
      case 16761405:
       
        para_esquerda();
        break;
      case 16712445:

        parar_motor();
        break;
  }
  irrecv.resume();// Recebe o próximo valor IR
  }
}

void parar_motor(){
    digitalWrite(entrada1,LOW);
    digitalWrite(entrada2,LOW);
    digitalWrite(entrada3,LOW);
    digitalWrite(entrada4,LOW);
    delay(2000);
}

void para_frente(){
  digitalWrite(entrada1,HIGH);
  digitalWrite(entrada2,LOW);
  digitalWrite(entrada3,HIGH);
  digitalWrite(entrada4,LOW);
  delay(4000);
}

void para_tras(){
  digitalWrite(entrada1,LOW);
  digitalWrite(entrada2,HIGH);
  digitalWrite(entrada3,LOW);
  digitalWrite(entrada4,HIGH);
  delay(4000);
}

void para_esquerda(){
  digitalWrite(entrada1,HIGH);
  digitalWrite(entrada2,LOW);
  digitalWrite(entrada3,LOW);
  digitalWrite(entrada4,HIGH);
  delay(1800);
}

void para_direita(){
  digitalWrite(entrada1,LOW);
  digitalWrite(entrada2,HIGH);
  digitalWrite(entrada3,HIGH);
  digitalWrite(entrada4,LOW);
  delay(1800);
}

void calcula_tensao(){
   const int pinosensor=A1;
   float valorsensor=0;
   
   valorsensor= analogRead(pinosensor);
   valorsensor = ((valorsensor / 1024)* 3.7)*2;
   //transforma os bits recebidos na tensão real.
   Serial.print("valor do sensor = ");
   Serial.println(valorsensor);
   if(valorsensor >= 5.60){
     digitalWrite(led_G, HIGH);
     digitalWrite(led_R,LOW);
     digitalWrite(led_Y,LOW);
   }
   if(valorsensor < 5.60 && valorsensor >=4.75){
       digitalWrite(led_G,LOW);
       delay(200);
       digitalWrite(led_G,HIGH);
       delay(300);
       digitalWrite(led_G,LOW);
       digitalWrite(led_Y,HIGH);
   }
   if(valorsensor <4.75){
       digitalWrite(led_G,LOW);
       
       digitalWrite(led_Y,LOW);
       delay(200);
       digitalWrite(led_Y,HIGH);
       delay(300);
       digitalWrite(led_Y,LOW);
       digitalWrite(led_R,HIGH);
   }
   
   valorsensor=0;
   
}
