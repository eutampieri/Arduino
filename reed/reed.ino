const int reedPin=9;
boolean statoPrecedente=LOW;
boolean stato;
void setup(){
  Serial.begin(9600);
  pinMode(reedPin, INPUT_PULLUP);
}
int i=0;
void loop(){
  stato=digitalRead(reedPin);
  Serial.println(stato);
  if(stato !=statoPrecedente){
    i++;
    Serial.println(i);
    statoPrecedente=stato;
  }
  delay(10);
}
