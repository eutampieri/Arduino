const int note[]={262,294,330,349};
void setup(){}
void loop(){
  int keyval=analogRead(A0);
  if(keyval==1023){
    tone(8, note[0]);
  }
  else if(keyval>=990&&keyval<=1010){
    tone(8,note[1]);
  }
  else if(keyval>=505&&keyval<=515){
    tone(8,note[2]);
  }
  else if(keyval>=5&&keyval<=10){
    tone(8,note[3]);
  }
  else{
    noTone(8);
  }
}
