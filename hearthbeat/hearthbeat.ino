const int sensorPin=A0;
const int ledPin=13;
const int THRESHOLD=1;
void setup(){
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
}
void loop(){
  int val=analogRead(sensorPin);
  if(val>=THRESHOLD){
    digitalWrite(ledPin,HIGH);
    Serial.println(val);
  }
  else{
    digitalWrite(ledPin,LOW);
  }
  delay(20);
}
