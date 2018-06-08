//sonsor IR
boolean desligado = false;

void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  if(desligado == false){
    digitalWrite(13,LOW);
  }
  int sensorValue = digitalRead(2);
  Serial.println(sensorValue,DEC);
  if(sensorValue == 0){
     digitalWrite(13,HIGH);
     desligado = true;
     delay(500);
     digitalWrite(13,LOW);
  }

}
