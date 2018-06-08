#include <LiquidCrystal.h>
#include <SD.h>
#include "Wire.h"
#define DS3231_I2C_ADDRESS 0x68
#define TEMPO_CATRACA 3000 // tempo que a catraca fica liberada

// Convert normal decimal numbers to binary coded decimal
byte decToBcd(byte val)
{
  return( (val/10*16) + (val%10) );
}
// Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val)
{
  return( (val/16*10) + (val%16) );
}

File ArquivoTxt;

// tela lcd

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// Botoes 

const int btn_r = 9;
const int btn_g = 8;
const int btn_y = A2;
const int btn_b = A1;
const int buzzer = A0;
const int rele = A3;

int estado_btn_r = 0;
int estado_btn_g = 0;
int estado_btn_y = 0;
int estado_btn_b = 0;
int estado_rele = 0;
//data/hora

void setup()
{
  lcd.begin(16, 2); // Iniciando o objeto "lcd"
  Wire.begin();
  pinMode(btn_r,INPUT);
  pinMode(btn_g,INPUT);
  pinMode(btn_y,INPUT);
  pinMode(btn_b,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(rele,OUTPUT);
  
  Serial.begin(9600);
  SD.begin(10); // saida responsavel pelo cartao sd.
  
 /* ======= ATUALIZAR DATA/HORA/DIA/ANO ====== 
 essa linha deve ser descomentada,atualizada, compilada, comenta e compila
 novamente.
          seg/min/hora-dia_da_semana-dd/mm-aa
*/  

  //setDS3231time(30,45,17,7,26,9,15);

}

void setDS3231time(byte second, byte minute, byte hour, byte dayOfWeek, byte
dayOfMonth, byte month, byte year)
{
  // sets time and date data to DS3231
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set next input to start at the seconds register
  Wire.write(decToBcd(second)); // set seconds
  Wire.write(decToBcd(minute)); // set minutes
  Wire.write(decToBcd(hour)); // set hours
  Wire.write(decToBcd(dayOfWeek)); // set day of week (1=Sunday, 7=Saturday)
  Wire.write(decToBcd(dayOfMonth)); // set date (1 to 31)
  Wire.write(decToBcd(month)); // set month
  Wire.write(decToBcd(year)); // set year (0 to 99)
  Wire.endTransmission();
}
void readDS3231time(byte *second,
byte *minute,
byte *hour,
byte *dayOfWeek,
byte *dayOfMonth,
byte *month,
byte *year)
{
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set DS3231 register pointer to 00h
  Wire.endTransmission();
  Wire.requestFrom(DS3231_I2C_ADDRESS, 7);
  // request seven bytes of data from DS3231 starting from register 00h
  *second = bcdToDec(Wire.read() & 0x7f);
  *minute = bcdToDec(Wire.read());
  *hour = bcdToDec(Wire.read() & 0x3f);
  *dayOfWeek = bcdToDec(Wire.read());
  *dayOfMonth = bcdToDec(Wire.read());
  *month = bcdToDec(Wire.read());
  *year = bcdToDec(Wire.read());
}

// funcao votar

void votar(String cor)
{
  // abrir arquivo
  ArquivoTxt = SD.open("votos.csv",FILE_WRITE);
  if(ArquivoTxt){  
    byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
    // retrieve data from DS3231
    readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,
    &year);
    // send it to the serial monitor
    
  ////////////////////////////
  Serial.print(hour, DEC);
  // convert the byte variable to a decimal number when displayed
  Serial.print(":");
  if (minute<10)
  {
    Serial.print("0");
  }
  Serial.print(minute, DEC);
  Serial.print(":");
  if (second<10)
  {
    Serial.print("0");
  }
  Serial.print(second, DEC);
  Serial.print(" ");
  Serial.print(dayOfMonth, DEC);
  Serial.print("/");
  Serial.print(month, DEC);
  Serial.print("/");
  Serial.print(year, DEC);
  
  ////////////////////////
    ArquivoTxt.print(cor);
    ArquivoTxt.print(";");
      
    ArquivoTxt.print(hour, DEC);
    // convert the byte variable to a decimal number when displayed
    ArquivoTxt.print(":");
    if (minute<10)
    {
      ArquivoTxt.print("0");
    }
    ArquivoTxt.print(minute, DEC);
    ArquivoTxt.print(":");
    if (second<10)
    {
      ArquivoTxt.print("0");
    }
    ArquivoTxt.print(second, DEC);
    ArquivoTxt.print(";");
    ArquivoTxt.print(dayOfMonth, DEC);
    ArquivoTxt.print("/");
    ArquivoTxt.print(month, DEC);
    ArquivoTxt.print("/");
    ArquivoTxt.print(year, DEC);
    ArquivoTxt.print(";");
    
    switch(dayOfWeek){
    case 1:
      ArquivoTxt.println("Domingo");
      break;
    case 2:
      ArquivoTxt.println("Segunda");
      break;
    case 3:
      ArquivoTxt.println("Terca");
      break;
    case 4:
      ArquivoTxt.println("Quarta");
      break;
    case 5:
      ArquivoTxt.println("Quinta");
      break;
    case 6:
      ArquivoTxt.println("Sexta");
      break;
    case 7:
      ArquivoTxt.println("Sabado");
      break;
    }
    
    // fechar aquivo
    ArquivoTxt.close();
    
    // sinal de confirmacao
    digitalWrite(buzzer,HIGH);
    delay(60);
    digitalWrite(buzzer,LOW);
    delay(60);
    digitalWrite(buzzer,HIGH);
    delay(60);
    digitalWrite(buzzer,LOW);
    delay(60);
    Serial.print("voto ok");
    Libera_catraca();
  }
  else{ //erro ao abrir arquivo
    ClearLCD();
    delay(1000);
    lcd.setCursor(1,0);
    lcd.print("ERRO no cartao");
    lcd.setCursor(3,1);
    lcd.print("de memoria");
    delay(5000);
  }
  
}






void loop()
{
  // define estado de cada Botao
  estado_btn_r = digitalRead(btn_r);
  estado_btn_g = digitalRead(btn_g);
  estado_btn_y = digitalRead(btn_y);
  estado_btn_b = digitalRead(btn_b);
  digitalWrite(rele,HIGH);
  /**/
  Serial.println("red");
  Serial.println(estado_btn_r);
  Serial.println(estado_btn_g);
  Serial.println(estado_btn_b);
  Serial.println(estado_btn_y);
  /**/
   
   
   //mensagem inicial   
   
   lcd.setCursor(2,0); 
   lcd.print(" Avilie sua");
   lcd.setCursor(2,1); 
   lcd.print(" Refeicao");
  //
  
  if(estado_btn_r == HIGH ){// vermelho
      
    lcd.setCursor(0,0); // seta o cursor para: (coluna = 0, linha = 0)
    lcd.print(" Muito Obrigado!");
    delay(200);
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    delay(100);
    ClearLCD();
    
    lcd.setCursor(0,0); // seta o cursor para: (coluna = 0, linha = 0)
    lcd.print("Que tal uma");
    lcd.setCursor(0,1); // seta para linha 1, ou seja, a linha de baixo
    lcd.print("Sugestao?");
    delay(1500);
    ClearLCD();
    votar("vermelho");
}
  if(estado_btn_y == HIGH){ // amarelo    
    lcd.setCursor(0,0); // seta o cursor para: (coluna = 0, linha = 0)
    lcd.print(" Muito Obrigado!");
    delay(200);
    
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    delay(100);
    ClearLCD();
    
    lcd.setCursor(0,0); // seta o cursor para: (coluna = 0, linha = 0)
    lcd.print("Que tal uma");
    lcd.setCursor(0,1); // seta para linha 1, ou seja, a linha de baixo
    lcd.print("Sugestao?");
    delay(1500);
    ClearLCD();
    votar("amarelo");
  }
  
  if(estado_btn_g == HIGH){    
    lcd.setCursor(0,0); // seta o cursor para: (coluna = 0, linha = 0)
    lcd.print(" Muito Obrigado!");
    delay(200);
     digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    delay(100);
    ClearLCD();
    lcd.setCursor(0,1); // seta para linha 1, ou seja, a linha de baixo
    lcd.print("Volte Sempre!");
    delay(1500);
    ClearLCD();
    votar("verde");
    }
    
    if(estado_btn_b == HIGH){    
    lcd.setCursor(0,0); // seta o cursor para: (coluna = 0, linha = 0)
    lcd.print(" Muito Obrigado!");
    delay(200);
     digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    delay(100);
    ClearLCD();
    lcd.setCursor(0,1); // seta para linha 1, ou seja, a linha de baixo
    lcd.print("Volte Sempre!");
    delay(1500);
    ClearLCD();
    votar("azul");
    }
    
}

// ira liberar o rele da cancela por 1.5 segundos e trancar novamente
void Libera_catraca(){
  digitalWrite(rele,LOW);
  lcd.setCursor(0,0); // seta o cursor para: (coluna = 0, linha = 0)
    lcd.print("Catraca Liberada");
  delay(TEMPO_CATRACA); // TEMPO que a catraca fica liberada
  digitalWrite(rele,HIGH);
}

// apaga todos os caracteres do display
void ClearLCD(){
    lcd.setCursor(0,0); 
    lcd.print("                 ");
    lcd.setCursor(0,1); 
    lcd.print("                 ");
}
