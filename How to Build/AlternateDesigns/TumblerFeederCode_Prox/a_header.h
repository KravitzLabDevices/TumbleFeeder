/*****************************************************************
 * TUMBLER FEEDER - HEADER FILE
 * 
 * This header file contains all library includes, pin definitions,
 * global variables, and object initializations for the Tumbler Feeder
 * with proximity detection system.
 * 
 * Hardware components:
 * - Adafruit Feather M0 or similar
 * - Sharp Memory Display (144x168)
 * - VL6180X Time-of-Flight Proximity Sensor
 * - DS3231 Real-Time Clock
 * - Servo motor for food hopper control
 * - SD card for data logging
 * - Capacitive touch buttons (red, green, blue)
 *****************************************************************/

/********************************************************
  LIBRARY INCLUDES
********************************************************/
#include <Servo.h>                    // Servo motor control for feeder mechanism
#include <Wire.h>                     // I2C communication for sensors
#include "RTClib.h"                   // Real-time clock library
#include "ArduinoLowPower.h"          // Low power sleep modes
#include <SPI.h>                      // SPI communication
#include <SdFat.h>                    // SD card file system
SdFat SD;                             // Make SdFat work with standard SD.h sketches
#include <Adafruit_GFX.h>             // Graphics library for display
#include <TimeLib.h>                  // Time manipulation library
#include <FlashStorage.h>             // Non-volatile storage
#include "Adafruit_FreeTouch.h"       // Capacitive touch sensing
#include <Adafruit_SharpMem.h>        // Sharp Memory Display driver
#include "Adafruit_VL6180X.h"         // Proximity sensor driver


/********************************************************
  PIN DEFINITIONS
********************************************************/
#define SHARP_SCK 5                   // Sharp display SPI clock pin
#define SHARP_MOSI A4                 // Sharp display SPI data pin
#define SHARP_SS 6                    // Sharp display SPI chip select pin
#define VBATPIN A7                    // Battery voltage monitoring pin
#define cardSelect 4                  // SD card chip select pin

// Hardware connections (not #defined):
// Pin 10: Servo motor signal
// Pin 13: MOSFET control / LED / Piezo beeper
// Pin A0: Spare input (pull-up enabled)
// Pin A1: Feeder touch sensor (pull-up, interrupt-enabled)
// Pin A2: Mouse detection sensor (pull-up)
// Pin A3: Red capacitive touch button (pull-up, interrupt-enabled)
// Pin 1:  Green capacitive touch button (pull-up)
// Pin A5: Blue capacitive touch button (pull-up)

/********************************************************
  DISPLAY SETUP
********************************************************/
// Initialize Sharp Memory Display (144 pixels wide x 168 pixels tall)
Adafruit_SharpMem display(SHARP_SCK, SHARP_MOSI, SHARP_SS, 144, 168);
#define BLACK 0                       // Black pixel value
#define WHITE 1                       // White pixel value (actually the background)

/********************************************************
  BEHAVIORAL EXPERIMENT VARIABLES
********************************************************/
// Event counters
int ApproachCount = 0;                // Number of times mouse approached feeder
int FeederCount = 0;                  // Number of feeding events/touches
int FeederDur = 0;                    // Duration of last feeder touch (milliseconds)

// Proximity requirements
int ProxRequirement = 1;              // How many seconds mouse must stay near feeder (1-10)

// Session control
bool SessionStarted = false;          // Flag indicating if experiment session has started
int inputtriggered = 0;               // Flag for input detection

/********************************************************
  DISPLAY UPDATE TIMING
********************************************************/
const unsigned long display_interval = 100;  // Display refresh interval (milliseconds)
unsigned long next_interval = 0;             // Next scheduled display update time

/********************************************************
  SERVO POSITION SETTINGS
********************************************************/
int closedpos = 150;                  // Servo angle when feeder is closed (degrees)
int openpos = 0;                      // Servo angle when feeder is open (degrees)

/********************************************************
  FEEDING PARAMETERS
********************************************************/
unsigned long open_duration = 60;     // How long feeder stays open (seconds)
int CSL = 0;                          // Device number / ID (0-19)
bool mode = 0;                        // Feeding mode: 0=Proximity, 1=Free feeding
unsigned int wake_counter = 0;        // Counter for periodic wake events

/********************************************************
  TIME SCHEDULING (CURRENTLY UNUSED)
********************************************************/
int on_hour = 0;                      // Hour to activate device (for future use)
int off_hour = 0;                     // Hour to deactivate device (for future use)

/********************************************************
  SENSOR STATE FLAGS
********************************************************/
int mouse_detected = 0;               // Flag: 1=mouse detected by proximity sensor
int feed_touch = 0;                   // Flag: 1=feeder rod touched by mouse

/********************************************************
  USER INTERFACE VARIABLES
********************************************************/
// Capacitive touch button states (LOW=pressed, HIGH=not pressed)
bool red_touch = digitalRead(A3);     // Red button state
bool green_touch = digitalRead(1);    // Green button state  
bool blue_touch = digitalRead(A5);    // Blue button state

// Menu navigation
unsigned long menustart = 0;          // Timestamp for menu timeout/blink timing
bool endstate = false;                // Flag to exit menu loops

/********************************************************
  POWER MONITORING
********************************************************/
float measuredvbat = 0.0;             // Current battery voltage

/********************************************************
  HARDWARE OBJECT INITIALIZATIONS
********************************************************/
// Servo motor
Servo myservo;                        // Servo object for feeder mechanism

// Real-Time Clock
RTC_DS3231 rtc;                       // DS3231 RTC object
char daysOfTheWeek[7][12] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

// Proximity Sensor
Adafruit_VL6180X vl = Adafruit_VL6180X();  // VL6180X Time-of-Flight sensor object

/********************************************************
  SD CARD DATA LOGGING
********************************************************/
File logfile;                         // Data log file object
File configfile;                      // Configuration file object
char filename[26];                    // Filename buffer for data files (format: CASTLE_###_MMDDYY_##.CSV)
