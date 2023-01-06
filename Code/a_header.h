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


/*date time*/

/********************************************************
  Feather pins being used
********************************************************/
//#define SHARP_SCK  5
//#define SHARP_MOSI 6
//#define SHARP_SS   9
//
//#define VBATPIN A7
//#define cardSelect 4
//
//Adafruit_SharpMem display(SHARP_SCK, SHARP_MOSI, SHARP_SS, 144, 168);
//#define BLACK 0
//#define WHITE 1
//int minorHalfSize;
/********************************************************
  Set up cap touch sensing
********************************************************/
Adafruit_FreeTouch qt_0 = Adafruit_FreeTouch(A2, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_1 = Adafruit_FreeTouch(A3, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_2 = Adafruit_FreeTouch(A0, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_3 = Adafruit_FreeTouch(A1, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);






/********************************************************
  Initialize variables
********************************************************/
int opentime = 60000; // changed from 20s to 60s // from 60s to 120s// to 5 mins
unsigned long rightstart;
unsigned long leftstart;
int offset = 0;
int tolerance = 5;

// MAYBE WE COULD LET USER SET RIGHT_POS AND LEFT_POS ? 
int home_pos = 442;
//int rightpos = 318;
//int leftpos = 595;
int currentpos = 0;

int touch0 = 0;
int touch1 = 0;
int touch2 = 0;
int touch3 = 0;
int touch0base = 0;
int touch1base = 0;
int touch2base = 0;
int touch3base = 0;

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
