int pinFotoresistenza=A0;
int pinLed=3;
int pinLedArduino=13;
int intensita;
int pinButton=2;
boolean premuto=false;
int pulsante;
int serialread;
unsigned int diffintensita;
int luminosita;
void setup(){
  pinMode(pinButton, INPUT);
  pinMode(pinFotoresistenza, INPUT);
  pinMode(pinLed, OUTPUT);
  pinMode(pinLedArduino, OUTPUT);
  digitalWrite(pinLedArduino, LOW);
  Serial.begin(9600);
}
void loop(){
  pulsante=digitalRead(pinButton);
  luminosita=analogRead(pinFotoresistenza);
  diffintensita=map(luminosita, 0,500, 0,255);
  Serial.println (diffintensita);
  intensita=255-diffintensita;
  if (intensita<0){
    intensita=0;
  }
  if (intensita>255){
    intensita=255;
  }
  if(premuto==false){
    analogWrite(pinLed, intensita);
  }
  Serial.print("Luminosità: /t");
  Serial.println(luminosita);
  Serial.print("Intensità LED: /t");
  Serial.println(intensita);
  if(pulsante==HIGH){
    Serial.println("premuto");
    premuto=true;
  }
  if (premuto==true){
    analogWrite(pinLed, 0);
    if(pulsante==HIGH){
      premuto==0;
      Serial.println(premuto);
    }
  }
  delay(500);
}
