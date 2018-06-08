#include <Ultrasonic.h>
#include<Servo.h>

Servo motor1;
Servo motor2;
int   sensor=7;
int valorSensor;
Ultrasonic ultrasonic(11,12);

void setup(){
  motor1.attach(5);
  motor2.attach(6);
  pinMode(sensor,INPUT);
  
  Serial.begin(9600);
  }

void loop(){
  
  float cmMsec;
 long microsec = ultrasonic.timing();
 cmMsec = ultrasonic.convert(microsec,Ultrasonic::CM);
 Serial.print(cmMsec);// distancia em cm;
 Serial.println(" cm");
  
  //valorSensor = RCTime(2);
  valorSensor = digitalRead(sensor);// sensor de linha
  
  Serial.println(valorSensor); // imprime sensor	     
  Serial.println(valorSensor);
  if(valorSensor == 0){// se for verdade ataca;
      if(cmMsec < 10){
          motor1.write(80);
          motor2.write(100);
      }
     else{
       motor1.write(100);
      motor2.write(100);
      
     }
   }
    
    
    if( valorSensor == 1){
     motor1.write(100);
      motor2.write(80);
         
   }
}



