#include <LiquidCrystal.h>
const byte ohm=B11110100;
const int Vref=5;
const float rfact=319.6875;
LiquidCrystal lcd(12,11,5,4,3,2);
void setup(){
  lcd.begin(2,16);
  lcd.print("ET Tester");
  lcd.setCursor(0,1);
  lcd.print("   V MAX: 15V");
  delay(5000);
  lcd.clear();
}
void loop(){
  lcd.setCursor(0,0);
  lcd.print("V:");
  float lettura=analogRead(A0);
  float volts=(lettura/rfact)*Vref;
  lcd.setCursor(3,0);
  lcd.print(volts);
  delay(1000);
  lcd.clear();
/*  lcd.setCursor(0,0);
  lcd.write(ohm);
  lcd.setCursor(3,0);
  float resistenza=analogRead(A2);
  float volt=(5.0 / 1023.0) * resistenza;
  int ohm=10000/((5/volt)-1);
  lcd.print(ohm);
  delay(1000);
  lcd.clear();*/
}
