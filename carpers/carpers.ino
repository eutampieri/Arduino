#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int rows=2;
const int cols=16;
byte glyphs[8][8]={
  {B00000, B00100, B10101, B01110, B11111, B01110, B10101, B00100},
  {B00100, B00100, B00100, B00100, B00100, B01010, B10111, B01110},
{B00100, B00100, B00100, B00100, B00100, B01110, B01110, B01110}};
  void setup(){
    lcd.begin(cols,rows);
    for(int i=0; i <3; i++)
    lcd.createChar(i,glyphs[i]);
    lcd.clear();}
    void loop(){
      for (byte i=0; i<3; i++)
      lcd.write(i);
      delay (5000);
      lcd.clear();
    }
