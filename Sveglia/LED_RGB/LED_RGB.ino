//RCBG
int ldrPin=A0;
int redPin=11;
int bluePin=10;
int greenPin=9;
void setup(){
  Serial.begin(9600);
  pinMode(ldrPin,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(greenPin,OUTPUT);
}
void loop(){
  bianco();
  semaforo();
}
void semaforo(){
  if(Serial.available()>0){
    char colore=Serial.read();
    Serial.print(colore);
  }
}
void allthreecolors(){
  int lettura=analogRead(ldrPin);
  int letturamappata=map(lettura,0,1023,0,100);
  analogWrite(redPin,56);
  delay(5000);
  analogWrite(redPin,0);
  analogWrite(bluePin,99);
  delay(5000);
  Serial.print("Blu= ");
  Serial.println(letturamappata);
  analogWrite(bluePin,0);
  analogWrite(greenPin,255);
  delay(5000);
  Serial.print("Verde= ");
  Serial.println(letturamappata);
  analogWrite(greenPin,0);
}
void bianco(){
  analogWrite(redPin,255);
  analogWrite(bluePin,255);
  analogWrite(greenPin,255);
}
