/*
 *LM35 Library by Eugenio Tampieri
 *Key features:
  -Average reading of an LM35 in C and in F
  - Reading of an LM35 in C or in F
This work is licensed under a Creative Commons Attribution-ShareAlike 3.0 Italy License
http://creativecommons.org/licenses/by-sa/3.0/it/
*/
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
float readC (int sensor);
float readF (int sensor);
float readK (int sensor);
float readRankine (int sensor);
float readReaumur (int sensor);
float readN (int sensor);
float readDe (int sensor);
float readRo (int sensor);