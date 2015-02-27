#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int potPin=A0;
int lettura;
int euro;
int portaSeriale=9600;
int minLettura=0;
int maxLettura=1023;
int minEuro=1;
int maxEuro=100;
void setup(){
  lcd.begin(16,2);
  Serial.begin(portaSeriale);
  digitalWrite(10,HIGH);
}
void loop(){
  lcd.setCursor(0,0);
  lettura=analogRead(potPin);
  euro=map(lettura,minLettura,maxLettura,minEuro,maxEuro);
  lcd.print(euro);
  lcd.println(" Euro");
  Serial.print(euro);
  Serial.println(" Euro");
}
