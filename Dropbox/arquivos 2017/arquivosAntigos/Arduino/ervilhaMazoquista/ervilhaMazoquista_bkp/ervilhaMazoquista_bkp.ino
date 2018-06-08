#include <Ultrasonic.h>
#include<Servo.h>

Servo motor1;
Servo motor2;
int   sensor=7;
int valorSensor;
Ultrasonic ultrasonic(12,11);

void setup(){
  motor1.attach(6);
  motor2.attach(5);
  pinMode(sensor,INPUT);
  
  Serial.begin(9600);
  }

void loop(){
  
  float cmMsec;
 long microsec = ultrasonic.timing();
 cmMsec = ultrasonic.convert(microsec,Ultrasonic::CM);
 //Serial.print(cmMsec);
 //Serial.println(" cm");
 
  
  valorSensor = RCTime(2); // sensor de linha ligado na porta digital 2
 Serial.println(valorSensor);	    

  
  if(valorSensor  < 100){
    if(cmMsec < 18 ){
      motor1.write(80);
      motor2.write(100);
      delay(1000);
    }
    else{ 
      motor1.write(100);
      motor2.write(100);
      
    }
    
  }else{
    motor1.write(100);
    motor2.write(80);
    delay(800);
    motor1.write(100);
    motor2.write(100);
    delay(1000);
    
  }
}




long RCTime(int sensorIn){
   long duration = 0;
   pinMode(sensorIn, OUTPUT);     // Make pin OUTPUT
   digitalWrite(sensorIn, HIGH);  // Pin HIGH (discharge capacitor)
   delay(1);                      // Wait 1ms
   pinMode(sensorIn, INPUT);      // Make pin INPUT
   digitalWrite(sensorIn, LOW);   // Turn off internal pullups
   while(digitalRead(sensorIn)){  // Wait for pin to go LOW
      duration++;
   }
   return duration;
}
