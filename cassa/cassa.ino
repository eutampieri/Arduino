//24/02/14, By Eugenio Tampieri
int pinOut=8;
int adIn=7;
int ridIn=6;
int posti=12;
int posto=0;
int counter=0;
int totAd=0;
int totRid=0;
int prezzoIntero=5;
float ridotto=3.5;
float totEur=0;
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
byte chars[16][16]={
  {B00000, B00000, B01110, B10010, B11100, B10100, B10100, B00000},
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B00000, B00000, B00100, B00010, B11110, B00010, B00100, B00000}
};
void setup(){
  pinMode(10,OUTPUT);
  pinMode(13,OUTPUT);
  digitalWrite(10,HIGH);
  lcd.begin(16, 2);
//  Serial.begin(9600);
  lcd.print("     iCassa     ");
  //modificare il valore della funzione "avvioclassico" per ottimizzare il tempo di startup.
  //commentarla per escludere lo startup
  avvioclassico(500);
  //se si è commentata la linea precedente, decommentare qualla successiva
  //delay(500*8);
  lcd.setCursor(0,0);
//  Serial.println("Rev 21/02/14, By Eugenio Tampieri");
//  Serial.println("Predisposto solo all'utilizzo con LCD o con sketch Procesisng");
  lcd.print("Rev 24/02/14, By");
  lcd.setCursor(0,2);
  lcd.print("Eugenio Tampieri");
  lcd.setCursor(0,1);
  delay(2500);
  lcd.clear();
  lcd.setCursor(5,0);
  for(int i=0; i <7; i++)
    lcd.createChar(i,chars[i]);
    lcd.clear();
    lcd.setCursor(5,0);
    for (byte i=0; i<5; i++){
      lcd.write(i);}
    lcd.setCursor(0,0);
    lcd.print("Eur  ");
    digitalWrite(10,LOW);
    analogWrite(10,150);
    digitalWrite(13,LOW);
    lcd.setCursor(0,1);
    }
void loop(){
  boolean statoAdulto=digitalRead(adIn);
  boolean statoOut=digitalRead(pinOut);
  boolean statoRid=digitalRead(ridIn);
  totEur=totAd+totRid;
  lcd.print(totEur);
  lcd.setCursor(5,1);
  lcd.print(posto);
  lcd.setCursor(9,1);
  lcd.print(counter);
  if(statoAdulto==HIGH){
    counter++;
    posto++;
    totAd+prezzoIntero;
    delay(500);
  }
}
void avvioclassico(int rit){
  lcd.setCursor(0,1);
  lcd.print("Starting ");
  delay(rit);
  lcd.setCursor(8,1);
  lcd.print(".");
  delay(rit);
  for(int i=9;i<=15;i++){
    lcd.setCursor(i,1);
    lcd.print(".");
    delay(rit);
  }
}
