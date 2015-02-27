#include "LiquidCrystal.h";
LiquidCrystal lcd(12,11,5,4,3,2);
void setup(){
	int millisdone;
	int n;
	Serial.begin(9600);
	lcd.begin(16,2);
	Serial.println("Inserisci il numero di compiti da svolgere");
	n=int(Serial.read());
	String materie[n];
	String compito[n];
	int tempo[n];
	for(int i=0;i<n;i++){
		Serial.println("Nome Materia");
		materie[i]=Serial.read();
		Serial.println("Compito:");
		compito[i]=Serial.read();
		Serial.println("Tempo Previsto");
		tempo[i]=int(Serial.read());
	}
	for(int i=0; i<n;i++){
		lcd.print(materie[i]);
		lcd.setCursor(14,0);
		lcd.print(tempo[i]);
		lcd.setCursor(0,1);
		lcd.print(compito[i]);
		delay(tempo[i]*60000);
	}
}
void loop(){
	
}
