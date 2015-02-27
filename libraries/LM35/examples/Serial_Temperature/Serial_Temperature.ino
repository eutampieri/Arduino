#include <LM35.h>
char val;
const int sensore=A0;
void setup(){
  Serial.begin(9600);
  Serial.println("Type G or g to obtain datas");
}
void loop(){
  if(Serial.available()){
    val=Serial.read();
    if(val=='G'|| val=='g'){
      Serial.println("-- Celsius --");
      Serial.print(readC(sensore));
      Serial.println("°C");
      Serial.println("-- Fahrenheit --");
      Serial.print(readF(sensore));
      Serial.println("°F");
      Serial.println("-- Kelvin --");
      Serial.print(readK(sensore));
      Serial.println(" k");
      Serial.println("-- Rankine --");
      Serial.print(readRankine(sensore));
      Serial.println("°R");
      Serial.println("-- Reaumur --");
      Serial.print(readReaumur(sensore));
      Serial.println("°r");
      Serial.println("-- Newton --");
      Serial.print(readN(sensore));
      Serial.println("°N");
      Serial.println("-- Delisle --");
      Serial.print(readDe(sensore));
      Serial.println("°De");
      Serial.println("-- Romer --");
      Serial.print(readDe(sensore));
      Serial.println("°Ro");
      delay(1000);
    }
  }
}