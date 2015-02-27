int LM35=A0;
void setup(){
  Serial.begin(9600);
}
void loop(){
  float temperatura=readToC(LM35);
  Serial.println(temperatura);
  delay(800);
}
float readToC(int pin){
  float reading=analogRead(pin);
  float celsius=(reading/1023*5.0-.5)*100;
  return celsius;
}
