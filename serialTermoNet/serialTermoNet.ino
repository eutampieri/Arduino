//FORK di Termolight(25/02/14)
//Rev 21/02/14, by Eugenio Tampieri. Corretto un  bug nella conversiuone in lux
//                                   Corretto un bug che affliggeva la luminosità dell'LCD
//Rev 20/02/14, By Eugenio Tampieri. Nella funzione avvioclassico è stato inserito un ciclo for.
//                                   Convertita la luminosità in lux
//Rev 19/02/14 Aggiunta regoplazione luminosità con LDR
//Rev 15/02/14, By Eugenio Tampieri - Corretto bug lcd.clear()
//Rev 30/12/13, By Eugenio Tampieri
const int sensorPin = A0;
float SensorValue;
float luminosita;
float lux;
float temp;
// include the library code:
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
byte chars[16][16]={
  {B00100, B00100, B00100, B00100, B00100, B01010, B10111, B01110},
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B00010, B00101, B00010, B00000, B00000, B00000, B00000, B00000},
{B01110, B10001, B10000, B10000, B10000, B10000, B10001, B01110},
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B00000, B11111, B10101, B10101, B10101, B10101, B11111, B00000}
};
void setup(){
  Serial.begin(9600);
  pinMode(10,OUTPUT);
  pinMode(13,OUTPUT);
  digitalWrite(10,HIGH);
  lcd.begin(16, 2);
//  Serial.begin(9600);
  lcd.print(" serialTermoNet ");
  //modificare il valore della funzione "avvioclassico" per ottimizzare il tempo di startup.
  //commentarla per escludere lo startup
  avvioclassico(500);
  //se si è commentata la linea precedente, decommentare qualla successiva
  //delay(500*8);
  lcd.setCursor(0,0);
//  Serial.println("Rev 21/02/14, By Eugenio Tampieri");
//  Serial.println("Predisposto solo all'utilizzo con LCD o con sketch Procesisng");
  lcd.print("Rev 25/02/14, By");
  lcd.setCursor(0,2);
  lcd.print("Eugenio Tampieri");
  lcd.setCursor(0,1);
  delay(2500);
  lcd.clear();
  for(int i=0; i <7; i++)
    lcd.createChar(i,chars[i]);
    lcd.clear();
    for (byte i=0; i<7; i++)
      lcd.write(i);
     digitalWrite(10,LOW);
     lcd.setCursor(7,0);
     lcd.print(" C");
    }
void loop(){
  temp=Serial.read();
  digitalWrite(13,LOW);
  int sensorVal=analogRead(sensorPin);
  float voltage=(sensorVal/1024.0)*5.0;
  float temperature=(voltage-.5)*100;
  lcd.setCursor(0, 1);
  SensorValue = analogRead(A1);
  luminosita=SensorValue/10.23;
  lux=(luminosita+0.0)/10.0;
  lcd.print(temperature);
  Serial.println(temperature);
  lcd.print(" ");
  if(Serial.available()){
  lcd.print(temp);}
  else{
    lcd.print("NA   ");}
  lcd.print("   ET");
  lcd.print("              ");
  int lcdlum=map(luminosita,0,100,50,255);
  if(lcdlum<1){
    lcdlum=1;
  }
  analogWrite(10,lcdlum);
  delay(2000);
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
