#include"Servo.h"
  Servo servo;
void setup(){
  Serial.begin(9600);
  servo.attach(9);
}
void loop(){
  //  lampeggia(13,500);
  servo.write(map(analogRead(A0),0,1023,1,180));
}
void lampeggia(int pin, int tempo){
  long trasc=millis();
  long prevTrasc=0;
  if (trasc-prevTrasc){
    prevTrasc=trasc;
  }
  if(digitalRead(pin)==HIGH){
    digitalWrite(pin,LOW);
  }
  else{
    digitalWrite(pin,HIGH);
  }
}

