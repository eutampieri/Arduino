#include<LiquidCrystal.h>
int a=0;
int b=0;
int c=0;
int d=0;
int pulsante_a;
int pinPulsante_a=6;
int pulsante_b;
int pinPulsante_b=7;
int pulsante_c;
int pinPulsante_c=8;
int pulsante_d;
int pinPulsante_d=9;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup(){
  pinMode(pinPulsante_a,INPUT);
  pinMode(pinPulsante_b,INPUT);
  pinMode(pinPulsante_c,INPUT);
  pinMode(pinPulsante_d,INPUT);
  Serial.begin(9600);
  Serial.println("MultiCounter for Arduino by ET");
  lcd.begin(16,2);
  lcd.print("A   B   C   D");
}
void loop(){
  pulsante_a=digitalRead(pinPulsante_a);
  pulsante_b=digitalRead(pinPulsante_b);
  pulsante_c=digitalRead(pinPulsante_c);
  pulsante_d=digitalRead(pinPulsante_d);
  if (pulsante_a==HIGH){
  Serial.print("A");
  Serial.println(a);
  Serial.print("B");
  Serial.print(b);
  Serial.print("\t");
  Serial.print("C");
  Serial.print(c);
  Serial.print("\t");
  Serial.print("D");
  Serial.println(d);
  a=a++;
  }
  if (pulsante_b==HIGH){
  Serial.print("B");
  Serial.println(b);
  Serial.print("A");
  Serial.print(a);
  Serial.print("\t");
  Serial.print("C");
  Serial.print(c);
  Serial.print("\t");
  Serial.print("D");
  Serial.println(d);
  b=b++;
  }
  if (pulsante_c==HIGH){
  Serial.print("C");
  Serial.println(c);
  Serial.print("B");
  Serial.print(b);
  Serial.print("\t");
  Serial.print("A");
  Serial.print(a);
  Serial.print("\t");
  Serial.print("D");
  Serial.println(d);
  c=c++;
  }
  if (pulsante_d==HIGH){
  Serial.print("D");
  Serial.println(d);
  Serial.print("B");
  Serial.print(b);
  Serial.print("\t");
  Serial.print("C");
  Serial.print(c);
  Serial.print("\t");
  Serial.print("A");
  Serial.println(d);
  d=d++;
  }
  lcd.setCursor(0,1);
  if(a<10){
    lcd.print(a);
    lcd.print("   ");
  }
  if(a>=10&&a<=99){
    lcd.print(a);
    lcd.print("  ");
  }
  if(a>99&&a<=100){
    lcd.print(a);
    lcd.print(" ");
    a=0;
  }
//lcd.setCursor(5,1);
  if(b<10){
    lcd.print(b);
    lcd.print("   ");
  }
  if(b>=10&&b<=99){
    lcd.print(b);
    lcd.print("  ");
  }
  if(b>99&&b<=100){
    lcd.print(b);
    lcd.print(" ");
    b=0;
  }
  if(c<10){
    lcd.print(c);
    lcd.print("   ");
  }
  if(c>=10&&c<=99){
    lcd.print(c);
    lcd.print("  ");
  }
  if(c>99&&a<=100){
    lcd.print(c);
    lcd.print(" ");
    c=0;
  }
  if(d<10){
    lcd.print(d);
    lcd.print("   ");
  }
  if(d>=10&&d<=99){
    lcd.print(d);
    lcd.print("  ");
  }
  if(d>99&&d<=100){
    lcd.print(d);
    lcd.print(" ");
    d=0;
  }
  delay(200);
}
