int pinPulsantePolizia=2;
int pinLedLadri1=4;
int pinLedLadri2=5;
int pinLedLadri3=6;
int pinLedLadri4=7;
int prigioneLadri=0;
int statoPolizia;
int pinPulsanteLadri=3;
int pinSoldi1=8;
int pinSoldi2=9;
int pinSoldi3=10;
int pinSoldi4=11;
int pinSoldi5=12;
int pinSoldi6=13;
int pinSoldi7=A0;
int pinSoldi8=A1;
int pinSoldi9=A2;
int pinSoldi10=A3;
void setup(){
  pinMode(pinPulsantePolizia, INPUT);
  pinMode(pinLedLadri1,OUTPUT);
  pinMode(pinLedLadri2,OUTPUT);
  pinMode(pinLedLadri3,OUTPUT);
  pinMode(pinLedLadri4,OUTPUT);
  pinMode(pinPulsanteLadri,INPUT);
  Serial.begin(9600);
}
void loop(){
  statoPolizia=digitalRead(pinPulsantePolizia);
  if(statoPolizia==HIGH){
    prigioneLadri=prigioneLadri++;
    delay(300);
    if (prigioneLadri==1){
      digitalWrite(pinLedLadri1,HIGH);
    }
    if(prigioneLadri==2){
      digitalWrite(pinLedLadri2,HIGH);
    }
    if(prigioneLadri==3){
      digitalWrite(pinLedLadri3,HIGH);
    }
    if(prigioneLadri==4){
      digitalWrite(pinLedLadri4,HIGH);
      delay(250);
      digitalWrite(pinLedLadri1,HIGH);
      digitalWrite(pinLedLadri2,LOW);
      digitalWrite(pinLedLadri3,LOW);
      digitalWrite(pinLedLadri4,LOW);
      delay(250);
      digitalWrite(pinLedLadri1,LOW);
      digitalWrite(pinLedLadri2,HIGH);
      digitalWrite(pinLedLadri3,LOW);
      digitalWrite(pinLedLadri4,LOW);
      delay(250);
      digitalWrite(pinLedLadri1,LOW);
      digitalWrite(pinLedLadri2,LOW);
      digitalWrite(pinLedLadri3,HIGH);
      digitalWrite(pinLedLadri4,LOW);
      delay(250);
      digitalWrite(pinLedLadri1,LOW);
      digitalWrite(pinLedLadri2,LOW);
      digitalWrite(pinLedLadri3,LOW);
      digitalWrite(pinLedLadri4,HIGH);
      delay(250);
      digitalWrite(pinLedLadri1,HIGH);
      digitalWrite(pinLedLadri2,HIGH);
      digitalWrite(pinLedLadri3,HIGH);
      digitalWrite(pinLedLadri4,HIGH);
      delay(250);
      digitalWrite(pinLedLadri1,HIGH);
      digitalWrite(pinLedLadri2,LOW);
      digitalWrite(pinLedLadri3,LOW);
      digitalWrite(pinLedLadri4,LOW);
      delay(250);
      digitalWrite(pinLedLadri1,LOW);
      digitalWrite(pinLedLadri2,HIGH);
      digitalWrite(pinLedLadri3,LOW);
      digitalWrite(pinLedLadri4,LOW);
      delay(250);
      digitalWrite(pinLedLadri1,LOW);
      digitalWrite(pinLedLadri2,LOW);
      digitalWrite(pinLedLadri3,HIGH);
      digitalWrite(pinLedLadri4,LOW);
      delay(250);
      digitalWrite(pinLedLadri1,LOW);
      digitalWrite(pinLedLadri2,LOW);
      digitalWrite(pinLedLadri3,LOW);
      digitalWrite(pinLedLadri4,HIGH);
      delay(250);
      digitalWrite(pinLedLadri1,HIGH);
      digitalWrite(pinLedLadri2,HIGH);
      digitalWrite(pinLedLadri3,HIGH);
      digitalWrite(pinLedLadri4,HIGH);
      delay(250);
      digitalWrite(pinLedLadri1,HIGH);
      digitalWrite(pinLedLadri2,LOW);
      digitalWrite(pinLedLadri3,LOW);
      digitalWrite(pinLedLadri4,LOW);
      delay(250);
      digitalWrite(pinLedLadri1,LOW);
      digitalWrite(pinLedLadri2,HIGH);
      digitalWrite(pinLedLadri3,LOW);
      digitalWrite(pinLedLadri4,LOW);
      delay(250);
      digitalWrite(pinLedLadri1,LOW);
      digitalWrite(pinLedLadri2,LOW);
      digitalWrite(pinLedLadri3,HIGH);
      digitalWrite(pinLedLadri4,LOW);
      delay(250);
      digitalWrite(pinLedLadri1,LOW);
      digitalWrite(pinLedLadri2,LOW);
      digitalWrite(pinLedLadri3,LOW);
      digitalWrite(pinLedLadri4,HIGH);
      delay(250);
      digitalWrite(pinLedLadri1,HIGH);
      digitalWrite(pinLedLadri2,HIGH);
      digitalWrite(pinLedLadri3,HIGH);
      digitalWrite(pinLedLadri4,HIGH);
      delay(250);
      digitalWrite(pinLedLadri1,HIGH);
      digitalWrite(pinLedLadri2,LOW);
      digitalWrite(pinLedLadri3,LOW);
      digitalWrite(pinLedLadri4,LOW);
      delay(250);
      digitalWrite(pinLedLadri1,LOW);
      digitalWrite(pinLedLadri2,HIGH);
      digitalWrite(pinLedLadri3,LOW);
      digitalWrite(pinLedLadri4,LOW);
      delay(250);
      digitalWrite(pinLedLadri1,LOW);
      digitalWrite(pinLedLadri2,LOW);
      digitalWrite(pinLedLadri3,HIGH);
      digitalWrite(pinLedLadri4,LOW);
      delay(250);
      digitalWrite(pinLedLadri1,LOW);
      digitalWrite(pinLedLadri2,LOW);
      digitalWrite(pinLedLadri3,LOW);
      digitalWrite(pinLedLadri4,HIGH);
      delay(250);
      digitalWrite(pinLedLadri4,LOW);
    }
    if(prigioneLadri>=5){
      prigioneLadri=0;
    }
    Serial.println(prigioneLadri);
  }
}
