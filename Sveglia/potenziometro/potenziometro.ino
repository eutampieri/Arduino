int potPin=A0;
void setup(){
  Serial.begin(9600);
  pinMode(potPin,INPUT);
}
void loop(){
  int lettura=analogRead(potPin);
  int minuti=map(lettura,0,1023,1,120);
  Serial.println(minuti);
//  delay(1000);
}
