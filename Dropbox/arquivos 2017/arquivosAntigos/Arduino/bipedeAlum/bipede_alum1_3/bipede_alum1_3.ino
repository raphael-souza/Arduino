
//bipede alum
#include <Servo.h> 


Servo r1, r2;
Servo l1, l2;
int vel1 = 40;
int vel2= 200;


void setup() 
{ 
  r1.attach(3);
  r2.attach(4);
  
  l1.attach(8);
  l2.attach(9);
   
} 

void loop() 
{ 
  passo0();
  enclina0();
  delay(vel2);
  
  enclinaR();
  delay(vel2);
  passo1();
  enclinaL();
  delay(vel2);
  passo2();
  delay(vel2);

} 

//============================================================================================================================    

void alinha(){
  int grau = 90;
   r1.write(grau);
   l1.write(grau);
   r2.write(grau);
   l2.write(grau);
 
    
}
void enclina0(){
  int i;
  if(i<70){
    return;
  }
  else{
    for(i=0;i<=25;i++){
      r1.write(90-i);
      l1.write(90-i);
      delay(vel1);
    }
  }
}
  
void enclinaL(){ // inclina para esquerda
  int i;
   for(i=0;i<55;i++){
    l1.write(65+i);
    r1.write(65+i);
    delay(vel1);
    
  }
 
}

void enclinaR(){
   int i;
   for(i=0;i<55;i++){
    l1.write(120-i);
    r1.write(120-i);
    delay(vel1);
    
  }
  
}

void passo0(){
  int i;
  
  for(i=0;i<=10;i++){
    r2.write(80-i);
    l2.write(100-i);
    delay(vel1);
  }
}

void passo1(){
    int i;
  
  for(i=0;i<=20;i++){
    r2.write(70+i);
    l2.write(90+i);
    delay(vel1);
  }
}
  
void passo2(){
  int i;
  
  for(i=0;i<=10;i++){
    r2.write(90-i);
    l2.write(110-i);
    delay(vel1);
  }
}

