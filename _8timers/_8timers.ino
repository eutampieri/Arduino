#include <EEPROM.h>
//8Timers
int oldMillis[8];
boolean pulsanti[8]{false,false,false,false,false,false,false,false};
float minutes[8];
int millisec[8];
void setup(){
  tempo=millis();
  for(int p=2;p<=10;p++){
    pinMode(p,INPUT);
  }
  for(int e=0;e<8;e++){
    minutes[e]=float(EEPROM.read(e));
  }
}
void loop(){
  if(digitalRead(2)==HIGH){
    if(pulsanti[0]==false){
      oldMillis[0]=int(millis());
      millisec[0]=int(millis())-tempo
