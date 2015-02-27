#include<LiquidCrystal.h>
#include <EEPROM.h>
LiquidCrystal lcd(12,11,5,4,3,2);
byte byteSet=0;
byte set;
byte materie;
byte byteMaterie=1;
byte ledVerde=7;
byte ledRosso=8;
byte pinPulsante=6;
int pot=A0;
boolean pulsante;
//byte matematica[25];
void setup(){
  pinMode(pinPulsante,INPUT);
  pinMode(ledVerde,OUTPUT);
  pinMode(ledRosso, OUTPUT);
  lcd.begin(16,2);
  set=EEPROM.read(byteSet);
  if(set==0){
    while(true){
      pulsante=digitalRead(pinPulsante);
      lcd.print("Materie studiate?");
      lcd.setCursor(0,1);
      int nmat=map(analogRead(pot),0,1023,0,20);
      lcd.print(nmat);
      if(pulsante==true){
        EEPROM.write(byteMaterie,nmat);
        EEPROM.write(byteSet,1);
        materie=nmat;
        break;
      }
    }
  }
  else if(set=1){
    materie=EEPROM.read(byteMaterie);
  }
}
void loop(){
  for(int i=0; i<=materie
}


