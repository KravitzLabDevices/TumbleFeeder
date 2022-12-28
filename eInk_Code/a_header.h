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
#include "Adafruit_FreeTouch.h"
#include "Adafruit_ThinkInk.h"

//eInk setup
#define EPD_DC      10 // can be any pin, but required!
#define EPD_CS      9  // can be any pin, but required!
#define EPD_BUSY    -1  // can set to -1 to not use a pin (will wait a fixed delay)
#define SRAM_CS     6  // can set to -1 to not use a pin (uses a lot of RAM!)
#define EPD_RESET   -1  // can set to -1 and share with chip Reset (can't deep sleep)
// 2.9" Grayscale Featherwing or Breakout:
ThinkInk_290_Grayscale4_T5 display(EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY);
#define COLOR1 EPD_BLACK
#define COLOR2 EPD_LIGHT
#define COLOR3 EPD_DARK

/********************************************************
  Feather pins being used
********************************************************/
#define BUTTON_A  11
#define BUTTON_B  12
#define BUTTON_C  13
#define VBATPIN A7
#define cardSelect 4

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
int opentime = 60000; // changed from 20s to 60s
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
const unsigned long display_interval = 100;
unsigned long next_interval = 0;
int middlepos;
int leftpos;
int rightpos;
int fromsd;
int CSL;
int count_pos = 0;  // initialize count_pos here for switching between l,r,m using %
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

int right_b_pulse = 12; // right // 12 // 10 for device 03fa
int left_b_pulse = 10; // left change from 12 to 10  // 11 for device 03fa
bool left_feed_flag = false;
bool right_feed_flag = false;
bool first_touch = false;

int set_pos;
int C_lastButtonState = HIGH;
int C_currentButtonState = HIGH;
unsigned long C_lastDebounceTime = 0;
unsigned long C_debounceDelay = 50;
int nums = 0;
int dnums = 0;

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