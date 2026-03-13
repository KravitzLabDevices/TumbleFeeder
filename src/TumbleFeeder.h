/*
  TumbleFeeder.h - Comprehensive library for servo-based pellet feeder
  Designed for behavioral neuroscience experiments
  
  Based on FED3 architecture by Lex Kravitz
  Adapted for TumbleFeeder by Mason Barrett, Kravitz Lab
  
  Hardware configuration (hardcoded):
  - Servo: Pin 10
  - LED indicator: Pin 13
  - Left touch input: A2
  - Right touch input: A0
  - Feeder touch input: A1
  - Sharp Memory Display: SCK=5, MOSI=A4, SS=6
  - SD Card: CS=4
  - Battery monitor: A7
*/

#ifndef TumbleFeeder_h
#define TumbleFeeder_h

#include "Arduino.h"
#include <Servo.h>
#include <Wire.h>
#include "RTClib.h"
#include "ArduinoLowPower.h"
#include <SPI.h>
#include <SdFat.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SharpMem.h>

// Pin definitions
#define SERVO_PIN       10
#define LED_PIN         13
#define LEFT_TOUCH_PIN  A2
#define RIGHT_TOUCH_PIN A0
#define FEEDER_TOUCH_PIN A1
#define SHARP_SCK       5
#define SHARP_MOSI      A4
#define SHARP_SS        6
#define VBATPIN         A7
#define cardSelect      4

// Additional button pins for menu
#define RED_BUTTON      A3
#define GREEN_BUTTON    1
#define BLUE_BUTTON     A5

#define BLACK 0
#define WHITE 1

class TumbleFeeder {
  public:
    // Constructor
    TumbleFeeder();
    
    // Main methods
    void begin();           // Initialize everything
    void run();             // Call this in loop() - handles everything
    
    // Configuration (can be called before begin() or will use defaults)
    void setFR(int fr);
    void setOpenDuration(unsigned long seconds);
    void setPositions(int openPos, int closedPos);
    void setDeviceNumber(int deviceNum);
    void setMode(int mode);  // 0 = FR mode, 1 = Free feeding
    
    // Manual feeder control (optional - normally handled by run())
    void feederOpen();
    void feederClose();
    void shakeFood();
    void shake();
    
    // Public counters (read-only, updated by library)
    int leftPokeCount;
    int rightPokeCount;
    int FeederCount;
    int leftPokeDur;
    int rightPokeDur;
    int leftFeederDur;
    
    // Public configuration variables
    int FR;
    int mode;  // 0 = FR, 1 = Free feeding
    int deviceNumber;
    int closedpos;
    int openpos;
    unsigned long open_duration;
    
    // Display and SD objects (public for advanced users)
    Adafruit_SharpMem display = Adafruit_SharpMem(SHARP_SCK, SHARP_MOSI, SHARP_SS, 144, 168);
    SdFat SD;
    File logfile;
    File configfile;
    char filename[26];
    
    // RTC
    RTC_DS3231 rtc;
    
    // Battery
    float measuredvbat;
    
    // Sleep control
    void enableSleep();
    void disableSleep();
    
    // Reset counters
    void resetCounts();
    
  private:
    // Servo object
    Servo _servo;
    
    // Touch flags (set by interrupts)
    volatile bool _leftTouch;
    volatile bool _rightTouch;
    volatile bool _feedTouch;
    
    // Menu/button reading
    bool _redTouch;
    bool _greenTouch;
    bool _blueTouch;
    void _readButtons();
    
    // Session state
    bool _SessionStarted;
    unsigned long _menustart;
    bool _endstate;
    unsigned long _next_interval;
    const unsigned long _display_interval = 100;
    unsigned int _wake_counter;
    
    // Sleep management
    bool _EnableSleep;
    void _goToSleep();
    
    // Interrupt handlers (static for ISR compatibility)
    static TumbleFeeder* _instance;
    static void _leftISR();
    static void _rightISR();
    static void _feedISR();
    static void _wakeISR();
    
    // Touch handling methods
    void _handleLeftTouch();
    void _handleRightTouch();
    void _handleFeederTouch();
    void _checkLeft();
    void _checkRight();
    void _checkFeeder();
    void _checkInputs();
    void _freeInputs();
    void _freeTerminateInputs();
    void _readTouchPin(int pin, unsigned long &startTime, int &count, int &duration);
    
    // Display methods
    void _updateDisplay();
    void _displayCurrentParams();
    void _displayMouse();
    void _displayBattery();
    void _displaySDError();
    void _readBatteryLevel();
    
    // Menu methods
    void _programSelect();
    void _startupMenu();
    void _setFeedParadigm();
    void _settingFR();
    void _settingDeviceNum();
    void _settingOpenDuration();
    void _settingOpenPosition();
    void _settingClosedPosition();
    
    // SD/Logging methods
    void _createFile();
    void _createPos();
    void _logData();
    void _writeToSD();
    void _writeConfigFile();
    void _getFilename(char *filename);
    static void _dateTime(uint16_t* date, uint16_t* time);
    void _error(uint8_t errno);
    
    // Stimuli/feedback
    void _blink(byte PIN, byte DELAY_MS, byte loops);
    void _beep();
};

#endif
