/*
* LM35
* A library which reads an LM35 thermometer
This work is licensed under a Creative Commons Attribution-ShareAlike 3.0 Italy License
http://creativecommons.org/licenses/by-sa/3.0/it/
*/
/*
	Unità di misura
	°F = (9/5 × °C) + 32
	K = celsius + 273.15
	°R = celsius*1.8+32+459.67 (Rankine)
	°r = celsius*0.8 (reaumur)
	°N = celsius*(33.0/100.0)
	°De = (100 − celsius) * 3.0/2.0
	°Rø = celsius*21.0/40.0+7.5
*/
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
float readC (int sensor){
	float reading=analogRead(sensor);
	float celsius=(reading/1023*5.0-.5)*100;
	return celsius;
}
float readF (int sensor){
	float reading=analogRead(sensor);
	float celsius=(reading/1023*5.0-.5)*100;
	float f= (9.0/5.0*celsius) + 32;
	return f;
}
float readK (int sensor){
	float reading=analogRead(sensor);
	float celsius=(reading/1023*5.0-.5)*100;
	float K= celsius + 273.15;
	return K;
}
float readRankine (int sensor){
	float reading=analogRead(sensor);
	float celsius=(reading/1023*5.0-.5)*100;
	float R=celsius*1.8+32+459.67;
	return(R);
}
float readReaumur (int sensor){
	float reading=analogRead(sensor);
	float celsius=(reading/1023*5.0-.5)*100;
	float r=celsius*0.8;
	return(r);
}
float readN (int sensor){
	float reading=analogRead(sensor);
	float celsius=(reading/1023*5.0-.5)*100;
	float N=celsius*(33.0/100.0);
	return(N);
}
float readDe (int sensor){
	float reading=analogRead(sensor);
	float celsius=(reading/1023*5.0-.5)*100;
	float dee=100.0-celsius;
	float de=dee*3.0/2.0;
	return(de);
}
float readRo (int sensor){
	float reading=analogRead(sensor);
	float celsius=(reading/1023*5.0-.5)*100;
	float Ro=celsius*21.0/40.0+7.5;
	return(Ro);
}