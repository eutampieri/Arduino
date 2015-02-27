#include "LiquidCrystal.h";
#include "EEPROM.h":
LiquidCrystal lcd(12,11,5,4,3,2);
int imp;
int n=1;
String materie[n];
String compito[n];
int tempo[n];
int millisdone[n];
void setup(){
	imp=EEPROM.read(0);
	Serial.println("Modifico? 1 per modificare");
	int set=int(Serial.read());
	Serial.begin(9600);
	lcd.begin(16,2);
	if(imp==0||set==1){
		Serial.println("Inserisci il numero di compiti da svolgere");
		n=int(Serial.read());
		for(int i=0;i<n;i++){
			Serial.println("Nome Materia");
			materie[i]=str(Serial.read());
			Serial.println("Compito:");
			compito[i]=str(Serial.read());
			Serial.println("Tempo Previsto");
			tempo[i]=int(Serial.read());
		}
		EEPROM.write(0,1);
		EEPROM.write(1,n);
		for(int i=0;i<n;i++){
			int a=i+2;
			EEPROM.write(a,materie[i])
		}
		for(int i=0;i<n;i++){
			int a=i+2;
			EEPROM.write(a,materie[i])
		}
	}
	else if(imp==1){
	    // statement
	}
}
void loop(){}
