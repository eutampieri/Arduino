int pinVerdePedoni=2;
int pinGialloPedoni=3;
int pinRossoPedoni=4;
int pinPiezo=5;
int pinVerdeAuto=6;
int pinGialloAuto=7;
int pinRossoAuto=8;
int pinPulsante=9;
void setup(){
  for(int i=2; i<=4; i++){
    pinMode(i,OUTPUT);
  }
  for(int i=6; i<=8; i++){
    pinMode(i,OUTPUT);
  }
  pinMode(pinPulsante,INPUT_PULLUP);
}
void loop(){  
  boolean statoPulsante=digitalRead(pinPulsante);
  if(statoPulsante==HIGH){
    digitalWrite(2,HIGH);
    digitalWrite(8,HIGH);
    delay(1500);
   tone(pinPiezo, 150, 500);
  }
   if(statoPulsante==LOW){
   for(int f=2; f<=8; f++){
     digitalWrite(f,LOW);
   }
   tone(pinPiezo, 0, 1);
   }
}
