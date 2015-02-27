const int sensorPin = A0;
const float baselineTemp = 20.0;
// include the library code:
#include <LiquidCrystal.h>
#include <Time.h>
#define TIME_MSG_LEN 11
#define TIME_HEADER 'T'

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
byte chars[16][16]={
  {B00100, B00100, B00100, B00100, B00100, B01010, B10111, B01110},
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B00000, B00100, B10101, B01110, B11111, B01110, B10101, B00100},
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B11111, B10000, B10000, B10000, B11111, B10000, B10000, B11111},
{B11111, B00100, B00100, B00100, B00100, B00100, B00100, B00100}};
void setup(){
  pinMode(13,OUTPUT);
    lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Termometro C  ET");
  Serial.begin(9600);//apertura porta seriale;
 Serial.println("In attesa del messaggio orario...");
  for(int i=0; i <16; i++)
    lcd.createChar(i,chars[i]);
    lcd.clear();
    for (byte i=0; i<16; i++)
      lcd.write(i);
}
void loop(){
  if(Serial.available() ){
    processSyncMessage();
  }
  if(timeStatus()!=timeNotSet){
    digitalClockDisplay();
  }
  digitalWrite(13,LOW);
  int sensorVal=analogRead(sensorPin);
  Serial.print("Valore sensore: ");
  Serial.print(sensorVal);
  float voltage=(sensorVal/1024.0)*5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", gradi C°: ");
  float temperature=(voltage-.5)*100;
  Serial.print(temperature);
  Serial.print('\n');
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(temperature);
  delay(3000);
}
void digitalClockDisplay(){
  lcd.print(" ");
  lcd.print(hour());
  printDigits(minute());
}
void printDigits(int digits){
  lcd.print(":");
  if(digits<10){
    lcd.print(0);}
    lcd.print(digits);
}
void processSyncMessage(){
  while(Serial.available()>=TIME_MSG_LEN){
  char c=Serial.read();
  Serial.print(c);
  if(c==TIME_HEADER){
    time_t pctime=0;
    for(int i=0; i < TIME_MSG_LEN -1;i++){
    if(isdigit(c)){
    pctime=(10*pctime)+(c-'0');
    }
    }
  setTime(pctime);
  }
}
}
