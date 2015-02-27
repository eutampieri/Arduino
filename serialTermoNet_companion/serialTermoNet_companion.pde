import processing.serial.*;

import com.onformative.yahooweather.*;
Serial Arduino;
YahooWeather weather;
int updateIntervallMillis = 30000; 

void setup() {
  println(Serial.list());

// Open the port you are using at the rate you want:
Arduino = new Serial(this, Serial.list()[4], 9600);
  size(700, 300);
  fill(0);
  textFont(createFont("Arial", 14));
  // 2442047 = the WOEID of Berlin
  // use this site to find out about your WOEID : http://sigizmund.info/woeidinfo/
  weather = new YahooWeather(this, 12845859, "c", updateIntervallMillis);
  
}

void draw() {
  String intemp=Arduino.readString();
  weather.update();
  int temp=weather.getTemperature();
  Arduino.write(temp);
  background(255);
  text("City: "+weather.getCityName()+"; Region: "+weather.getRegionName()+"; Country: "+weather.getCountryName()+"; Last updated: "+weather.getLastUpdated(), 20, 20);
  text("Lon: "+weather.getLongitude()+" Lat: "+weather.getLatitude(), 20, 40);
  text("Temp: "+weather.getTemperature()+" WindSpeed: "+weather.getWindSpeed()+" WindDirection: "+weather.getWindDirection(), 20, 60);
  text("Humidity: "+weather.getHumidity()+" visibility: "+weather.getVisibleDistance()+" pressure: "+weather.getPressure()+" rising: "+weather.getRising(), 20, 80);
  text("Sunrise: "+weather.getSunrise()+" sunset: "+weather.getSunset(), 20, 100);
//  text("\n\n\n\n\n\n");
  text("Temperatura interna: "+intemp, 20, 120);
  delay(2000);
}

public void keyPressed() {
  if (key == 'i') {
    weather.setWOEID(12845859);
  }
  if (key == 'r') {
    weather.setWOEID(44418);
  }
}
