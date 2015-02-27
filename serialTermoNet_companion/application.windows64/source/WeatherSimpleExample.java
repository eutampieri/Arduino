import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 
import com.onformative.yahooweather.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class WeatherSimpleExample extends PApplet {




Serial Arduino;
YahooWeather weather;
int updateIntervallMillis = 30000; 

public void setup() {
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

public void draw() {
  weather.update();
  int temp=weather.getTemperature();
  Arduino.write(temp);
  background(255);
  text("City: "+weather.getCityName()+"; Region: "+weather.getRegionName()+"; Country: "+weather.getCountryName()+"; Last updated: "+weather.getLastUpdated(), 20, 20);
  text("Lon: "+weather.getLongitude()+" Lat: "+weather.getLatitude(), 20, 40);
  text("Temp: "+weather.getTemperature()+" WindSpeed: "+weather.getWindSpeed()+" WindDirection: "+weather.getWindDirection(), 20, 60);
  text("Humidity: "+weather.getHumidity()+" visibility: "+weather.getVisibleDistance()+" pressure: "+weather.getPressure()+" rising: "+weather.getRising(), 20, 80);
  text("Sunrise: "+weather.getSunrise()+" sunset: "+weather.getSunset(), 20, 100);
}

public void keyPressed() {
  if (key == 'i') {
    weather.setWOEID(12845859);
  }
  if (key == 'r') {
    weather.setWOEID(44418);
  }
}
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "--full-screen", "--bgcolor=#666666", "--stop-color=#cccccc", "WeatherSimpleExample" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
