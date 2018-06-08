const int pinsensor = 0;
float valorsensor=0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  valorsensor= analogRead(pinsensor);
  Serial.print("valor do sensor temperatura: ");
  Serial.println(valorsensor);
  delay(500);
}
