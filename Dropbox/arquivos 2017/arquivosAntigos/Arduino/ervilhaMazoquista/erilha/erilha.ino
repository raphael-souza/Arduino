#include <Ultrasonic.h>
#include<Servo.h>

Servo motor1;
Servo motor2;
int   sensor=7;
int valorSensor;
Ultrasonic ultrasonic(11,12);
float cmMsec;
long microsec;

void setup(){
  motor1.attach(5);
  motor2.attach(6);
  pinMode(sensor,INPUT);
  
  Serial.begin(9600);
  }

void loop(){
  valorSensor = digitalRead(sensor);
  microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec,Ultrasonic::CM);
  
  Serial.println(valorSensor);
  if(valorSensor==HIGH){
    motor1.write(80);
    motor2.write(100);
    
  }else{
    motor1.write(80);
    motor2.write(80);
    delay(200);
  }
}
