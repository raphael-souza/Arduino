const int pinosensor=0;
int valorsensor=0;

void setup() {
   Serial.begin(9600);
}

void loop() {
 valorsensor= analogRead(pinosensor);
 Serial.print("valor do sensor = ");
 Serial.println(valorsensor);
 delay(400);
 valorsensor=0;
}
