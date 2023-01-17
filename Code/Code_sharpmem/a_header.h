//INCLUDE LIBRARIES
#include <Servo.h>
#include <Wire.h>
//#include <RTCZero.h>
#include "RTClib.h"
#include "ArduinoLowPower.h"
//#include <sleep.h>
#include <SPI.h>
#include <SdFat.h>
SdFat SD; //Make SdFat work with standard SD.h sketches
#include <Adafruit_GFX.h>
#include <TimeLib.h> //include the Arduino Time library
#include <FlashStorage.h>
#include "Adafruit_FreeTouch.h"
#include <Adafruit_SharpMem.h>


/********************************************************
  Set up pins for the screen
********************************************************/
#define SHARP_SCK  5
#define SHARP_MOSI A4
#define SHARP_SS   6

#define VBATPIN A7
#define cardSelect 4

Adafruit_SharpMem display(SHARP_SCK, SHARP_MOSI, SHARP_SS, 144, 168);
#define BLACK 0
#define WHITE 1

/********************************************************
  Initialize variables
********************************************************/
int opentime = 10000; // changed from 20s to 60s // from 60s to 120s// to 5 mins
unsigned long rightstart;
unsigned long leftstart;
int offset = 0;
int tolerance = 5;
int currentpos = 0;
int leftPokeCount = 0;
int rightPokeCount = 0;
int leftPokeDur = 0;
int rightPokeDur = 0;
int leftFeederCount = 0;
int rightFeederCount = 0;
int leftFeederDur = 0;
int rightFeederDur = 0;
int inputtriggered = 0;
float measuredvbat;

/********************************************************
  Initialize servo
********************************************************/
Servo myservo;

/********************************************************
  Initialize RTC
********************************************************/

//RTCZero rtc;
RTC_DS3231 rtc; 
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

/********************************************************
  Set up datafile
********************************************************/
File logfile;         // Create file object
File configfile;
char filename[26];    // Array for file name data logged to named in setup
