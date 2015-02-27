void setup(){
  int pinN=2;
  while(pinN<=2){
    pinMode(pinN, OUTPUT);
    pinN++;
  }
  pinN=2;
  while (pinN<=2){
    digitalWrite(pinN, HIGH);
  }
}
void loop(){}
