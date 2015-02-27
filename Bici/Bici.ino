// Bici.ino
#include <LiquidCrystal.h>
#include "LM35.h"
// initialize the library with the numbers of the interface pins
int reed=6;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
	lcd.begin(16,2);
	pinMode(reed,INPUT);
}

void loop() {
	//4.38:5=x:y
	float batVolts=(analogRead(A0)/511.0)*5.0*5.0/4.38;
	lcd.print(batVolts);
	lcd.setCursor(5,0);
	lcd.print(readC(A1));
	lcd.setCursor(10,0);
	lcd.print(readKmH(reed, 26));
	delay(1500);
	lcd.clear();
	lcd.setCursor(0,0);
}
float readKmH(int reedPin, int raggio){
	const float pi=3.14159265359;
	int i=0;
	long startMillis=millis();
	while(i<5){
	    if(digitalRead(reedPin)==HIGH){
	    	i++;
	    	delay(20);
	    }
	}
	int t=millis()-startMillis;
	float s=raggio*2*pi*5;
	return s/t;
}