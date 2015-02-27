#include <pRNG.h>
#include <LiquidCrystal.h>
boolean numeri[90]={
  true, true, true,  true, true, true,  true, true, true,  true, true, true,  true, true, true,  true, true, true,  true, true, true,  true, true, true,  true, true, true,  true, true, true,  true, true, true,  true, true, true,  true, true, true,  true, true, true,  true, true, true,  true, true, true,  true, true, true,  true, true, true,  true, true, true,  true, true, true,  true, true, true,  true, true, true,  true, true, true,  true, true, true,  true, true, true,  true, true, true,  true, true, true,  true, true, true,  true, true, true,  true, true, true};
LiquidCrystal lcd(12,11,5,4,3,2);
pRNG rseed;
boolean fine=false;
boolean pulsante;
int pinPulsante=6;
int tombola;
int seed;
void setup(){
  pinMode(pinPulsante,INPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
  seed=rseed.getRndLong();
  randomSeed(seed);
  lcd.print("    Tombola!");
  lcd.setCursor(0,1);
  lcd.print(" 15/04/14 by ET");
}
void loop(){
  pulsante=digitalRead(pinPulsante);
  if(pulsante==HIGH){
    tombola=random(1,91);
    int narray=tombola-1;
    boolean stato=numeri[narray];
    if (numeri[narray]==true){
      numeri[narray]=false;
    }
    if(stato== true){
      lcd.clear();
      lcd.print(tombola);
      Serial.println(tombola);
      delay(200);
    }
  }
  boolean blocco=false;
  boolean finito;
  for(int i=0;i<90;i++){
    boolean lettura=numeri[i];
    if(lettura==true){
      finito=false;
      blocco=true;
      i=90;
    }
  }
  if(blocco==false){
    finito= true;
  }
  if(finito==true){
    if(fine==false){
      lcd.clear();
      int x;
      lcd.clear();
      lcd.print("By Eugenio Tampieri.");
      for(int i=0; i<=4;i++){
        lcd.scrollDisplayLeft();
        delay(150);
      }
      delay(1000);
      lcd.clear();
      lcd.print("Grazie alla libreria pNRG di Leonardo Mi");
      for(int i=0; i<=50;i++){
        lcd.scrollDisplayLeft();
        delay(150);
      }
      lcd.clear();
      lcd.print("lani (leonardomilani.com).");
      for(int i=0; i<=10;i++){
        lcd.scrollDisplayLeft();
        delay(150);
      }
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Made on Arduino");
      lcd.setCursor(0,1);
      lcd.print("   arduino.cc");
      delay(3000);
      lcd.clear();
      lcd.print("Visita etsoftware.bl.ee!");
      for(int i=0; i<=9;i++){
        lcd.scrollDisplayLeft();
        delay(150);
      }
      delay(1000);
      lcd.clear();
      lcd.print("FINE!");
    }
    fine=true;
  }
}
boolean done=false;
/*boolean checkFine(int pulsante, int tempo){
  if(done==false){
    pinMode(pulsante,INPUT_PULLUP);
    done=true;
  }
  if(digitalRead(pulsante)==LOW){
    return false;
    Serial.println("00");
  }
  else{
    return true;
  }
}*/
