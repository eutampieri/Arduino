int pinFotoaccoppiatore=13;
float durataCampanella=2.5;
int durataOre[8]={5,55,60,10,55,60,5,55};
int durSec=1000;
int durMin=60;
int minToMillis=durSec*durMin;
void setup(){
  pinMode(pinFotoaccoppiatore,OUTPUT);
  Serial.begin(9600);
}
void loop(){
  boolean fine=false;
  while(fine==false){
    int i=0;
    while(i<=8){
      suona();
      int ritardo=durataOre[i]*minToMillis;
      Serial.println(ritardo);
      delay(ritardo);
      Serial.println(durataOre[i]);
      Serial.println(i);
      Serial.println("_---_");
      i=i++;
    }
    fine=true;
  }
}
void suona(){
  digitalWrite(pinFotoaccoppiatore,HIGH);
  int durCampana=durataCampanella*durSec;
  delay(durCampana);
  digitalWrite(pinFotoaccoppiatore,LOW);
}
