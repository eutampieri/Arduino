boolean numeri[90];
int cambio;
int conta;
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void setup(){
  for (int i = 1 ; i <= 90 ; i++)
    numeri[i - 1] = false;
  conta = 0;
  cambio = 0;
  pinMode(2,INPUT);
  pinMode(13,OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Tombola!      ET");
  Serial.begin(9600);
}

void loop(){
  digitalWrite(13,LOW);
  cambio = digitalRead(9);
  digitalWrite(13,LOW);
  if (cambio == HIGH)
  {
    Serial.println("Pulsante premuto");
    int number;
    number = rand()%90;
    Serial.println(number);
    delay(1000);
    if (number >= 0 && number < 90)
    {
      if (numeri[number])
        delay(1);
      else
      {
        numeri[number] = true;
        lcd.setCursor(0, 1);
        lcd.print(number);
        ++conta;
        Serial.print(conta + 1);
      }
    }
    delay(1000);
    if (conta == 90)
    {
      delay(1);
      lcd.print("Tombola finita");
    }
  }
  else{
    delay(1);
  }
}

