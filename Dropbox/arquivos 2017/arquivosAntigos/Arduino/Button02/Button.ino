


const int btn1 = 8;     // the number of the pushbutton pin
const int led1 = 5;      // the number of the LED pin
const int btn2 = 9;     // the number of the pushbutton pin
const int led2 = 6;
const int btn3 = 10;     // the number of the pushbutton pin
const int led3 =  7;
const int led0 = 11;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

int T = 0;

void setup() {
  
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led0,OUTPUT);
  // botao
  pinMode(btn1,INPUT);
  pinMode(btn2,INPUT);
  pinMode(btn3,INPUT);  
  
}

void loop(){
  
  buttonState1 = digitalRead(btn1);
  buttonState2 = digitalRead(btn2);
  buttonState3 = digitalRead(btn3);
  if(buttonState1 == HIGH || buttonState2 == HIGH || buttonState3 == HIGH){
    digitalWrite(led0,HIGH);
  }
  else{
    digitalWrite(led0,LOW);
  }
  
  if (buttonState1 == HIGH) {   
       T = 100;  
       digitalWrite(led1, HIGH);  
  } 
  else {
    digitalWrite(led1, LOW); 
  }
 
  if (buttonState2 == HIGH) {  
       T = 300;   
       digitalWrite(led2, HIGH);  
  } 
  else {
    digitalWrite(led2, LOW); 
  }
  
     if (buttonState3 == HIGH) {  
       T = 500;   
       digitalWrite(led3, HIGH);  
  } 
  else {
    digitalWrite(led3, LOW); 
  }
}
