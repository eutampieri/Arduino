//Arduino color palette
int red[5]={0,98,228,229,140};
int green[5]={153,174,113,173,121};
int blue[5]={143,178,40,36,101};
int pinRed=9;
int pinGreen=10;
int pinBlue=11;
void setup(){
}
void loop(){
  for(int i=0;i<4;i++){
    analogWrite(pinRed,red[i]);
    analogWrite(pinGreen,green[i]);
    analogWrite(pinBlue,blue[i]);
    delay(500);
  }
  delay(1000);
}
