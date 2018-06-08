#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16,2);
lcd.setCursor(0,0);
  lcd.print("linha 1");
  lcd.setCursor(0,1);
  lcd.print("L");
  delay(300);
  lcd.print("i");
  delay(300);
  lcd.print("n");
  delay(300);
  lcd.print("h");
  delay(300);
  lcd.print("a ");
  delay(300);
  lcd.print("2");
}

void loop() {
  
}
