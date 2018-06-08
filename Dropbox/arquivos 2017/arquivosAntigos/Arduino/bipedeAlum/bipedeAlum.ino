
//bipede alum
#include <Servo.h> 
#define V1 120
#define V2 1000 

Servo r1, r2, r3;
Servo l1, l2, l3;
 
  
int grau;

void setup() 
{ 
  r1.attach(3);
  r2.attach(4);
  r3.attach(5);
  l1.attach(8);
  l2.attach(9);
  l3.attach(10);
  
} 

void loop() 
{ 
  int i = 0;
  
  for(i=0;i<15;i++){
   r3.write(90+i);
   l3.write(90+i);
   
   r1.write(90);
   l1.write(105);
   
  
   r2.write(85);
   l2.write(95);
   delay(V1);
  }
  
  for(i=0;i<15;i++){
   r3.write(105-i);
   l3.write(105-i);
  
   delay(V1);
  }
  //======================
  for(i=0;i<15;i++){
   r3.write(90-i);
   l3.write(90-i);
   
   r1.write(75);
   l1.write(95);
   
   r2.write(90);
   l2.write(85);
  
   delay(V1);
  }
  for(i=0;i<15;i++){
   r3.write(75+i);
   l3.write(75+i);
    
   delay(V1);
  }
  
  
} 
    
void alinha(){
  int grau = 90;
   r1.write(grau);
   l1.write(grau);
   r2.write(grau);
   l2.write(grau);
   r3.write(grau);
   l3.write(grau);
   
    
}

