/********************************************************
  Include libraries
********************************************************/
#include <Arduino.h>
#include <Servo.h>
#include "ArduinoLowPower.h"
#include "RTClib.h"
#include <SdFat.h>
SdFat SD;  //Make SdFat work with standard SD.h sketches

/********************************************************
  Set variables
********************************************************/
int CAS = 1;  //This is the unique # of the device
int lux = 0;
bool doorOpen = true;
char filename[30];  // make a "char" type variable called "filename" [13]
float measuredvbat;
int sleeptime = 60;  //sleep time in seconds (this sets the interval between sensor readings and logging)

/********************************************************
  Setup RTC
********************************************************/
RTC_DS3231 rtc;

/********************************************************
  Setup Servo
********************************************************/
Servo myservo;  // create servo object to control a servo

/********************************************************
  Setup SD Card
********************************************************/
const int chipSelect = 4;
File logfile;  // Create file object