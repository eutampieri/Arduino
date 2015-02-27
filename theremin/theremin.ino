int letturaSensore;
int minimo=1023;
int massimo=0;
const int pinLed=13;
void setup(){
  pinMode(pinLed, OUTPUT);
  digitalWrite(pinLed,HIGH);
  while(millis()<5000);{
    letturaSensore=analogRead(A0);
    if(letturaSensore>massimo){
      massimo=letturaSensore;
    }
    if(letturaSensore<minimo){
      minimo=letturaSensore;
    }
  }
  digitalWrite(pinLed,LOW);
}
void loop(){
   letturaSensore=analogRead(A0);
   int altezza=map(letturaSensore,minimo,massimo,120,3000);
   tone(8,altezza,20);
   delay(10);
}                                                                                                                                                                                                                      
