#include <Ultrasonic.h>
#include<Servo.h>

Servo motor1;
Servo motor2;
Ultrasonic ultrasonic(12,11);

void setup(){
  motor1.attach(5);
  motor2.attach(6);

  Serial.begin(9600);
  }

void loop(){
 float cmMsec;
 long microsec = ultrasonic.timing();
 cmMsec = ultrasonic.convert(microsec,Ultrasonic::CM);
 Serial.print(cmMsec);
 Serial.println(" cm");
 if(cmMsec <15){
  motor1.write(1);
  motor2.write(180);
 }
 else{
   motor1.write(180);
  motor2.write(1);
 }
  delay(300);
  
}
