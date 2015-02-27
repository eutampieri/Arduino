int cambio=0;
boolean uno=0;
boolean due=0;
boolean tre=0;
boolean quattro=0;
boolean cinque=0;
boolean sei=0;
boolean sette=0;
boolean otto=0;
boolean nove=0;
boolean dieci=0;
boolean undici=0;
boolean dodici=0;
boolean tredici=0;
boolean quattordici=0;
boolean quindici=0;
boolean sedici=0;
boolean diciassette=0;
boolean diciotto=0;
boolean diciannove=0;
boolean venti=0;
boolean ventuno=0;
boolean ventidue=0;
boolean ventitre=0;
boolean ventiquattro=0;
boolean venticinque=0;
boolean ventisei=0;
boolean ventisette=0;
boolean ventotto=0;
boolean ventinove=0;
boolean trenta=0;
boolean trentuno=0;
boolean trentadue=0;
boolean trentatre=0;
boolean trentaquattro=0;
boolean trentacinque=0;
boolean trentasei=0;
boolean trentasette=0;
boolean trentotto=0;
boolean trentanove=0;
boolean quaranta=0;
boolean quarantuno=0;
boolean quarantadue=0;
boolean quarantatre=0;
boolean quarantaquattro=0;
boolean quarantacinque=0;
boolean quarantasei=0;
boolean quarantasette=0;
boolean quarantotto=0;
boolean quarantanove=0;
boolean cinquanta=0;
boolean cinquantuno=0;
boolean cinquantadue=0;
boolean cinquantatre=0;
boolean cinquantaquattro=0;
boolean cinquantacinque=0;
boolean cinquantasei=0;
boolean cinquantasette=0;
boolean cinquantotto=0;
boolean cinquantanove=0;
boolean sessanta =false;
boolean sessantuno=0;
boolean sessantadue=0;
boolean sessantatre=0;
boolean sessantaquattro=0;
boolean sessantacinque=0;
boolean sessantasei=0;
boolean sessantasette=0;
boolean sessantotto=0;
boolean sessantanove=0;
boolean settanta=0;
boolean settantuno=0;
boolean settantadue=0;
boolean settantatre=0;
boolean settantaquattro=0;
boolean settantacinque=0;
boolean settantasei=0;
boolean settantasette=0;
boolean settantotto=0;
boolean settantanove=0;
boolean ottanta=0;
boolean ottantuno=0;
boolean ottantadue=0;
boolean ottantatre=0;
boolean ottantaquattro=0;
boolean ottantacinque=0;
boolean ottantasei=0;
boolean ottantasette=0;
boolean ottantotto=0;
boolean ottantanove=0;
boolean novanta=0;
int i=1;
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 6, 5, 4, 3);
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main ();
void setup(){
  pinMode(2,INPUT);
  pinMode(13,OUTPUT);
   lcd.begin(16, 2);
  lcd.print("Tombola!      ET");
  Serial.begin(9600);
}
void loop(){
  digitalWrite(13,LOW);
  cambio = digitalRead(9);
  digitalWrite(13,LOW);
  if (cambio==HIGH){
    Serial.print(i);
    Serial.println("Pulsante premuto");
    int number;
    number = rand()%90;
    Serial.println(number);
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print(number);
    if(number==1){
      if (uno==1){
        delay(1);
      }
      else {
        lcd.print(number);
        uno=1;
      }
    }
    if(number==2){
    if (due==1){
      delay(1);
    }
    else{
      lcd.print(number);
      due=1;
    }
  }
  if(number==3){
    if (tre==1){
      delay(1);
    }
    else{
      lcd.print(number);
      tre=1;
    }
  }
  if(number==4){
    if (quattro==1){
      delay(1);
    }
     else{
        lcd.print(number);
        quattro=1;
      }
  }
  else if(number==5){
    if (cinque==1){
      delay(1);
    }
     else {
        lcd.print(number);
        cinque=1;
      }
  }
 else if(number==6){
    if (sei==1){
      delay(1);
    }
     else if (sei=0){
        lcd.print(number);
        sei=1;
      }
      else{
        lcd.print("Tombola finita");
      }
  }
  else if(number==7){
    if (sette==1){
      delay(1);
    }
     else if (sette=0){
        lcd.print(number);
        sette=1;
      }
      else{
        lcd.print("Tombola finita");
      }
  }
  else if(number==8){
    if (otto==1){
      delay(1);
    }
     else if (otto=0){
        lcd.print(number);
        otto=1;
      }
      else{
        lcd.print("Tombola finita");
      }
  }
  else if(number==9){
    if (nove==1){
      delay(1);
    }
     else if (nove=0){
        lcd.print(number);
        nove=1;
      }
      else{
        lcd.print("Tombola finita");
      }
  }
  else if(number==10){
    if (dieci==1){
      delay(1);
    }
     else if (dieci=0){
        lcd.print(number);
        dieci=1;
      }
      else{
        lcd.print("Tombola finita");
      }
  }
  else if(number==11){
    if (undici==1){
      delay(1);
    }
     else if (undici=0){
        lcd.print(number);
        undici=1;
      }
      else{
        lcd.print("Tombola finita");
      }
}
else if(number==12){
    if (dodici==1){
      delay(1);
    }
     else if (dodici=0){
        lcd.print(number);
        dodici=1;
      }
      else{
        lcd.print("Tombola finita");
      }
  }
  else if(number==13){
    if (tredici==1){
      delay(1);
    }
     else if (tredici=0){
        lcd.print(number);
        tredici=1;
      }
      else{
        lcd.print("Tombola finita");
      }
  }
  else if(number==14){
    if (quattordici==1){
      delay(1);
    }
     else if (quattordici=0){
        lcd.print(number);
        quattordici=1;
      }
      else{
        lcd.print("Tombola finita");
      }
  }
  else if(number==15){
    if (quindici==1){
      delay(1);
    }
     else if (quindici=0){
        lcd.print(number);
        quindici=1;
      }
      else{
        lcd.print("Tombola finita");
      }
  }
  else if(number==16){
    if (sedici==1){
      delay(1);
    }
     else if (sedici=0){
        lcd.print(number);
        sedici=1;
      }
      }
  else if(number==17){
    if (diciassette==1){
      delay(1);
    }
     else if (diciassette=0){
        lcd.print(number);
        diciassette=1;
     }
  }
  else if(number==18){
    if (diciotto==1){
      delay(1);
    }
     else if (diciotto=0){
        lcd.print(number);
        diciotto=1;
      }
  }
  else if(number==19){
    if (diciannove==1){
      delay(1);
    }
     else if (diciannove=0){
        lcd.print(number);
        diciannove=1;
      }
  }
  else if(number==20){
    if (venti==1){
      delay(1);
    }
     else if (venti=0){
        lcd.print(number);
        venti=1;
      }
  }
  else if(number==21){
    if (ventuno==1){
      delay(1);
    }
     else if (ventuno=0){
        lcd.print(number);
        ventuno=1;
      }
  }
  else if(number==22){
    if (ventidue==1){
      delay(1);
    }
     else if (ventidue=0){
        lcd.print(number);
        ventidue=1;
      }
  }
  else if(number==23){
    if (ventiquattro==1){
      delay(1);
    }
     else if (ventiquattro=0){
        lcd.print(number);
        ventiquattro=1;
      }
  }
  else if(number==25){
    if (venticinque==1){
      delay(1);
    }
     else if (venticinque=0){
        lcd.print(number);
        venticinque=1;
      }
  }
  else if(number==26){
    if (ventisei==1){
      delay(1);
    }
     else if (ventisei=0){
        lcd.print(number);
        ventisei=1;
      }
  }
  else if(number==27){
    if (ventisette==1){
      delay(1);
    }
     else if (ventisette=0){
        lcd.print(number);
        ventisette=1;
      }
  }
  else if(number==28){
    if (ventotto==1){
      delay(1);
    }
     else if (ventotto=0){
        lcd.print(number);
        ventotto=1;
      }
  }
  else if(number==29){
    if (ventinove==1){
      delay(1);
    }
     else if (ventinove=0){
        lcd.print(number);
        ventinove=1;
      }
  }
  else if(number==30){
    if (trenta==1){
      delay(1);
    }
     else if (trenta=0){
        lcd.print(number);
        trenta=1;
      }
  }
  else if(number==31){
    if (trentuno==1){
      delay(1);
    }
     else if (trentuno=0){
        lcd.print(number);
        trentuno=1;
      }
  }
  else if(number==32){
    if (trentadue==1){
      delay(1);
    }
     else if (trentadue=0){
        lcd.print(number);
        trentadue=1;
      }
  }
  else if(number==33){
    if (trentatre==1){
      delay(1);
    }
     else if (trentatre=0){
        lcd.print(number);
        trentatre=1;
      }
  }
  else if(number==34){
    if (trentaquattro==1){
      delay(1);
    }
     else if (trentaquattro=0){
        lcd.print(number);
        trentaquattro=1;
      }
  }
  else if(number==35){
    if (trentacinque==1){
      delay(1);
    }
     else if (trentacinque=0){
        lcd.print(number);
        trentacinque=1;
      }
  }
  else if(number==36){
    if (trentasei==1){
      delay(1);
    }
     else if (trentasei=0){
        lcd.print(number);
        trentasei=1;
      }
  }
  else if(number==37){
    if (trentasette==1){
      delay(1);
    }
     else if (trentasette=0){
        lcd.print(number);
        trentasette=1;
      }
  }
  else if(number==38){
    if (trentotto==1){
      delay(1);
    }
     else if (trentotto=0){
        lcd.print(number);
        trentotto=1;
      }
  }
  else if(number==39){
    if (trentanove==1){
      delay(1);
    }
     else if (trentanove=0){
        lcd.print(number);
        trentanove=1;
      }
  }
  else if(number==40){
    if (quaranta==1){
      delay(1);
    }
     else if (quaranta=0){
        lcd.print(number);
        quaranta=1;
      }
  }
    else if(number==41){
    if (quarantuno==1){
      delay(1);
    }
     else if (quarantuno=0){
        lcd.print(number);
        quarantuno=1;
      }
  }
    else if(number==42){
    if (quarantadue==1){
      delay(1);
    }
     else if (quarantadue=0){
        lcd.print(number);
        quarantadue=1;
      }
  }
    else if(number==43){
    if (quarantatre==1){
      delay(1);
    }
     else if (quarantatre=0){
        lcd.print(number);
        quarantatre=1;
      }
  }
    else if(number==44){
    if (quarantaquattro==1){
      delay(1);
    }
     else if (quarantaquattro=0){
        lcd.print(number);
        quarantaquattro=1;
      }
  }
    else if(number==45){
    if (quarantacinque==1){
      delay(1);
    }
     else if (quarantacinque=0){
        lcd.print(number);
        quarantacinque=1;
      }
  }
    else if(number==46){
    if (quarantasei==1){
      delay(1);
    }
     else if (quarantasei=0){
        lcd.print(number);
        quarantasei=1;
      }
  }
    else if(number==47){
    if (quarantasette==1){
      delay(1);
    }
     else if (quarantasette=0){
        lcd.print(number);
        quarantasette=1;
      }
  }
    else if(number==48){
    if (quarantotto==1){
      delay(1);
    }
     else if (quarantotto=0){
        lcd.print(number);
        quarantotto=1;
      }
  }
    else if(number==49){
    if (quarantanove==1){
      delay(1);
    }
     else if (quarantanove=0){
        lcd.print(number);
        quarantanove=1;
      }
  }
    else if(number==50){
    if (cinquanta==1){
      delay(1);
    }
     else if (cinquanta=0){
        lcd.print(number);
        cinquanta=1;
      }
  }
      else if(number==51){
    if (cinquantuno==1){
      delay(1);
    }
     else if (cinquantuno=0){
        lcd.print(number);
        cinquantuno=1;
      }
  }
      else if(number==52){
    if (cinquantadue==1){
      delay(1);
    }
     else if (cinquantadue=0){
        lcd.print(number);
        cinquantadue=1;
      }
  }
      else if(number==53){
    if (cinquantatre==1){
      delay(1);
    }
     else if (cinquantatre=0){
        lcd.print(number);
        cinquantatre=1;
      }
  }
      else if(number==54){
    if (cinquantaquattro==1){
      delay(1);
    }
     else if (cinquantaquattro=0){
        lcd.print(number);
        cinquantaquattro=1;
      }
  }
      else if(number==55){
    if (cinquantacinque==1){
      delay(1);
    }
     else if (cinquantacinque=0){
        lcd.print(number);
        cinquantacinque=1;
      }
  }
      else if(number==56){
    if (cinquantasei==1){
      delay(1);
    }
     else if (cinquantasei=0){
        lcd.print(number);
        cinquantasei=1;
      }
  }
      else if(number==57){
    if (cinquantasette==1){
      delay(1);
    }
     else if (cinquantasette=0){
        lcd.print(number);
        cinquantasette=1;
      }
  }
      else if(number==58){
    if (cinquantotto==1){
      delay(1);
    }
     else if (cinquantotto=0){
        lcd.print(number);
        cinquantotto=1;
      }
  }
      else if(number==59){
    if (cinquantanove==1){
      delay(1);
    }
     else if (cinquantanove=0){
        lcd.print(number);
        cinquantanove=1;
      }
  }
      else if(number==60){
    if (sessanta==1){
      delay(1);
    }
     else if (sessanta=0){
        lcd.print(number);
        sessanta=1;
      }
  }
  else if(number==61){
    if (sessantuno==1){
      delay(1);
    }
     else if (sessantuno=0){
        lcd.print(number);
        sessantuno=1;
      }
  }
  else if(number==62){
    if (sessantadue==1){
      delay(1);
    }
     else if (sessantadue=0){
        lcd.print(number);
        sessantadue=1;
      }
  }
  else if(number==63){
    if (sessantatre==1){
      delay(1);
    }
     else if (sessantatre=0){
        lcd.print(number);
        sessantatre=1;
      }
  }
  else if(number==64){
    if (sessantaquattro==1){
      delay(1);
    }
     else if (sessantaquattro=0){
        lcd.print(number);
        sessantaquattro=1;
      }
  }
  else if(number==65){
    if (sessantacinque==1){
      delay(1);
    }
     else if (sessantacinque=0){
        lcd.print(number);
        sessantacinque=1;
      }
  }
  else if(number==66){
    if (sessantasei==1){
      delay(1);
    }
     else if (sessantasei=0){
        lcd.print(number);
        sessantasei=1;
      }
  }
  else if(number==67){
    if (sessantasette==1){
      delay(1);
    }
     else if (sessantasette=0){
        lcd.print(number);
        sessantasette=1;
      }
  }
  else if(number==68){
    if (sessantotto==1){
      delay(1);
    }
     else if (sessantotto=0){
        lcd.print(number);
        sessantotto=1;
      }
  }
  if(number==69){
    if (sessantanove==1){
      delay(1);
    }
     else if (sessantanove=0){
        lcd.print(number);
        sessantanove=1;
      }
  }
  if(number==70){
    if (settanta==1){
      delay(1);
    }
     else if (settanta=0){
        lcd.print(number);
        settanta=1;
      }
  }
  if(number==71){
    if (settantuno==1){
      delay(1);
    }
     else if (settantuno=0){
        lcd.print(number);
        settantuno=1;
      }
  }
  if(number==72){
    if (settantadue==1){
      delay(1);
    }
     else if (settantadue=0){
        lcd.print(number);
        settantadue=1;
      }
  }
  delay(1000);
      if (i==3){
        delay(1);
       lcd.print("Tombola finita");
      }
      i=i+1;
  }
  else{
  delay(1);

  }
  }
