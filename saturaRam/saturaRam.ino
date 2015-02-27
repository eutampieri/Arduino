void setup(){
  Serial.begin(9600);
}
int i=0;
String arduino="Arduino";
void loop(){
  i++;
  arduino.concat(i);
  Serial.println(arduino);
}

