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
#include <Adafruit_SH110X.h>


/*date time*/

/********************************************************
  Feather pins being used
********************************************************/
#define BUTTON_A  9
#define BUTTON_B  6
#define BUTTON_C  5
#define VBATPIN A7
#define cardSelect 4

/********************************************************
  Set up cap touch sensing
********************************************************/
//Adafruit_FreeTouch qt_0 = Adafruit_FreeTouch(A0, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
//Adafruit_FreeTouch qt_1 = Adafruit_FreeTouch(A1, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
//Adafruit_FreeTouch qt_2 = Adafruit_FreeTouch(A2, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
//Adafruit_FreeTouch qt_3 = Adafruit_FreeTouch(A3, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);


Adafruit_FreeTouch qt_0 = Adafruit_FreeTouch(A2, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_1 = Adafruit_FreeTouch(A3, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_2 = Adafruit_FreeTouch(A0, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_3 = Adafruit_FreeTouch(A1, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);




/********************************************************
  Initialize variables
********************************************************/
int opentime = 20000;
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
  Set up OLED screen
********************************************************/
Adafruit_SH1107 display = Adafruit_SH1107(64, 128, &Wire);

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
