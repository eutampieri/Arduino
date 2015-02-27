const int sensorPin = A0;
const float baselineTemp = 20.0;
float SensorValue;
float luminosita;
float voltsvento;
float vento;
// include the library code:
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
byte chars[16][16]={
  {B00100, B00100, B00100, B00100, B00100, B01010, B10111, B01110},
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B01110, B10001, B10000, B10000, B10000, B10000, B10001, B01110},
{B00010, B00101, B00010, B00000, B00000, B00000, B00000, B00000},
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B00000, B00100, B10101, B01110, B11111, B01110, B10101, B00100}/*,
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
{B11111, B10000, B10000, B10000, B11111, B10000, B10000, B11111},
{B11111, B00100, B00100, B00100, B00100, B00100, B00100, B00100}*/};
void setup(){
  pinMode(13,OUTPUT);
    lcd.begin(16, 2);
  // Print a message to the LCD.
  Serial.begin(9600);//apertura porta seriale;
  for(int i=0; i <7; i++)
    lcd.createChar(i,chars[i]);
    lcd.clear();
    for (byte i=0; i<7; i++)
      lcd.write(i);
    }
void loop(){
  voltsvento=analogRead(A2);
  vento=map(voltsvento,0,1023,0,100);
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
  SensorValue = analogRead(A1);
  luminosita=map(SensorValue,0,1023,0,100);
  // print the number of seconds since reset:
  lcd.print(temperature);
  lcd.print(" ");
  lcd.print(luminosita);
  lcd.print(" ");
  lcd.print(vento);
  delay(1000);
  lcd.print("              ");
}
