/*****************************************************************
 * DISPLAY AND USER INTERFACE FUNCTIONS
 * 
 * This file contains all functions related to the Sharp Memory
 * Display and user interface, including:
 * - Configuration menu screens
 * - Parameter setting/adjustment functions
 * - Runtime status display
 * - Battery indicator
 * - Mouse animation
 * - Error displays
 * 
 * NAVIGATION:
 * - Red button: Increment values / Start session / Reset
 * - Blue button: Confirm and advance to next menu
 * - Green button: Go back to previous menu
 * 
 * MENU HIERARCHY:
 * 1. Main settings display
 * 2. Mode selection (Proximity/Free)
 * 3. ProxRequirement setting
 * 4. Device number setting
 * 5. Open duration setting
 * 6. Open position calibration
 * 7. Closed position calibration
 * 8. Back to main → Start session
 *****************************************************************/

/*****************************************************************
 * DISPLAY CURRENT PARAMETERS (MAIN SETTINGS SCREEN)
 * 
 * Shows the main configuration screen before starting a session.
 * Displays all current settings and waits for user input.
 * 
 * SCREEN LAYOUT:
 * ┌──────────────┐
 * │  Settings    │   Title box
 * ├──────────────┤
 * │ Mode: Prox   │   Operating mode
 * │ ProxTime: 1  │   Proximity duration requirement
 * │ Device#: 0   │   Device ID number
 * │ Sec open: 60 │   Feeder open duration
 * │ Open Pos: 0  │   Servo open angle
 * │ Close Pos:150│   Servo closed angle
 * ├──────────────┤
 * │ MM-DD-YY     │   Current date and time
 * │ HH:MM        │
 * └──────────────┘
 * [Edit] [Start] ← Button labels
 * [Battery icon]
 * 
 * BUTTON ACTIONS:
 * - Red button: Start session (play mouse animation, begin logging)
 * - Blue button: Enter edit mode (set_feed_paradigm menu)
 * - Green button: (currently unused)
 * 
 * Called repeatedly from setup() until SessionStarted becomes true.
 *****************************************************************/
void display_current_params() {
  display.fillRect(0, 0, 168, 128, WHITE);  // Clear screen

  digitalWrite(13, LOW);  // Ensure MOSFET/LED is off
  read_buttons();         // Read current button states
  
  // Draw UI borders and labels with shadow effect (double-printing)
  display.drawRect(5, 5, 104, 25, BLACK);
  display.setCursor(35, 14);
  display.println("Settings");
  display.setCursor(138, 60);
  display.println("Edit");
  display.setCursor(134, 100);
  display.println("Start");
  display.setCursor(36, 14);
  display.println("Settings");  // Shadow effect
  display.setCursor(139, 60);
  display.println("Edit");      // Shadow effect
  display.setCursor(135, 100);
  display.println("Start");     // Shadow effect
  display.drawRect(5, 5, 104, 110, BLACK);
  display.drawRect(2, 2, 110, 116, BLACK);

  // Display Mode setting
  display.setCursor(12, 36);
  display.print("Mode: ");
  display.setCursor(80, 36);
  mode == 1 ? display.print("Free") : display.print("Prox");

  // Display ProxRequirement setting
  display.setCursor(12, 48);
  display.print("ProxTime: ");
  display.setCursor(80, 48);
  display.print(ProxRequirement);

  // Display Device Number
  display.setCursor(12, 60);
  display.print("Device#: ");
  display.setCursor(80, 60);
  display.print(CSL);

  // Display Open Duration
  display.setCursor(12, 72);
  display.print("Sec open: ");
  display.setCursor(80, 72);
  display.print(open_duration);
  
  // Display Open Position
  display.setCursor(12, 84);
  display.print("Open Pos: ");
  display.setCursor(80, 84);
  display.print(openpos);
  
  // Display Closed Position
  display.setCursor(12, 96);
  display.print("Close Pos: ");
  display.setCursor(80, 96);
  display.print(closedpos);

  // Display battery indicator
  DisplayBattery();

  // Display current date and time from RTC
  DateTime now = rtc.now();
  display.setCursor(5, 128);
  display.fillRect(5, 127, 200, 60, WHITE);  // Clear date/time area
  
  // Format: MM-DD-YY HH:MM (with leading zeros)
  if (now.month() < 10)
    display.print('0');
  display.print(now.month());
  display.print("-");
  if (now.day() < 10)
    display.print('0');
  display.print(now.day());
  display.print("-");
  display.print(now.year() % 100);  // 2-digit year
  display.print("     ");
  if (now.hour() < 10)
    display.print('0');
  display.print(now.hour());
  display.print(":");
  if (now.minute() < 10)
    display.print('0');
  display.print(now.minute());
  display.refresh();

  // Handle button presses
  if (red_touch == 0) {
    // RED BUTTON: Start experimental session
    Beep();
    SessionStarted = true;    // Exit configuration loop
    display_mouse();          // Play mouse animation
    CreateFile();             // Create timestamped data log file
    writeConfigFile();        // Save settings to CONFIG.csv
    update_display();         // Switch to runtime display
  }

  if (blue_touch == 0) {
    // BLUE BUTTON: Enter edit mode
    Beep();
    delay(100);
    display.fillRect(117, 2, 60, 50, WHITE);  // Clear button area
    menustart = millis();     // Initialize menu blink timer
    set_feed_paradigm();      // Enter first menu (mode selection)
  }

  if (green_touch == 0) {
    // GREEN BUTTON: Currently unused in main settings screen
  }
}

/*****************************************************************
 * MODE SELECTION MENU
 * 
 * Allows user to toggle between Proximity and Free feeding modes.
 * First menu screen in the configuration edit sequence.
 * 
 * DISPLAY:
 * - Shows current mode ("Prox" or "Free") with blinking effect
 * - Button labels: [Back] [Next] [Edit]
 * 
 * BUTTON ACTIONS:
 * - Red button: Toggle between modes (Prox ↔ Free)
 * - Blue button: Confirm selection, advance to next menu (setting_FR)
 * - Green button: Cancel, return to main settings screen
 * 
 * VISUAL FEEDBACK:
 * - Value blinks at 4 Hz (250ms on/off cycle) to indicate edit mode
 * - Recursively calls itself until user confirms or cancels
 *****************************************************************/
void set_feed_paradigm() {
  endstate = false;  // Flag to control recursion loop
  
  // Draw button labels with shadow effect
  display.fillRect(134, 20, 35, 12, WHITE);
  display.setCursor(134, 20);
  display.println("Back");
  display.setCursor(135, 20);
  display.println("Back");

  display.fillRect(134, 60, 35, 12, WHITE);
  display.setCursor(134, 60);
  display.println("Next");
  display.setCursor(135, 60);
  display.println("Next");

  display.fillRect(134, 100, 35, 12, WHITE);
  display.setCursor(134, 100);
  display.println("Edit");
  display.setCursor(135, 100);
  display.println("Edit");
  display.refresh();

  read_buttons();  // Read current button states
  
  // Display current mode
  display.setCursor(80, 36);
  mode == 1 ? display.print("Free") : display.print("Prox");
  display.refresh();

  // Blink the value to indicate it's editable (250ms on/off)
  if ((millis() - menustart) > 250) {
    display.fillRect(80, 36, 25, 12, WHITE);  // Clear value area
    display.refresh();
    delay(5);
    menustart = millis();  // Reset blink timer
  }

  // RED BUTTON: Toggle mode
  if (red_touch == 0) {
    Beep();
    if (mode == 0) {
      mode = 1;  // Switch to Free mode
      delay(200);  // Debounce delay
    } else {
      mode = 0;  // Switch to Proximity mode
      delay(200);  // Debounce delay
    }
  }

  // BLUE BUTTON: Confirm and proceed to next menu
  if (blue_touch == 0) {
    Beep();
    display.fillRect(80, 36, 25, 12, WHITE);
    display.setCursor(80, 36);
    mode == 1 ? display.print("Free") : display.print("Prox");
    display.refresh();
    delay(100);
    endstate = true;  // Exit this menu
    setting_FR();     // Proceed to ProxRequirement setting menu
  }

  // GREEN BUTTON: Go back to main settings screen
  if (green_touch == 0) {
    Beep();
    endstate = true;  // Exit this menu
    display_current_params();  // Return to main screen
  }

  // Recursive call to stay in this menu until user confirms or cancels
  if (endstate == false) set_feed_paradigm();
}

/*****************************************************************
 * PROXIMITY REQUIREMENT SETTING MENU
 * 
 * Allows user to set how many seconds the mouse must stay near
 * the feeder to trigger a feeding event (in Proximity mode).
 * 
 * DISPLAY:
 * - Shows current ProxRequirement value (1-10 seconds) with blinking
 * - Label: "ProxTime: #"
 * - Button labels inherited from previous menu
 * 
 * BUTTON ACTIONS:
 * - Red button: Increment value (1→2→3...→10→1)
 * - Blue button: Confirm selection, advance to next menu (device number)
 * - Green button: Cancel, return to main settings screen
 * 
 * VALUE RANGE: 1-10 seconds (wraps around)
 * Determines how long the mouse must maintain proximity before
 * the feeder opens in Proximity mode.
 *****************************************************************/
void setting_FR() {
  endstate = false;  // Flag to control recursion loop
  read_buttons();    // Read current button states
  
  // Display current ProxRequirement value
  display.setCursor(80, 48);
  display.print(ProxRequirement);
  display.refresh();

  // Blink the value to indicate it's editable (250ms on/off)
  if ((millis() - menustart) > 250) {
    display.fillRect(80, 48, 25, 12, WHITE);  // Clear value area
    display.refresh();
    delay(5);
    menustart = millis();  // Reset blink timer
  }

  // RED BUTTON: Increment ProxRequirement (1-10, wrapping)
  if (red_touch == 0) {
    Beep();
    ProxRequirement++;
    if (ProxRequirement > 10) ProxRequirement = 1;  // Wrap to 1
    delay(200);  // Debounce delay
  }

  // BLUE BUTTON: Confirm and proceed to next menu
  if (blue_touch == 0) {
    Beep();
    display.fillRect(80, 48, 25, 12, WHITE);
    display.refresh();
    display.setCursor(80, 48);
    display.print(ProxRequirement);
    display.refresh();
    endstate = true;  // Exit this menu
    delay(200);
    setting_device_num();  // Proceed to device number menu
  }

  // GREEN BUTTON: Go back to main settings screen
  if (green_touch == 0) {
    Beep();
    endstate = true;  // Exit this menu
    display_current_params();  // Return to main screen
  }

  // Recursive call to stay in this menu until user confirms or cancels
  if (endstate == false) setting_FR();
}


/*****************************************************************
 * DEVICE NUMBER SETTING MENU
 * 
 * Allows user to set the device ID number (CSL variable). This
 * number is embedded in data filenames and logged in CSV files
 * to identify which device generated the data.
 * 
 * DISPLAY:
 * - Shows current device number (0-19) with blinking
 * - Label: "Device#: #"
 * 
 * BUTTON ACTIONS:
 * - Red button: Increment value (0→1→2...→19→0)
 * - Blue button: Confirm selection, advance to next menu (open duration)
 * - Green button: Cancel, return to main settings screen
 * 
 * VALUE RANGE: 0-19 (wraps around)
 * Used in filename format: CASTLE_###_MMDDYY_##.CSV
 * Example: Device #3 creates files like CASTLE_003_031524_00.CSV
 *****************************************************************/
void setting_device_num() {
  endstate = false;  // Flag to control recursion loop
  read_buttons();    // Read current button states
  
  // Display current device number
  display.setCursor(80, 60);
  display.print(CSL);
  display.refresh();

  // Blink the value to indicate it's editable (250ms on/off)
  if ((millis() - menustart) > 250) {
    display.fillRect(80, 60, 25, 12, WHITE);  // Clear value area
    display.refresh();
    delay(5);
    menustart = millis();  // Reset blink timer
  }

  // RED BUTTON: Increment device number (0-19, wrapping)
  if (red_touch == 0) {
    Beep();
    CSL++;
    if (CSL > 19) CSL = 0;  // Wrap to 0
    delay(200);  // Debounce delay
  }

  // BLUE BUTTON: Confirm and proceed to next menu
  if (blue_touch == 0) {
    Beep();
    display.fillRect(80, 60, 25, 12, WHITE);
    display.refresh();
    display.setCursor(80, 60);
    display.print(CSL);
    display.refresh();
    endstate = true;  // Exit this menu
    delay(200);
    setting_open_duration();  // Proceed to open duration menu
  }

  // GREEN BUTTON: Go back to main settings screen
  if (green_touch == 0) {
    Beep();
    endstate = true;  // Exit this menu
    display_current_params();  // Return to main screen
  }

  // Recursive call to stay in this menu until user confirms or cancels
  if (endstate == false) setting_device_num();
}

/*****************************************************************
 * OPEN DURATION SETTING MENU
 * 
 * Allows user to set how many seconds the feeder door stays open
 * during a feeding event (in Proximity mode).
 * 
 * DISPLAY:
 * - Shows current open_duration value (10-120 seconds) with blinking
 * - Label: "Sec open: ##"
 * 
 * BUTTON ACTIONS:
 * - Red button: Increment by 10 seconds (10→20→30...→120→10)
 * - Blue button: Confirm selection, move servo to open position,
 *   advance to servo open position calibration menu
 * - Green button: Cancel, return to main settings screen
 * 
 * VALUE RANGE: 10-120 seconds in 10-second increments (wraps around)
 * Determines how long food is accessible after proximity detection.
 * 
 * NOTE: When proceeding to next menu, the servo automatically moves
 * to the current openpos to allow visual calibration.
 *****************************************************************/
void setting_open_duration() {
  endstate = false;  // Flag to control recursion loop
  read_buttons();    // Read current button states
  
  // Display current open duration value
  display.setCursor(80, 72);
  display.print(open_duration);
  display.refresh();

  // Blink the value to indicate it's editable (250ms on/off)
  if ((millis() - menustart) > 250) {
    display.fillRect(80, 72, 25, 12, WHITE);  // Clear value area
    display.refresh();
    delay(5);
    menustart = millis();  // Reset blink timer
  }

  // RED BUTTON: Increment by 10 seconds (10-120, wrapping)
  if (red_touch == 0) {
    Beep();
    open_duration += 10;
    if (open_duration > 120) open_duration = 10;  // Wrap to 10
    delay(100);  // Debounce delay
  }

  // BLUE BUTTON: Confirm and proceed to open position calibration
  if (blue_touch == 0) {
    Beep();
    display.setCursor(80, 72);
    display.print(open_duration);
    display.refresh();
    
    // Move servo to open position for visual calibration
    digitalWrite(13, HIGH);  // Enable servo power
    myservo.attach(10);      // Attach servo
    myservo.write(openpos);  // Move to open position
    delay(300);              // Wait for servo to reach position
    myservo.detach();        // Detach servo
    digitalWrite(13, LOW);   // Disable servo power
    
    endstate = true;  // Exit this menu
    setting_open_position();  // Proceed to open position calibration menu
  }

  // GREEN BUTTON: Go back to main settings screen
  if (green_touch == 0) {
    Beep();
    endstate = true;  // Exit this menu
    display_current_params();  // Return to main screen
  }

  // Recursive call to stay in this menu until user confirms or cancels
  if (endstate == false) setting_open_duration();
}

/*****************************************************************
 * SERVO OPEN POSITION CALIBRATION MENU
 * 
 * Allows user to calibrate the servo angle for the "open" position
 * of the food hopper. The servo moves in real-time as the user
 * adjusts, providing immediate visual feedback.
 * 
 * DISPLAY:
 * - Shows current openpos value (0-90 degrees) with blinking
 * - Label: "Open Pos: ##"
 * - Button labels changed to: [Decrease] [Next] [Increase]
 * 
 * BUTTON ACTIONS:
 * - Red button: Increase angle by 10° (servo moves immediately)
 * - Blue button: Confirm selection, move servo to closed position,
 *   advance to closed position calibration menu
 * - Green button: Decrease angle by 10° (servo moves immediately)
 * 
 * VALUE RANGE: 0-90 degrees in 10-degree increments
 * - Red increments wrap: 90° → 0°
 * - Green decrements cap at 90° maximum
 * 
 * CALIBRATION PROCESS:
 * 1. User observes current physical servo position
 * 2. Presses Red to increase or Green to decrease angle
 * 3. Servo gradually moves 1° at a time (smooth motion)
 * 4. User finds angle where hopper is fully open
 * 5. Presses Blue to confirm and move to closed position calibration
 *****************************************************************/
void setting_open_position() {
  // Update button labels for this menu
  display.fillRect(115, 20, 60, 12, WHITE);
  display.setCursor(115, 20);
  display.println("Decrease");
  display.setCursor(116, 20);
  display.println("Decrease");  // Shadow effect

  display.fillRect(115, 100, 60, 12, WHITE);
  display.setCursor(115, 100);
  display.println("Increase");
  display.setCursor(116, 100);
  display.println("Increase");  // Shadow effect
  display.refresh();

  endstate = false;  // Flag to control recursion loop
  read_buttons();    // Read current button states
  
  // Display current open position value
  display.setCursor(80, 84);
  display.print(openpos);
  display.refresh();

  // Blink the value to indicate it's editable (250ms on/off)
  if ((millis() - menustart) > 250) {
    display.fillRect(80, 84, 25, 12, WHITE);  // Clear value area
    display.refresh();
    delay(5);
    menustart = millis();  // Reset blink timer
  }

  // RED BUTTON: Increase servo angle by 10°
  if (red_touch == 0) {
    Beep();
    delay(100);
    openpos += 10;
    
    // Move servo gradually to new position for smooth motion
    digitalWrite(13, HIGH);  // Enable servo power
    myservo.attach(10);      // Attach servo
    
    // Gradually move 1° at a time from old position to new
    for (int move = openpos - 10; move < openpos; move++) {
      myservo.write(move);
      delay(50);  // 50ms per degree
    }
    
    myservo.detach();        // Detach servo
    digitalWrite(13, LOW);   // Disable servo power

    // Wrap to 0 if exceeds max
    if (openpos > 90) openpos = 0;
  }

  // BLUE BUTTON: Confirm and proceed to closed position calibration
  if (blue_touch == 0) {
    Beep();
    display.fillRect(80, 84, 25, 12, WHITE);
    display.setCursor(80, 84);
    display.print(openpos);
    display.refresh();
    
    // Move servo to closed position for next calibration step
    digitalWrite(13, HIGH);     // Enable servo power
    myservo.attach(10);         // Attach servo
    myservo.write(closedpos);   // Move to closed position
    delay(300);                 // Wait for servo to reach position
    myservo.detach();           // Detach servo
    digitalWrite(13, LOW);      // Disable servo power
    
    endstate = true;  // Exit this menu
    setting_closed_position();  // Proceed to closed position calibration
  }

  // GREEN BUTTON: Decrease servo angle by 10°
  if (green_touch == 0) {
    Beep();
    delay(100);
    openpos -= 10;
    
    // Move servo gradually to new position for smooth motion
    digitalWrite(13, HIGH);  // Enable servo power
    myservo.attach(10);      // Attach servo
    
    // Gradually move 1° at a time from old position to new (decreasing)
    for (int move = openpos + 10; move > openpos; move--) {
      myservo.write(move);
      delay(50);  // 50ms per degree
    }
    
    myservo.detach();        // Detach servo
    digitalWrite(13, LOW);   // Disable servo power

    // Cap at 90° maximum
    if (openpos > 90) openpos = 90;
  }

  // Recursive call to stay in this menu until user confirms
  if (endstate == false) setting_open_position();
}

/*****************************************************************
 * SERVO CLOSED POSITION CALIBRATION MENU
 * 
 * Allows user to calibrate the servo angle for the "closed" position
 * of the food hopper. The servo moves in real-time as the user
 * adjusts, providing immediate visual feedback.
 * 
 * DISPLAY:
 * - Shows current closedpos value (0-140 degrees) with blinking
 * - Label: "Close Pos: ###"
 * - Button labels inherited from previous menu: [Decrease] [Next] [Increase]
 * 
 * BUTTON ACTIONS:
 * - Red button: Increase angle by 10° (servo moves immediately, caps at 140°)
 * - Blue button: Confirm selection, return to main settings screen
 * - Green button: Decrease angle by 10° (servo moves immediately, no lower limit)
 * 
 * VALUE RANGE: Typically 90-180 degrees in 10-degree increments
 * - Red increments cap at 140° maximum
 * - Green decrements have no lower limit
 * 
 * CALIBRATION PROCESS:
 * 1. User observes current physical servo position
 * 2. Presses Red to increase or Green to decrease angle
 * 3. Servo gradually moves 1° at a time (smooth motion)
 * 4. User finds angle where hopper is fully closed
 * 5. Presses Blue to finish calibration and return to main menu
 *****************************************************************/
void setting_closed_position() {
  endstate = false;  // Flag to control recursion loop
  read_buttons();    // Read current button states
  
  // Display current closed position value
  display.setCursor(80, 96);
  display.print(closedpos);
  display.refresh();

  // Blink the value to indicate it's editable (250ms on/off)
  if ((millis() - menustart) > 250) {
    display.fillRect(80, 96, 25, 12, WHITE);  // Clear value area
    display.refresh();
    delay(5);
    menustart = millis();  // Reset blink timer
  }

  // RED BUTTON: Increase servo angle by 10° (capped at 140°)
  if (red_touch == 0) {
    Beep();
    delay(100);
    closedpos += 10;
    
    // Move servo gradually to new position for smooth motion
    digitalWrite(13, HIGH);  // Enable servo power
    myservo.attach(10);      // Attach servo
    
    // Gradually move 1° at a time from old position to new
    for (int move = closedpos - 10; move < closedpos; move++) {
      myservo.write(move);
      delay(50);  // 50ms per degree
    }
    
    myservo.detach();        // Detach servo
    digitalWrite(13, LOW);   // Disable servo power
    
    // Cap at 140° maximum to prevent over-rotation
    if (closedpos > 140) closedpos = 140;
  }

  // BLUE BUTTON: Confirm and return to main settings screen
  if (blue_touch == 0) {
    Beep();
    display.fillRect(80, 96, 25, 12, WHITE);
    display.setCursor(80, 96);
    display.print(closedpos);
    display.refresh();
    endstate = true;  // Exit this menu
    display_current_params();  // Return to main settings screen
  }

  // GREEN BUTTON: Decrease servo angle by 10°
  if (green_touch == 0) {
    Beep();
    delay(100);
    closedpos -= 10;
    
    // Move servo gradually to new position for smooth motion
    digitalWrite(13, HIGH);  // Enable servo power
    myservo.attach(10);      // Attach servo
    
    // Gradually move 1° at a time from old position to new (decreasing)
    for (int move = closedpos + 10; move > closedpos; move--) {
      myservo.write(move);
      delay(50);  // 50ms per degree
    }
    
    myservo.detach();        // Detach servo
    digitalWrite(13, LOW);   // Disable servo power
  }
  
  // Recursive call to stay in this menu until user confirms
  if (endstate == false) setting_closed_position();
}

/*****************************************************************
 * ON HOUR SETTING MENU (DISABLED)
 * 
 * This function would allow users to set the hour when the device
 * becomes active each day. Currently disabled/commented out.
 * 
 * See SetActiveHours.ino for the corresponding logic that would
 * use this setting.
 * 
 * TO RE-ENABLE:
 * 1. Uncomment the code below
 * 2. Integrate into menu flow (after closed position setting)
 * 3. Re-enable set_active() function in SetActiveHours.ino
 *****************************************************************/
void setting_on_hour() {
  // DISABLED - Code commented out
  // Would allow setting active start hour (0-23)
  //  read_buttons();
  //  display.fillRect(0, 0, 168, 144, WHITE);
  //  display.drawRect(5, 5, 156, 35, BLACK);
  //  display.setCursor(20, 20);
  //  display.println("On Hour");
  //
  //  display.setCursor(5, 45);
  //  display.println("Green Button : next menu");
  //
  //  display.setCursor(5, 60);
  //  display.println("Blue Button : change params");
  //  display.setCursor(5, 75);
  //  display.print("On Hour: ");
  //  display.print(on_hour);
  //  //  display.refresh();
  //  if (red_touch == 0) {
  //    display.refresh();
  //    delay(100);
  //    on_nums += 1;
  //  }
  //  return (on_nums % 24) ;
}

/*****************************************************************
 * OFF HOUR SETTING MENU (DISABLED)
 * 
 * This function would allow users to set the hour when the device
 * becomes inactive each day. Currently disabled/commented out.
 * 
 * See SetActiveHours.ino for the corresponding logic that would
 * use this setting.
 * 
 * TO RE-ENABLE:
 * 1. Uncomment the code below
 * 2. Integrate into menu flow (after on_hour setting)
 * 3. Re-enable set_active() function in SetActiveHours.ino
 *****************************************************************/
void setting_off_hour() {
  // DISABLED - Code commented out
  // Would allow setting active end hour (0-23)
  //  read_buttons();
  //  display.fillRect(0, 0, 168, 144, WHITE);
  //  display.drawRect(5, 5, 156, 35, BLACK);
  //  display.setCursor(20, 20);
  //  display.println("Off Hour");
  //  display.setCursor(5, 45);
  //  display.println("Green Button : next menu");
  //  display.setCursor(5, 60);
  //  display.println("Blue Button : change params");
  //  display.setCursor(5, 75);
  //  display.print("Off Hour: ");
  //  display.print(off_hour);
  //  if (red_touch == 0) {
  //    display.refresh();
  //    delay(100);
  //    off_nums += 1;
  //  }
  //  return (off_nums % 25) ;
}

/*****************************************************************
 * RUNTIME STATUS DISPLAY
 * 
 * Shows real-time experimental data during an active session.
 * Displays current configuration, event counters, and allows
 * system reset via long red button press.
 * 
 * SCREEN LAYOUT:
 * ┌──────────────┐
 * │   Tumble!    │   Title
 * ├──────────────┤
 * │ Mode: Prox   │   Current configuration
 * │ ProxTime: 1  │
 * │ Device#: 0   │
 * ├──────────────┤
 * │ Approach: ## │   Live event counters
 * │ Feed: ##     │
 * ├──────────────┤
 * │ MM-DD-YY     │   Current date and time
 * │ HH:MM        │
 * └──────────────┘
 * [Battery icon] [Reset]
 * 
 * BUTTON ACTIONS:
 * - Red button (1 second hold): System reset (restarts device)
 * - Blue button: (unused)
 * - Green button: (unused)
 * 
 * RESET SEQUENCE:
 * 1. User presses and holds red button for 1 second
 * 2. Display shows "RESETTING..."
 * 3. Four confirmation beeps
 * 4. System performs hardware reset via NVIC_SystemReset()
 * 
 * Called repeatedly from loop() during active experiment session.
 *****************************************************************/
void update_display() {
  display.fillRect(0, 0, 168, 128, WHITE);  // Clear screen

  // Display title with shadow effect
  display.setCursor(35, 14);
  display.println("Tumble!");
  display.setCursor(36, 14);
  display.println("Tumble!");  // Shadow effect

  digitalWrite(13, LOW);  // Ensure MOSFET/LED is off
  read_buttons();         // Read current button states
  
  // Display "Reset" button label with shadow effect
  display.setCursor(134, 100);
  display.println("Reset");
  display.setCursor(135, 100);
  display.println("Reset");  // Shadow effect

  // Draw UI borders
  display.drawRect(5, 5, 104, 110, BLACK);
  display.drawRect(2, 2, 110, 116, BLACK);

  // Display current configuration
  display.setCursor(12, 30);
  display.print("Mode: ");
  display.setCursor(80, 30);
  mode == 1 ? display.print("Free") : display.print("Prox");

  display.setCursor(12, 42);
  display.print("ProxTime: ");
  display.setCursor(80, 42);
  display.print(ProxRequirement);
  
  display.setCursor(12, 56);
  display.print("Device#: ");
  display.setCursor(80, 56);
  display.print(CSL);

  // Horizontal divider line between config and counters
  display.drawFastHLine(10, 70, 80, BLACK);

  // Display live event counters
  display.setCursor(12, 78);
  display.print("Approach: ");
  display.setCursor(80, 78);
  display.print(ApproachCount);  // Number of proximity detections
  
  display.setCursor(12, 90);
  display.print("Opening: ");
  display.setCursor(80, 90);
  display.print(OpenCount);  // Number of feeding events
  
  // Display battery indicator
  DisplayBattery();

  // Display current date and time from RTC
  DateTime now = rtc.now();
  display.setCursor(5, 128);
  display.fillRect(5, 127, 200, 60, WHITE);  // Clear date/time area
  
  // Format: MM-DD-YY HH:MM (with leading zeros)
  if (now.month() < 10)
    display.print('0');
  display.print(now.month());
  display.print("-");
  if (now.day() < 10)
    display.print('0');
  display.print(now.day());
  display.print("-");
  display.print(now.year() % 100);  // 2-digit year
  display.print("     ");
  if (now.hour() < 10)
    display.print('0');
  display.print(now.hour());
  display.print(":");
  if (now.minute() < 10)
    display.print('0');
  display.print(now.minute());
  display.refresh();

  // RED BUTTON: System reset (requires 1-second hold)
  if (red_touch == 0) {
    delay(1000);  // Wait 1 second
    if (red_touch == 0) {  // Still pressed after 1 second?
      // Display reset message
      display.fillRect(0, 0, 200, 150, WHITE);
      display.setCursor(50, 50);
      display.print("RESETTING...");
      display.refresh();
      
      // Four confirmation beeps
      Beep();
      delay(200);
      Beep();
      delay(200);
      Beep();
      delay(200);
      Beep();

      // Perform hardware reset
      NVIC_SystemReset();  // ARM Cortex-M0+ system reset
    }
  }

  display.refresh();
  inputtriggered = 0;  // Clear input flag
}


/*****************************************************************
 * SD CARD ERROR DISPLAY
 * 
 * Displays an error message when the SD card cannot be detected
 * or initialized. The device cannot operate without an SD card
 * for data logging, so this function halts execution indefinitely.
 * 
 * BEHAVIOR:
 * 1. Blinks LED on pin 13 (3 times)
 * 2. Blinks LED on pin 8 (3 times)
 * 3. Displays error message with riddle
 * 4. Enters infinite loop (halts program)
 * 
 * ERROR MESSAGE:
 * "Check SD card"
 * Plus a riddle hint: "I'm smaller than a mouse but I can fill
 * up a house. What am I?" (Answer: SD card / memory card)
 * 
 * TO RESOLVE:
 * - Check that SD card is properly inserted
 * - Verify SD card is formatted (FAT32 recommended)
 * - Check electrical connections to SD card slot
 * - Reset device after fixing issue
 *****************************************************************/
void DisplaySDError() {
  // Visual feedback: blink LEDs to indicate error
  Blink(13, 50, 3);  // Blink pin 13 LED
  delay(25);
  Blink(8, 50, 3);   // Blink pin 8 LED
  delay(25);
  
  // Clear screen and set large text for error message
  display.fillRect(0, 0, 168, 144, WHITE);
  display.setTextSize(2);
  display.setRotation(1);
  display.setCursor(5, 20);
  display.println("Check SD card");

  // Fun riddle for users to ponder while troubleshooting
  // (Answer: SD card / memory)
  display.setTextSize(1);
  display.setCursor(5, 60);
  display.println("I'm smaller than a mouse");
  display.setCursor(5, 70);
  display.println("but I can fill up a house.");
  display.setCursor(5, 85);
  display.println("What am I?");

  display.refresh();
  while (1);  // Halt program - SD card is required for operation
}

/*****************************************************************
 * MOUSE ANIMATION
 * 
 * Displays an animated mouse walking across the screen. This
 * animation plays when the user starts an experimental session
 * (presses red button on settings screen).
 * 
 * ANIMATION DETAILS:
 * - Mouse walks from left to right across the screen
 * - Alternates between two poses to create walking motion
 * - Components: head, ear, eye, body, tail, feet
 * - Each frame moves 15 pixels to the right
 * - 80ms delay between frames
 * 
 * WALKING MOTION:
 * - Even positions (i/10 % 2 == 0): One leg forward
 * - Odd positions: Other leg forward
 * - Tail and body position also varies slightly
 * 
 * PURPOSE:
 * Provides visual feedback that the system is transitioning
 * from configuration mode to active experimental mode.
 *****************************************************************/
void display_mouse() {
  display.setRotation(1);  // Landscape orientation for wider animation
  
  // Animate mouse walking across screen (left to right)
  for (int i = -50; i < 200; i += 15) {
    // Draw mouse head, ear, and eye (constant across all frames)
    display.fillRoundRect(i + 25, 82, 15, 10, 6, BLACK);  // Head
    display.fillRoundRect(i + 22, 80, 8, 5, 3, BLACK);    // Ear
    display.fillRoundRect(i + 30, 84, 1, 1, 1, WHITE);    // Eye
    
    // Alternate between two poses for walking animation
    if ((i / 10) % 2 == 0) {
      // POSE 1: Left foot forward
      display.fillRoundRect(i, 84, 32, 17, 10, BLACK);      // Body
      display.drawFastHLine(i - 8, 85, 18, BLACK);          // Tail (top)
      display.drawFastHLine(i - 8, 86, 18, BLACK);          // Tail (bottom)
      display.drawFastHLine(i - 14, 84, 8, BLACK);          // Tail end (top)
      display.drawFastHLine(i - 14, 85, 8, BLACK);          // Tail end (bottom)
      display.fillRoundRect(i + 22, 99, 8, 4, 3, BLACK);    // Front foot (forward)
      display.fillRoundRect(i, 97, 8, 6, 3, BLACK);         // Back foot
    } else {
      // POSE 2: Right foot forward
      display.fillRoundRect(i + 2, 82, 30, 17, 10, BLACK);  // Body (shifted)
      display.drawFastHLine(i - 6, 91, 18, BLACK);          // Tail (top)
      display.drawFastHLine(i - 6, 90, 18, BLACK);          // Tail (bottom)
      display.drawFastHLine(i - 12, 92, 8, BLACK);          // Tail end (top)
      display.drawFastHLine(i - 12, 91, 8, BLACK);          // Tail end (bottom)
      display.fillRoundRect(i + 15, 99, 8, 4, 3, BLACK);    // Front foot
      display.fillRoundRect(i + 8, 97, 8, 6, 3, BLACK);     // Back foot (forward)
    }
    
    display.refresh();
    delay(80);  // Frame delay (12.5 fps)
    display.fillRect(i - 25, 73, 95, 33, WHITE);  // Erase previous frame
  }
}

/*****************************************************************
 * DISPLAY BATTERY INDICATOR
 * 
 * Draws a graphical battery indicator on the display showing the
 * current LiPo battery charge level. Includes both a graphical
 * bar indicator and numerical voltage readout.
 * 
 * GRAPHIC LAYOUT:
 * ┌───────────┬─┐
 * │█████░░░░░ │+│  Battery outline with bars and terminal
 * └───────────┴─┘
 *     3.XX V        Voltage reading below
 * 
 * BATTERY LEVELS (based on LiPo voltage):
 * - 4 bars: > 3.85V  (Full charge, ~4.0-4.2V)
 * - 3 bars: > 3.70V  (Good charge)
 * - 2 bars: > 3.55V  (Medium charge, should recharge soon)
 * - 1 bar:  ≤ 3.55V  (Low charge, recharge recommended)
 * 
 * LOCATION: Top right corner of display
 * 
 * Called by both display_current_params() and update_display()
 * to show battery status on all screens.
 *****************************************************************/
void DisplayBattery() {
  ReadBatteryLevel();  // Update measuredvbat variable
  
  // Draw battery outline and terminal
  display.fillRect(119, 5, 40, 16, WHITE);   // Clear battery area
  display.drawRect(118, 4, 42, 18, BLACK);   // Main battery outline
  display.drawRect(159, 9, 6, 8, BLACK);     // Positive terminal (+)

  // Draw charge level bars based on voltage
  // LiPo voltage ranges: 4.2V=full, 3.7V=nominal, 3.0V=empty
  
  if (measuredvbat > 3.85) {
    // 4 BARS: Fully charged (>3.85V, close to 4.2V max)
    display.fillRect(122, 7, 7, 12, BLACK);  // Bar 1
    display.fillRect(131, 7, 7, 12, BLACK);  // Bar 2
    display.fillRect(140, 7, 7, 12, BLACK);  // Bar 3
    display.fillRect(149, 7, 7, 12, BLACK);  // Bar 4
  }
  else if (measuredvbat > 3.7) {
    // 3 BARS: Good charge level (3.7-3.85V)
    display.fillRect(121, 6, 26, 13, WHITE); // Clear bar 4 area
    display.fillRect(122, 7, 7, 12, BLACK);  // Bar 1
    display.fillRect(131, 7, 7, 12, BLACK);  // Bar 2
    display.fillRect(140, 7, 7, 12, BLACK);  // Bar 3
  }
  else if (measuredvbat > 3.55) {
    // 2 BARS: Medium charge (3.55-3.7V) - should recharge soon
    display.fillRect(121, 6, 26, 13, WHITE); // Clear bars 3-4 area
    display.fillRect(122, 7, 7, 12, BLACK);  // Bar 1
    display.fillRect(131, 7, 7, 12, BLACK);  // Bar 2
  }
  else {
    // 1 BAR: Low charge (≤3.55V) - recharge recommended
    display.fillRect(121, 6, 26, 13, WHITE); // Clear bars 2-4 area
    display.fillRect(122, 7, 7, 12, BLACK);  // Bar 1 only
  }

  // Display numerical voltage reading below battery icon
  display.fillRect(122, 26, 28, 12, WHITE);  // Clear voltage text area
  display.setCursor(122, 26);
  display.print(measuredvbat, 2);  // Print voltage with 2 decimal places
  display.print("V");
}
