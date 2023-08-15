//INCLUDE LIBRARIES
#include <Servo.h>
#include <Wire.h>
#include "RTClib.h"
#include "ArduinoLowPower.h"
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

/********************************************************
  Set up screen
********************************************************/
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

bool SessionStarted = false;
const unsigned long display_interval = 100;
unsigned long next_interval = 0;
int middlepos ;
int leftpos ;
int fromsd;
int CSL;
int count_pos = 0; // 0 initialize count_pos here for switching between l,r,m using %
unsigned long open_interval;
int left_touch;
int right_touch;
int start_touch;
int feed_touch;
boolean buttonLow = false;
boolean freefeed;
unsigned int wake_counter = 0;
int on_hour;
int off_hour;
boolean open_now = true;
int margin = 10;

/********************************************************
  Initialize servo
********************************************************/
Servo myservo;

/********************************************************
  Initialize RTC
********************************************************/
RTC_DS3231 rtc; 
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

/********************************************************
  Set up datafile
********************************************************/
File logfile;         // Create file object
File configfile;
char filename[26];    // Array for file name data logged to named in setup
