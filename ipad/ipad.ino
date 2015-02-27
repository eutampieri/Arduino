const int freqs[15]={262,262,330,330,220,220,262,262,587,587,196,196,247,247};
void setup(){}
void loop(){
/*  for(int i=0; i<=14;i++){
    tone(8,freqs[i],2000);
  }*/
  tone(8,freqs[0],1000);
  delay(1000 );
  tone(8,freqs[1],1000);
  delay(1000);
  tone(8,freqs[2],1000);
  delay(100);
  tone(8,freqs[3],1000);
  delay(1000);
  tone(8,freqs[4],1000);
  delay(100);
  tone(8,freqs[5],1000);
  delay(1000);
  tone(8,freqs[6],1000);
  delay(1000);
  tone(8,freqs[7],1000);
  delay(5000);
}
