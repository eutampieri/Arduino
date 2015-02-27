int motore=9;
int led=10;
int debug=13;
void setup(){
  pinMode(motore,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(debug,OUTPUT);
  digitalWrite(debug,LOW);
}
void loop(){
  digitalWrite(debug,HIGH);
  for(int i=0;i<=255;i++){
    analogWrite(motore,i);
    analogWrite(led,i);
    delay(100);
  }
  for(int i=0;i<=4;i++){
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
    delay(500);
  }
  digitalWrite(led,HIGH);
  delay(2000);
  for(int i=0;i<=4;i++){
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
    delay(500);
  }
  for(int i=255;i>0;i--){
    analogWrite(motore,i);
    analogWrite(led,i);
    delay(100);
  }
  digitalWrite(led,LOW);
  digitalWrite(motore,LOW);
  digitalWrite(debug,LOW);
  for(int i=0; i<10;i++){
    digitalWrite(debug,HIGH);
    delay(500);
    digitalWrite(debug,LOW);
    delay(500);
  }
}
