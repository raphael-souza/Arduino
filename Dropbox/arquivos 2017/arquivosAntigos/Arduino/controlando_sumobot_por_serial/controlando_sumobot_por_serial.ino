#include <Servo.h>
#include <avr/wdt.h>

Servo motor_l;
Servo motor_r;
const int motor1=12;
const int motor2=13;

void setup() {
  Serial.begin(9600);
  motor_l.attach(12);
  motor_r.attach(13);
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  
}

void loop(){
  wdt_disable();//desabilita
  char direcao=0;
  Serial.println("recebendo dados");
  delay(200);
  if(Serial.available()){
    direcao= Serial.read();
    switch(direcao){
      case('8'):
        motor_l.write(180);
        motor_r.write(0);
        break;
      case('5'):
        motor_l.write(0);
        motor_r.write(180);
        break;
      case ('4'):
        motor_l.write(180);
        break;
      case ('6'):
        motor_r.write(0);
        break;
      case '0':
        wdt_enable(1);
        while(1);
        break;
    }
     
    }
}
      
      
