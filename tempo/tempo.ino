unsigned long mill;
boolean stop=false;
unsigned long sec;
float minu;
unsigned long ore;
unsigned long tempo;
void setup(){
  Serial.begin(9600);
  pinMode(10,INPUT);
}
void loop(){
  tempo=mill/1000;
  if(digitalRead(10)==HIGH){
    if(stop==false){
    mill=0;
    stop=true;
  }
    if(stop==true){
      mill=millis();
    }
    Serial.println(tempo);
}
}

