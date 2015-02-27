const int sensorPin = A0;
const float baselineTemp = 20.0;
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup(){
  pinMode(13,OUTPUT);
    lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Termometro C  ET");
  Serial.begin(9600);//apertura porta seriale;
}
void loop(){
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
