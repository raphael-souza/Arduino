#include <Servo.h>
#include<avr/wdt.h>

int valor_sensor_r=0;
int valor_sensor_l=0;
const int sensor_r=0;
const int sensor_l=1;
Servo motor_r;
Servo motor_l;

void setup() {
   Serial.begin(9600);
   motor_r.attach(12);
   motor_l.attach(13);
}
//comparar valores esatos e resetar!!!!!
void loop() {
  wdt_disable();
  valor_sensor_r= analogRead(sensor_r);
  valor_sensor_l= analogRead(sensor_l);
  valor_sensor_r= map(valor_sensor_r,0,1023,0,180);
  valor_sensor_l= map(valor_sensor_l,0,1023,0,180);//funcao que transforma os bits em graus
  Serial.print("valor do sensor: ");
  Serial.print(valor_sensor_l);
  Serial.print(" - ");
  Serial.println(valor_sensor_r);
  
  if(valor_sensor_l ==127){
    motor_r.write(16);
    motor_l.write(160);
    delay(200);
    wdt_enable(100);
    while(1);
  }
  else if(valor_sensor_l==121){
    motor_r.write(160);
    motor_l.write(16);
    delay(200);
    wdt_enable(100);
    while(1);
  }
  else if(valor_sensor_l==120){
    motor_r.write(16);
    delay(200);
    wdt_enable(100);
    while(1);
  }
  else if(valor_sensor_l==125){
    motor_l.write(160);
    delay(200);
    wdt_enable(100);
    while(1);
  }
  
}
