/*
  TumbleFeeder.cpp - Comprehensive library for servo-based pellet feeder
*/

#include "Arduino.h"
#include "TumbleFeeder.h"

// Static member initialization
TumbleFeeder* TumbleFeeder::_instance = nullptr;

/**************************************************************************************************************************************************
                                                                                    Constructor and Initialization
**************************************************************************************************************************************************/

// Constructor
TumbleFeeder::TumbleFeeder() {
  // Initialize counters
  leftPokeCount = 0;
  rightPokeCount = 0;
  FeederCount = 0;
  leftPokeDur = 0;
  rightPokeDur = 0;
  leftFeederDur = 0;
  
  // Initialize touch flags
  _leftTouch = false;
  _rightTouch = false;
  _feedTouch = false;
  
  // Default configuration
  FR = 1;
  mode = 0;  // FR mode
  deviceNumber = 0;
  closedpos = 150;
  openpos = 0;
  open_duration = 60;
  
  // Session state
  _SessionStarted = false;
  _endstate = false;
  _wake_counter = 0;
  _EnableSleep = true;
  
  // Set instance pointer for static ISRs
  _instance = this;
}

// Main initialization
void TumbleFeeder::begin() {
  Serial.begin(9600);
  
  /********************************************************
    Initialize pins
  ********************************************************/
  pinMode(LED_PIN, OUTPUT);
  pinMode(LEFT_TOUCH_PIN, INPUT_PULLUP);
  pinMode(RIGHT_TOUCH_PIN, INPUT_PULLUP);
  pinMode(FEEDER_TOUCH_PIN, INPUT_PULLUP);
  pinMode(RED_BUTTON, INPUT_PULLUP);
  pinMode(GREEN_BUTTON, INPUT_PULLUP);
  pinMode(BLUE_BUTTON, INPUT_PULLUP);
  pinMode(VBATPIN, INPUT);
  
  digitalWrite(LED_PIN, LOW);
  
  /********************************************************
    Initialize RTC
  ********************************************************/
  rtc.begin();
  
  /********************************************************
    Initialize Display
  ********************************************************/
  display.begin();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setRotation(1);
  display.fillRect(0, 0, 168, 144, WHITE);
  display.refresh();
  
  /********************************************************
    Initialize SD Card
  ********************************************************/
  SdFile::dateTimeCallback(_dateTime);
  _createFile();
  _createPos();  // Load saved positions and settings
  
  /********************************************************
    Attach Interrupts
  ********************************************************/
  LowPower.attachInterruptWakeup(digitalPinToInterrupt(LEFT_TOUCH_PIN), _leftISR, FALLING);
  LowPower.attachInterruptWakeup(digitalPinToInterrupt(RIGHT_TOUCH_PIN), _rightISR, FALLING);
  LowPower.attachInterruptWakeup(digitalPinToInterrupt(FEEDER_TOUCH_PIN), _feedISR, FALLING);
  LowPower.attachInterruptWakeup(digitalPinToInterrupt(RED_BUTTON), _wakeISR, CHANGE);
  
  /********************************************************
    Startup Menu
  ********************************************************/
  while (!_SessionStarted) {
    _displayCurrentParams();
  }
  
  // Display is already showing run screen from _displayCurrentParams
  // No need to clear it
  
  Serial.println("TumbleFeeder initialized!");
}

/**************************************************************************************************************************************************
                                                                                    Main Run Loop
**************************************************************************************************************************************************/

void TumbleFeeder::run() {
  // This is called every loop - handles all input checking, display updates, and sleep
  unsigned long current = millis();
  
  // Check inputs at regular intervals
  if (current >= _next_interval) {
    if (mode == 0) {
      // FR mode
      _checkInputs();
    }
    else if (mode == 1) {
      // Free feeding mode
      _freeInputs();
      if (_wake_counter % 180 == 0) {
        shakeFood();
      }
    }
    else if (mode == 2) {
      // FR Extend mode
      _checkInputs();
    }
    else if (mode == 3) {
      // Free Terminate mode
      _freeTerminateInputs();
      if (_wake_counter % 180 == 0) {
        shakeFood();
      }
    }
    
    _next_interval = current + _display_interval;
  }
  
  // Update display
  _updateDisplay();
  
  // Sleep management
  _goToSleep();
  
  _wake_counter++;
}

/**************************************************************************************************************************************************
                                                                                    Static Interrupt Handlers
**************************************************************************************************************************************************/

void TumbleFeeder::_leftISR() {
  if (_instance) {
    _instance->_handleLeftTouch();
  }
}

void TumbleFeeder::_rightISR() {
  if (_instance) {
    _instance->_handleRightTouch();
  }
}

void TumbleFeeder::_feedISR() {
  if (_instance) {
    _instance->_handleFeederTouch();
  }
}

void TumbleFeeder::_wakeISR() {
  // Just wake up - no action needed
}

/**************************************************************************************************************************************************
                                                                                    Touch Handlers
**************************************************************************************************************************************************/

void TumbleFeeder::_handleLeftTouch() {
  _leftTouch = true;
}

void TumbleFeeder::_handleRightTouch() {
  _rightTouch = true;
}

void TumbleFeeder::_handleFeederTouch() {
  _feedTouch = true;
}

// Helper method to read touch duration
void TumbleFeeder::_readTouchPin(int pin, unsigned long &startTime, int &count, int &duration) {
  startTime = millis();
  while (digitalRead(pin) == LOW) {
    delay(1);
  }
  duration = millis() - startTime;
  count++;
}

// Check left poke with FR schedule
void TumbleFeeder::_checkLeft() {
  if (_leftTouch) {
    unsigned long startTime;
    _readTouchPin(LEFT_TOUCH_PIN, startTime, leftPokeCount, leftPokeDur);
    
    _logData();
    
    // Force immediate display update
    static unsigned long lastUpdate = 0;
    lastUpdate = 0;  // Reset timer to force update
    _updateDisplay();
    
    _leftTouch = false;
    leftPokeDur = 0;
    
    // Check if FR condition is met
    if (FR > 0 && leftPokeCount % FR == 0) {
      feederOpen();
      unsigned long openStart = millis();
      unsigned long feedingEnd   = openStart + (open_duration * 1000UL);
      unsigned long extensionEnd = openStart + 30000UL;

      while (true) {
        unsigned long nowMs = millis();
        bool feedDone = (nowMs >= feedingEnd);
        bool extDone  = (nowMs >= extensionEnd);

        if (mode == 2) {
          if (feedDone && extDone) break;
        } else {
          if (feedDone) break;
        }

        if (mode == 2 && _feedTouch) {
          unsigned long startTime;
          _readTouchPin(FEEDER_TOUCH_PIN, startTime, FeederCount, leftFeederDur);
          extensionEnd = millis() + 30000UL;
          _logData();
          _feedTouch = false;
          leftFeederDur = 0;
        } else {
          _checkFeeder();
        }

        // Display timers
        display.fillRect(122, 36, 46, 60, WHITE);
        display.setCursor(122, 48);
        display.println("Feeding");
        long feedRemain = ((long)feedingEnd - (long)millis()) / 1000;
        if (feedRemain < 0) feedRemain = 0;
        display.setCursor(122, 60);
        display.print(feedRemain);

        if (mode == 2) {
          display.setCursor(122, 72);
          display.println("Extensn");
          long extRemain = ((long)extensionEnd - (long)millis()) / 1000;
          if (extRemain < 0) extRemain = 0;
          display.setCursor(122, 84);
          display.print(extRemain);
        }

        display.refresh();
      }

      display.fillRect(122, 36, 46, 60, WHITE);
      feederClose();
      _updateDisplay();
    }
  }
}

// Check right poke (no reward)
void TumbleFeeder::_checkRight() {
  if (_rightTouch) {
    unsigned long startTime;
    _readTouchPin(RIGHT_TOUCH_PIN, startTime, rightPokeCount, rightPokeDur);
    
    _updateDisplay();
    _logData();
    
    _rightTouch = false;
    rightPokeDur = 0;
  }
}

// Check feeder access
void TumbleFeeder::_checkFeeder() {
  if (_feedTouch) {
    unsigned long startTime;
    _readTouchPin(FEEDER_TOUCH_PIN, startTime, FeederCount, leftFeederDur);
    
    _updateDisplay();
    _logData();
    
    _feedTouch = false;
    leftFeederDur = 0;
  }
}

// Check all inputs (FR mode)
void TumbleFeeder::_checkInputs() {
  _checkRight();
  _checkLeft();
  _checkFeeder();
}

// Free feeding mode
void TumbleFeeder::_freeInputs() {
  _checkRight();
  _checkFeeder();
  
  // Left poke in free mode - no feeder opening
  if (_leftTouch) {
    unsigned long startTime;
    _readTouchPin(LEFT_TOUCH_PIN, startTime, leftPokeCount, leftPokeDur);
    
    _updateDisplay();
    _logData();
    
    _leftTouch = false;
    leftPokeDur = 0;
  }
}

// Free Terminate mode - feedtouch closes feeder for 60s then reopens
void TumbleFeeder::_freeTerminateInputs() {
  _checkRight();

  // Left poke - log only, no reward
  if (_leftTouch) {
    unsigned long startTime;
    _readTouchPin(LEFT_TOUCH_PIN, startTime, leftPokeCount, leftPokeDur);
    _updateDisplay();
    _logData();
    _leftTouch = false;
    leftPokeDur = 0;
  }

  // Feedtouch - wait 60s (feeder open), close for 60s, then reopen
  if (_feedTouch) {
    unsigned long startTime;
    _readTouchPin(FEEDER_TOUCH_PIN, startTime, FeederCount, leftFeederDur);
    _logData();
    _updateDisplay();  // Show updated FeederCount immediately
    _feedTouch = false;
    leftFeederDur = 0;

    // Helper lambda to draw countdown overlay after _updateDisplay()
    // Countdown to close (feeder still open)
    unsigned long warningStart = millis();
    while (millis() - warningStart < 60000) {
      bool touched = false;
      if (_rightTouch) {
        _readTouchPin(RIGHT_TOUCH_PIN, startTime, rightPokeCount, rightPokeDur);
        _logData();
        _rightTouch = false;
        rightPokeDur = 0;
        touched = true;
      }
      if (_leftTouch) {
        _readTouchPin(LEFT_TOUCH_PIN, startTime, leftPokeCount, leftPokeDur);
        _logData();
        _leftTouch = false;
        leftPokeDur = 0;
        touched = true;
      }
      if (_feedTouch) {
        _readTouchPin(FEEDER_TOUCH_PIN, startTime, FeederCount, leftFeederDur);
        _logData();
        _feedTouch = false;
        leftFeederDur = 0;
        touched = true;
      }

      if (touched) _updateDisplay();
      long remain = 60 - (long)(millis() - warningStart) / 1000;
      if (remain < 0) remain = 0;
      display.fillRect(122, 36, 46, 36, WHITE);
      display.setCursor(122, 48);
      display.println("Closing");
      display.setCursor(122, 60);
      display.print(remain);
      display.refresh();
    }

    _pendingEvent = "Closing";
    _logData();

    feederClose();

    // Closed period
    unsigned long closeStart = millis();
    while (millis() - closeStart < 60000) {
      bool touched = false;
      if (_rightTouch) {
        _readTouchPin(RIGHT_TOUCH_PIN, startTime, rightPokeCount, rightPokeDur);
        _logData();
        _rightTouch = false;
        rightPokeDur = 0;
        touched = true;
      }
      if (_leftTouch) {
        _readTouchPin(LEFT_TOUCH_PIN, startTime, leftPokeCount, leftPokeDur);
        _logData();
        _leftTouch = false;
        leftPokeDur = 0;
        touched = true;
      }
      if (_feedTouch) {
        _readTouchPin(FEEDER_TOUCH_PIN, startTime, FeederCount, leftFeederDur);
        _logData();
        _feedTouch = false;
        leftFeederDur = 0;
        touched = true;
      }

      if (touched) _updateDisplay();
      long remain = 60 - (long)(millis() - closeStart) / 1000;
      if (remain < 0) remain = 0;
      display.fillRect(122, 36, 46, 36, WHITE);
      display.setCursor(122, 48);
      display.println("Closed");
      display.setCursor(122, 60);
      display.print(remain);
      display.refresh();
    }

    _pendingEvent = "Opening";
    _logData();

    feederOpen();
    display.fillRect(122, 36, 46, 36, WHITE);
    _updateDisplay();
  }
}

/**************************************************************************************************************************************************
                                                                                    Servo Control
**************************************************************************************************************************************************/

void TumbleFeeder::feederOpen() {
  digitalWrite(LED_PIN, HIGH);
  _servo.attach(SERVO_PIN);
  
  for (int pos = closedpos; pos >= openpos; pos -= 1) {
    _servo.write(pos);
    delay(50);
  }
  
  _servo.detach();
  digitalWrite(LED_PIN, LOW);
}

void TumbleFeeder::feederClose() {
  digitalWrite(LED_PIN, HIGH);
  _servo.attach(SERVO_PIN);
  
  for (int pos = openpos; pos <= closedpos; pos += 1) {
    _servo.write(pos);
    delay(50);
  }
  
  _servo.detach();
  digitalWrite(LED_PIN, LOW);
}

void TumbleFeeder::shake() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
    delay(50);
  }
}

void TumbleFeeder::shakeFood() {
  feederClose();
  feederOpen();
  _logData();
}

/**************************************************************************************************************************************************
                                                                                    Configuration Methods
**************************************************************************************************************************************************/

void TumbleFeeder::setFR(int fr) {
  FR = (fr == 0) ? 1 : fr;
}

void TumbleFeeder::setOpenDuration(unsigned long seconds) {
  open_duration = seconds;
}

void TumbleFeeder::setPositions(int openPos, int closedPos) {
  openpos = openPos;
  closedpos = closedPos;
}

void TumbleFeeder::setDeviceNumber(int deviceNum) {
  deviceNumber = deviceNum;
}

void TumbleFeeder::setMode(int m) {
  mode = m;
}

void TumbleFeeder::resetCounts() {
  leftPokeCount = 0;
  rightPokeCount = 0;
  FeederCount = 0;
  leftPokeDur = 0;
  rightPokeDur = 0;
  leftFeederDur = 0;
}

/**************************************************************************************************************************************************
                                                                                    Sleep Management
**************************************************************************************************************************************************/

void TumbleFeeder::enableSleep() {
  _EnableSleep = true;
}

void TumbleFeeder::disableSleep() {
  _EnableSleep = false;
}

void TumbleFeeder::_goToSleep() {
  if (_EnableSleep) {
    LowPower.sleep(5000);
  }
}

/**************************************************************************************************************************************************
                                                                                    Display Methods
**************************************************************************************************************************************************/

void TumbleFeeder::_updateDisplay() {
  // Update display during running session
  if (_SessionStarted) {
    display.fillRect(0, 0, 168, 128, WHITE);
    
    // Title
    display.setCursor(35, 14);
    display.println("Tumble!");
    display.setCursor(36, 14);
    display.println("Tumble!");
    
    // Box around data
    display.drawRect(5, 5, 104, 110, BLACK);
    display.drawRect(2, 2, 110, 116, BLACK);
    
    // Mode and FR
    display.setCursor(12, 30);
    display.print("Mode: ");
    display.setCursor(80, 30);
    if (mode == 0)      display.print("FR");
    else if (mode == 1) display.print("Free");
    else if (mode == 2) display.print("FRxt");
    else if (mode == 3) display.print("FrTm");

    if (mode == 0 || mode == 2) {
      display.setCursor(12, 42);
      display.print("FR: ");
      display.setCursor(80, 42);
      display.print(FR);
    }
    
    display.setCursor(12, 56);
    display.print("Device#: ");
    display.setCursor(80, 56);
    display.print(deviceNumber);
    
    display.drawFastHLine(10, 70, 80, BLACK);
    
    // Counts
    display.setCursor(12, 78);
    display.print("Left: ");
    display.setCursor(80, 78);
    display.print(leftPokeCount);
    
    display.setCursor(12, 90);
    display.print("Right: ");
    display.setCursor(80, 90);
    display.print(rightPokeCount);
    
    display.setCursor(12, 100);
    display.print("Feed: ");
    display.setCursor(80, 100);
    display.print(FeederCount);
    
    // Battery
    _displayBattery();
    
    // Time
    DateTime now = rtc.now();
    display.setCursor(5, 128);
    display.fillRect(5, 127, 200, 60, WHITE);
    if (now.month() < 10) display.print('0');
    display.print(now.month());
    display.print("-");
    if (now.day() < 10) display.print('0');
    display.print(now.day());
    display.print("-");
    display.print(now.year() % 100);
    display.print("     ");
    if (now.hour() < 10) display.print('0');
    display.print(now.hour());
    display.print(":");
    if (now.minute() < 10) display.print('0');
    display.print(now.minute());
    
    display.refresh();
  }
}

void TumbleFeeder::_readButtons() {
  _redTouch = digitalRead(RED_BUTTON);
  _greenTouch = digitalRead(GREEN_BUTTON);
  _blueTouch = digitalRead(BLUE_BUTTON);
}

void TumbleFeeder::_readBatteryLevel() {
  analogReadResolution(10);
  measuredvbat = analogRead(VBATPIN);
  measuredvbat *= 2;    // we divided by 2, so multiply back
  measuredvbat *= 3.3;  // Multiply by 3.3V, our reference voltage
  measuredvbat /= 1024; // convert to voltage
}

void TumbleFeeder::_displayBattery() {
  _readBatteryLevel();
  display.fillRect(119, 5, 40, 16, WHITE);
  display.drawRect(118, 4, 42, 18, BLACK);
  display.drawRect(159, 9, 6, 8, BLACK);

  // Battery graphic showing bars indicating voltage levels
  if (measuredvbat > 3.85) {
    display.fillRect(122, 7, 7, 12, BLACK);
    display.fillRect(131, 7, 7, 12, BLACK);
    display.fillRect(140, 7, 7, 12, BLACK);
    display.fillRect(149, 7, 7, 12, BLACK);
  }
  else if (measuredvbat > 3.7) {
    display.fillRect(121, 6, 26, 13, WHITE);
    display.fillRect(122, 7, 7, 12, BLACK);
    display.fillRect(131, 7, 7, 12, BLACK);
    display.fillRect(140, 7, 7, 12, BLACK);
  }
  else if (measuredvbat > 3.55) {
    display.fillRect(121, 6, 26, 13, WHITE);
    display.fillRect(122, 7, 7, 12, BLACK);
    display.fillRect(131, 7, 7, 12, BLACK);
  }
  else {
    display.fillRect(121, 6, 26, 13, WHITE);
    display.fillRect(122, 7, 7, 12, BLACK);
  }

  // Display voltage
  display.fillRect(122, 26, 28, 12, WHITE);
  display.setCursor(122, 26);
  display.print(measuredvbat, 2);
  display.print("V");
}

void TumbleFeeder::_displayMouse() {
  display.setRotation(1);
  for (int i = -50; i < 200; i += 15) {
    display.fillRoundRect(i + 25, 82, 15, 10, 6, BLACK);  //head
    display.fillRoundRect(i + 22, 80, 8, 5, 3, BLACK);    //ear
    display.fillRoundRect(i + 30, 84, 1, 1, 1, WHITE);    //eye
    
    if ((i / 10) % 2 == 0) {
      display.fillRoundRect(i, 84, 32, 17, 10, BLACK);
      display.drawFastHLine(i - 8, 85, 18, BLACK);
      display.drawFastHLine(i - 8, 86, 18, BLACK);
      display.drawFastHLine(i - 14, 84, 8, BLACK);
      display.drawFastHLine(i - 14, 85, 8, BLACK);
      display.fillRoundRect(i + 22, 99, 8, 4, 3, BLACK);
      display.fillRoundRect(i, 97, 8, 6, 3, BLACK);
    } else {
      display.fillRoundRect(i + 2, 82, 30, 17, 10, BLACK);
      display.drawFastHLine(i - 6, 91, 18, BLACK);
      display.drawFastHLine(i - 6, 90, 18, BLACK);
      display.drawFastHLine(i - 12, 92, 8, BLACK);
      display.drawFastHLine(i - 12, 91, 8, BLACK);
      display.fillRoundRect(i + 15, 99, 8, 4, 3, BLACK);
      display.fillRoundRect(i + 8, 97, 8, 6, 3, BLACK);
    }
    display.refresh();
    delay(80);
    display.fillRect(i - 25, 73, 95, 33, WHITE);
  }
}

void TumbleFeeder::_displaySDError() {
  _blink(13, 50, 3);
  delay(25);
  _blink(8, 50, 3);
  delay(25);
  display.fillRect(0, 0, 168, 144, WHITE);
  display.setTextSize(2);
  display.setRotation(1);
  display.setCursor(5, 20);
  display.println("Check SD card");
  
  display.setTextSize(1);
  display.setCursor(5, 60);
  display.println("I'm smaller than a mouse");
  display.setCursor(5, 70);
  display.println("but I can fill up a house.");
  display.setCursor(5, 85);
  display.println("What am I?");
  
  display.refresh();
  while (1);
}

/**************************************************************************************************************************************************
                                                                                    Startup Menu Methods
**************************************************************************************************************************************************/

void TumbleFeeder::_drawSettingsBase() {
  display.fillRect(0, 0, 168, 128, WHITE);
  display.drawRect(5, 5, 104, 25, BLACK);
  display.setCursor(35, 14);
  display.println("Settings");
  display.setCursor(36, 14);
  display.println("Settings");
  display.drawRect(5, 5, 104, 110, BLACK);
  display.drawRect(2, 2, 110, 116, BLACK);

  display.setCursor(12, 36);
  display.print("Mode: ");
  display.setCursor(80, 36);
  if (mode == 0)      display.print("FR");
  else if (mode == 1) display.print("Free");
  else if (mode == 2) display.print("FRxt");
  else if (mode == 3) display.print("FrTm");

  if (mode == 0 || mode == 2) {
    display.setCursor(12, 48);
    display.print("FR: ");
  }
  display.setCursor(12, 60);
  display.print("Device#: ");
  display.setCursor(12, 72);
  display.print("Sec open: ");
  display.setCursor(12, 84);
  display.print("Open Pos: ");
  display.setCursor(12, 96);
  display.print("Close Pos: ");
  display.refresh();
}

void TumbleFeeder::_displayCurrentParams() {
  display.fillRect(0, 0, 168, 128, WHITE);
  
  digitalWrite(LED_PIN, LOW);
  _readButtons();
  
  display.drawRect(5, 5, 104, 25, BLACK);
  display.setCursor(35, 14);
  display.println("Settings");
  display.setCursor(36, 14);
  display.println("Settings");
  
  display.setCursor(138, 60);
  display.println("Edit");
  display.setCursor(139, 60);
  display.println("Edit");
  
  display.setCursor(134, 100);
  display.println("Start");
  display.setCursor(135, 100);
  display.println("Start");
  
  display.drawRect(5, 5, 104, 110, BLACK);
  display.drawRect(2, 2, 110, 116, BLACK);
  
  display.setCursor(12, 36);
  display.print("Mode: ");
  display.setCursor(80, 36);
  if (mode == 0)      display.print("FR");
  else if (mode == 1) display.print("Free");
  else if (mode == 2) display.print("FRxt");
  else if (mode == 3) display.print("FrTm");

  if (mode == 0 || mode == 2) {
    display.setCursor(12, 48);
    display.print("FR: ");
    display.setCursor(80, 48);
    display.print(FR);
  }

  display.setCursor(12, 60);
  display.print("Device#: ");
  display.setCursor(80, 60);
  display.print(deviceNumber);

  display.setCursor(12, 72);
  display.print("Sec open: ");
  display.setCursor(80, 72);
  display.print(open_duration);
  
  display.setCursor(12, 84);
  display.print("Open Pos: ");
  display.setCursor(80, 84);
  display.print(openpos);
  
  display.setCursor(12, 96);
  display.print("Close Pos: ");
  display.setCursor(80, 96);
  display.print(closedpos);
  
  _displayBattery();
  
  DateTime now = rtc.now();
  display.setCursor(5, 128);
  display.fillRect(5, 127, 200, 60, WHITE);
  if (now.month() < 10) display.print('0');
  display.print(now.month());
  display.print("-");
  if (now.day() < 10) display.print('0');
  display.print(now.day());
  display.print("-");
  display.print(now.year() % 100);
  display.print("     ");
  if (now.hour() < 10) display.print('0');
  display.print(now.hour());
  display.print(":");
  if (now.minute() < 10) display.print('0');
  display.print(now.minute());
  display.refresh();
  
  // Start session with red button
  if (_redTouch == 0) {
    _beep();
    _displayMouse();  // MOUSE ANIMATION! 🐭
    
    // Update display to show run screen
    _SessionStarted = true;
    _updateDisplay();
    
    // Don't move servo here - it's already in closed position from the menu
    
    // Create files
    _createFile();
    _writeConfigFile();
    return;
  }
  
  // Edit settings with blue button
  if (_blueTouch == 0) {
    _beep();
    delay(100);
    display.fillRect(117, 2, 60, 50, WHITE);
    _menustart = millis();
    _setFeedParadigm();
  }
}

void TumbleFeeder::_setFeedParadigm() {
  int selection;
  if      (mode == 1) selection = 0;
  else if (mode == 0) selection = 1;
  else if (mode == 2) selection = 2;
  else                selection = 3;

  const char* abbrevs[4] = {"Free", "FR", "FRxt", "FrTm"};

  _endstate = false;

  // Set up button labels in right column (no battery in edit menu)
  display.fillRect(112, 0, 56, 128, WHITE);
  display.setCursor(134, 20); display.println("Back");
  display.setCursor(135, 20); display.println("Back");
  display.setCursor(134, 60); display.println("Next");
  display.setCursor(135, 60); display.println("Next");
  display.setCursor(130, 100); display.println("Cycle");
  display.setCursor(131, 100); display.println("Cycle");
  display.refresh();

  while (!_endstate) {
    _readButtons();

    // Blink value at value column (x=80), matching DeviceNum style
    display.setCursor(80, 36);
    display.print(abbrevs[selection]);
    display.refresh();

    if ((millis() - _menustart) > 250) {
      display.fillRect(80, 30, 35, 14, WHITE);
      display.refresh();
      delay(5);
      _menustart = millis();
    }

    // Red = cycle
    if (_redTouch == 0) {
      _beep();
      selection = (selection + 1) % 4;
      // Update mode immediately so FR row can refresh if needed
      int prevMode = mode;
      if      (selection == 0) mode = 1;
      else if (selection == 1) mode = 0;
      else if (selection == 2) mode = 2;
      else                     mode = 3;
      // Redraw base if FR row visibility changed
      if ((prevMode == 0 || prevMode == 2) != (mode == 0 || mode == 2)) {
        _drawSettingsBase();
        display.fillRect(112, 0, 56, 128, WHITE);
        display.setCursor(134, 20); display.println("Back");
        display.setCursor(135, 20); display.println("Back");
        display.setCursor(134, 60); display.println("Next");
        display.setCursor(135, 60); display.println("Next");
        display.setCursor(130, 100); display.println("Cycle");
        display.setCursor(131, 100); display.println("Cycle");
      }
      delay(200);
    }

    // Blue = confirm + proceed
    if (_blueTouch == 0) {
      _beep();
      if      (selection == 0) mode = 1;
      else if (selection == 1) mode = 0;
      else if (selection == 2) mode = 2;
      else                     mode = 3;
      _endstate = true;
      delay(100);
    }

    // Green = back
    if (_greenTouch == 0) {
      _beep();
      _endstate = true;
      _displayCurrentParams();
      return;
    }
  }

  // Redraw settings base (mode may have changed - FR row needs to appear/disappear)
  _drawSettingsBase();
  display.setCursor(134, 20);
  display.println("Back");
  display.setCursor(135, 20);
  display.println("Back");
  display.setCursor(134, 60);
  display.println("Next");
  display.setCursor(135, 60);
  display.println("Next");
  display.setCursor(134, 100);
  display.println("Edit");
  display.setCursor(135, 100);
  display.println("Edit");
  display.refresh();

  if (mode == 1 || mode == 3) {
    _settingDeviceNum();
  } else {
    _settingFR();
  }
}

void TumbleFeeder::_settingFR() {
  _endstate = false;
  _readButtons();
  display.setCursor(80, 48);
  display.print(FR);
  display.refresh();
  
  if ((millis() - _menustart) > 250) {
    display.fillRect(80, 48, 25, 12, WHITE);
    display.refresh();
    delay(5);
    _menustart = millis();
  }
  
  if (_redTouch == 0) {
    _beep();
    FR++;
    if (FR > 10) FR = 1;
    delay(200);
  }
  
  if (_blueTouch == 0) {
    _beep();
    display.fillRect(80, 48, 25, 12, WHITE);
    display.refresh();
    display.setCursor(80, 48);
    display.print(FR);
    display.refresh();
    _endstate = true;
    delay(200);
    _settingDeviceNum();
  }
  
  if (_greenTouch == 0) {
    _beep();
    _endstate = true;
    _displayCurrentParams();
  }
  
  if (_endstate == false) _settingFR();
}

void TumbleFeeder::_settingDeviceNum() {
  _endstate = false;
  _readButtons();
  display.setCursor(80, 60);
  display.print(deviceNumber);
  display.refresh();
  
  if ((millis() - _menustart) > 250) {
    display.fillRect(80, 60, 25, 12, WHITE);
    display.refresh();
    delay(5);
    _menustart = millis();
  }
  
  if (_redTouch == 0) {
    _beep();
    deviceNumber++;
    if (deviceNumber > 19) deviceNumber = 0;
    delay(200);
  }
  
  if (_blueTouch == 0) {
    _beep();
    display.fillRect(80, 60, 25, 12, WHITE);
    display.refresh();
    display.setCursor(80, 60);
    display.print(deviceNumber);
    display.refresh();
    _endstate = true;
    delay(200);
    _settingOpenDuration();
  }
  
  if (_greenTouch == 0) {
    _beep();
    _endstate = true;
    _displayCurrentParams();
  }
  
  if (_endstate == false) _settingDeviceNum();
}

void TumbleFeeder::_settingOpenDuration() {
  _endstate = false;
  _readButtons();
  display.setCursor(80, 72);
  display.print(open_duration);
  display.refresh();
  
  if ((millis() - _menustart) > 250) {
    display.fillRect(80, 72, 25, 12, WHITE);
    display.refresh();
    delay(5);
    _menustart = millis();
  }
  
  if (_redTouch == 0) {
    _beep();
    open_duration += 10;
    if (open_duration > 120) open_duration = 10;
    delay(100);
  }
  
  if (_blueTouch == 0) {
    _beep();
    display.setCursor(80, 72);
    display.print(open_duration);
    display.refresh();
    
    // Move servo to open position before entering menu
    digitalWrite(LED_PIN, HIGH);
    _servo.attach(SERVO_PIN);
    _servo.write(openpos);
    delay(300);
    _servo.detach();
    digitalWrite(LED_PIN, LOW);
    
    _endstate = true;
    _settingOpenPosition();
  }
  
  if (_greenTouch == 0) {
    _beep();
    _endstate = true;
    _displayCurrentParams();
  }
  
  if (_endstate == false) _settingOpenDuration();
}

void TumbleFeeder::_settingOpenPosition() {
  display.fillRect(115, 20, 60, 12, WHITE);
  display.setCursor(115, 20);
  display.println("Decrease");
  display.setCursor(116, 20);
  display.println("Decrease");
  
  display.fillRect(115, 100, 60, 12, WHITE);
  display.setCursor(115, 100);
  display.println("Increase");
  display.setCursor(116, 100);
  display.println("Increase");
  display.refresh();
  
  _endstate = false;
  
  while (!_endstate) {
    _readButtons();
    display.setCursor(80, 84);
    display.print(openpos);
    display.refresh();
    
    if ((millis() - _menustart) > 250) {
      display.fillRect(80, 84, 25, 12, WHITE);
      display.refresh();
      delay(5);
      _menustart = millis();
    }
    
    // RED = INCREASE (fixed - was backwards)
    if (_redTouch == 0) {
      _beep();
      delay(100);
      openpos += 10;
      digitalWrite(LED_PIN, HIGH);
      _servo.attach(SERVO_PIN);
      
      // Slowly move servo to new openpos
      for (int move = openpos - 10; move < openpos; move++) {
        _servo.write(move);
        delay(50);
      }
      
      _servo.detach();
      digitalWrite(LED_PIN, LOW);
      
      if (openpos > 90) openpos = 90;
    }
    
    if (_blueTouch == 0) {
      _beep();
      display.fillRect(80, 84, 25, 12, WHITE);
      display.setCursor(80, 84);
      display.print(openpos);
      display.refresh();
      digitalWrite(LED_PIN, HIGH);
      _servo.attach(SERVO_PIN);
      _servo.write(closedpos);
      delay(300);
      _servo.detach();
      digitalWrite(LED_PIN, LOW);
      _endstate = true;
      _settingClosedPosition();
    }
    
    // GREEN = DECREASE (fixed - was backwards)
    if (_greenTouch == 0) {
      _beep();
      delay(100);
      openpos -= 10;
      digitalWrite(LED_PIN, HIGH);
      _servo.attach(SERVO_PIN);
      
      // Slowly move servo to new openpos
      for (int move = openpos + 10; move > openpos; move--) {
        _servo.write(move);
        delay(50);
      }
      
      _servo.detach();
      digitalWrite(LED_PIN, LOW);
      
      if (openpos < 0) openpos = 0;
    }
    
    delay(10);  // Small delay
  }
}

void TumbleFeeder::_settingClosedPosition() {
  _endstate = false;

  // Update button labels for this screen
  display.fillRect(112, 0, 56, 128, WHITE);
  display.setCursor(115, 20);
  display.println("Decrease");
  display.setCursor(116, 20);
  display.println("Decrease");
  display.setCursor(115, 100);
  display.println("Increase");
  display.setCursor(116, 100);
  display.println("Increase");
  display.setCursor(134, 60);
  display.println("Save");
  display.setCursor(135, 60);
  display.println("Save");
  display.refresh();

  while (!_endstate) {
    _readButtons();
    display.setCursor(80, 96);
    display.print(closedpos);
    display.refresh();
    
    if ((millis() - _menustart) > 250) {
      display.fillRect(80, 96, 25, 12, WHITE);
      display.refresh();
      delay(5);
      _menustart = millis();
    }
    
    if (_redTouch == 0) {
      _beep();
      delay(100);
      closedpos += 10;
      digitalWrite(LED_PIN, HIGH);
      _servo.attach(SERVO_PIN);
      
      // Slowly move servo to new closedpos
      for (int move = closedpos - 10; move < closedpos; move++) {
        _servo.write(move);
        delay(50);
      }
      
      _servo.detach();
      digitalWrite(LED_PIN, LOW);
      if (closedpos > 180) closedpos = 180;
    }
    
    if (_blueTouch == 0) {
      _beep();
      display.fillRect(80, 96, 25, 12, WHITE);
      display.setCursor(80, 96);
      display.print(closedpos);
      display.refresh();
      _endstate = true;
      _displayCurrentParams();
    }
    
    if (_greenTouch == 0) {
      _beep();
      delay(100);
      closedpos -= 10;
      digitalWrite(LED_PIN, HIGH);
      _servo.attach(SERVO_PIN);
      
      // Slowly move servo to new closedpos
      for (int move = closedpos + 10; move > closedpos; move--) {
        _servo.write(move);
        delay(50);
      }
      
      _servo.detach();
      digitalWrite(LED_PIN, LOW);
    }
    
    delay(10);  // Small delay
  }
}

/**************************************************************************************************************************************************
                                                                                    SD Card / Logging Methods
**************************************************************************************************************************************************/

// Static datetime callback for SD card
void TumbleFeeder::_dateTime(uint16_t* date, uint16_t* time) {
  if (_instance) {
    DateTime now = _instance->rtc.now();
    *date = FAT_DATE(now.year(), now.month(), now.day());
    *time = FAT_TIME(now.hour(), now.minute(), now.second());
  }
}

void TumbleFeeder::_logData() {
  _writeToSD();
  logfile.flush();
  delay(100);
}

void TumbleFeeder::_writeToSD() {
  DateTime now = rtc.now();
  
  logfile.print(now.month());
  logfile.print("/");
  logfile.print(now.day());
  logfile.print("/");
  logfile.print(now.year());
  logfile.print(" ");
  logfile.print(now.hour());
  logfile.print(":");
  if (now.minute() < 10) logfile.print('0');
  logfile.print(now.minute());
  logfile.print(":");
  if (now.second() < 10) logfile.print('0');
  logfile.print(now.second());
  logfile.print(",");
  
  logfile.print(rtc.getTemperature());
  logfile.print(",");
  
  logfile.print(millis() / 1000.0000);
  logfile.print(",");
  logfile.print(measuredvbat);
  logfile.print(",");
  logfile.print(deviceNumber);
  logfile.print(",");
  
  logfile.print(leftPokeCount);
  logfile.print(",");
  logfile.print(leftPokeDur);
  logfile.print(",");
  logfile.print(rightPokeCount);
  logfile.print(",");
  logfile.print(rightPokeDur);
  logfile.print(",");
  
  logfile.print(FeederCount);
  logfile.print(",");
  logfile.print(leftFeederDur);
  logfile.print(",");
  logfile.print(_pendingEvent);
  logfile.print(",");
  _pendingEvent = "";
  if (mode == 0) {
    logfile.print("FR");
    logfile.println(FR);
  } else if (mode == 1) {
    logfile.println("Free");
  } else if (mode == 2) {
    logfile.print("FRExtend");
    logfile.println(FR);
  } else if (mode == 3) {
    logfile.println("FreeTerminate");
  }
}

void TumbleFeeder::_createFile() {
  if (!SD.begin(cardSelect, SD_SCK_MHZ(4))) {
    _error(2);
    return;
  }
  
  strcpy(filename, "TUMBLER______________.CSV");
  _getFilename(filename);
  Serial.print("Creating file: ");
  Serial.println(filename);
  
  logfile = SD.open(filename, FILE_WRITE);
  if (!logfile) {
    Serial.println("Failed to open file for writing!");
    return;
  }
  
  // Write header
  logfile.println("Timestamp,Temperature,ElapsedSecs,BatteryVoltage,DeviceNumber,LeftCount,LeftDur,RightCount,RightDur,LeftFeedCount,LeftFeedDur,Event,FeedParadigm");
  logfile.flush();
  Serial.println("File created and header written.");
}

void TumbleFeeder::_getFilename(char *fname) {
  DateTime now = rtc.now();
  fname[7] = deviceNumber / 100 + '0';
  fname[8] = deviceNumber / 10 + '0';
  fname[9] = deviceNumber % 10 + '0';
  fname[11] = now.month() / 10 + '0';
  fname[12] = now.month() % 10 + '0';
  fname[13] = now.day() / 10 + '0';
  fname[14] = now.day() % 10 + '0';
  fname[15] = (now.year() - 2000) / 10 + '0';
  fname[16] = (now.year() - 2000) % 10 + '0';
  for (uint8_t i = 0; i < 100; i++) {
    fname[18] = '0' + i / 10;
    fname[19] = '0' + i % 10;
    if (!SD.exists(fname)) {
      break;
    }
  }
}

void TumbleFeeder::_createPos() {
  if (!SD.begin(cardSelect, SD_SCK_MHZ(4))) {
    _error(2);
    Serial.println("SD error in createPos");
    return;
  }
  
  configfile = SD.open("CONFIG.csv", FILE_WRITE);
  configfile.close();
  configfile = SD.open("CONFIG.csv", FILE_READ);
  
  if (configfile) {
    String all = configfile.readString();
    if (all.length() > 0) {
      int index = all.indexOf(" ");
      int index2 = all.indexOf(" ", index + 1);
      int index3 = all.indexOf(" ", index2 + 1);
      int index4 = all.indexOf(" ", index3 + 1);
      int index5 = all.indexOf(" ", index4 + 1);
      
      mode = all.substring(0, index).toInt();
      open_duration = all.substring(index + 1, index2).toInt();
      deviceNumber = all.substring(index2 + 1, index3).toInt();
      openpos = all.substring(index3 + 1, index4).toInt();
      closedpos = all.substring(index4 + 1, index5).toInt();
      FR = all.substring(index5 + 1).toInt();
    }
    configfile.close();
  }
  delay(50);
}

void TumbleFeeder::_writeConfigFile() {
  configfile = SD.open("CONFIG.csv", FILE_WRITE);
  if (configfile) {
    configfile.rewind();
    configfile.print(mode);
    configfile.print(" ");
    configfile.print(open_duration);
    configfile.print(" ");
    configfile.print(deviceNumber);
    configfile.print(" ");
    configfile.print(openpos);
    configfile.print(" ");
    configfile.print(closedpos);
    configfile.print(" ");
    configfile.print(FR);
    configfile.flush();
    configfile.close();
  }
}

void TumbleFeeder::_error(uint8_t errno) {
  _displaySDError();
}

/**************************************************************************************************************************************************
                                                                                    Stimuli / Helper Methods
**************************************************************************************************************************************************/

void TumbleFeeder::_blink(byte PIN, byte DELAY_MS, byte loops) {
  for (byte i = 0; i < loops; i++) {
    digitalWrite(PIN, HIGH);
    delay(DELAY_MS);
    digitalWrite(PIN, LOW);
    delay(DELAY_MS);
  }
}

void TumbleFeeder::_beep() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(LED_PIN, HIGH);
    delayMicroseconds(250);
    digitalWrite(LED_PIN, LOW);
    delayMicroseconds(450);
  }
}
