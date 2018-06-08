
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
  
   r3.write(115);
   l3.write(75);
 
//=============================== 
  inclinaL();
  for(i=0;i<15;i++){
    r3.write(115+i);
    l3.write(75+i);
    //r2.write(90+i);
    delay(100);
  }
  
  inclinaR();
  for(i=0;i<15;i++){
    r3.write(130-i);
    l3.write(90-i);
   // r2.write(105-i);
    delay(100);
  }
//==============================================
 
 for(i=0;i<15;i++){
    r3.write(115-i);
    l3.write(75-i);
    //l2.write(90+i);
    delay(100);
  }
inclinaL();
  for(i=0;i<15;i++){
    r3.write(100+i);
    l3.write(60+i);
    //l2.write(105+i);
    delay(100);
  }
 
 
   delay(1000);
   
} 
//============================================================================================================================    
void alinha(){
  int grau = 90;
   r1.write(grau);
   l1.write(grau);
   r2.write(grau);
   l2.write(grau);
   r3.write(grau);
   l3.write(grau);
   
    
}

void inclinaL(){
  int i;
  for(i=0;i<30;i++){//inclina bipede para esquerda
    l1.write(90+i);
    r1.write(60+i);
    delay(100);
    
  }
  delay(500);
}

void inclinaR(){// inclina bipede para direita
   int i;
   for(i=0;i<30;i++){
    l1.write(120-i);
    r1.write(90-i);
    delay(100);
    
  }
  delay(500);

}
