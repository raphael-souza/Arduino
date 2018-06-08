#include <Servo.h>
//sensor a 3v 
Servo motor_l;//amarelo
Servo motor_r;//azul
const int sensor=0;
int valor_sensor;
int buzzer= 11;

void setup() {
 Serial.begin(9600);
 motor_l.attach(12);
 motor_r.attach(13);
 pinMode(buzzer,OUTPUT);
}

void loop() {
    valor_sensor= analogRead(sensor);
    Serial.print("valor do sensor: ");
    Serial.println(valor_sensor);
    digitalWrite(buzzer,HIGH);
      delay(500);
      digitalWrite(buzzer,LOW);
    if(valor_sensor >100){
      motor_l.write(180);
      motor_r.write(0);
      delay(1000);
    }
    else{
      motor_l.write(0);
      delay(3000);
      motor_r.write(180);
      delay(900);
      
      
  }
  }
