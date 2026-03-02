# Migration Guide: Converting CastleCode to TumbleFeeder Library

This guide shows how to convert your existing CastleCode sketch to use the TumbleFeeder library.

## Step 1: Install the Library

Copy the `TumbleFeeder` folder to your Arduino libraries directory.

## Step 2: Update Your Main Sketch Header

### Before (a_header.h):
```cpp
//INCLUDE LIBRARIES
#include <Servo.h>
// ... other includes

/********************************************************
  Initialize variables
********************************************************/
unsigned long rightstart;
unsigned long leftstart;
int currentpos = 0;
int leftPokeCount = 0;
int rightPokeCount = 0;
int leftPokeDur = 0;
int rightPokeDur = 0;
int FeederCount = 0;
int leftFeederDur = 0;
int FR=1;
// ... other variables

/********************************************************
  Initialize servo
********************************************************/
Servo myservo;
```

### After:
```cpp
//INCLUDE LIBRARIES
#include <TumbleFeeder.h>  // Add this
#include <Servo.h>  // Keep if needed elsewhere
// ... other includes

/********************************************************
  Initialize TumbleFeeder
********************************************************/
TumbleFeeder feeder;

/********************************************************
  Keep other variables
********************************************************/
unsigned long menustart;
bool SessionStarted = false;
const unsigned long display_interval = 100;
unsigned long next_interval = 0;
unsigned long open_duration = 60;
int on_hour;
int off_hour;
bool mode = 0;
// ... other non-feeder variables
```

## Step 3: Update Setup() in Main Sketch

### Before (Startup.ino):
```cpp
void setup() {
  // ... RTC, SD, display setup
  
  pinMode(13, OUTPUT);
  // ... other pin setups
  
  attachInterrupt(digitalPinToInterrupt(A2), left_interrupt, FALLING);
  attachInterrupt(digitalPinToInterrupt(A0), right_interrupt, FALLING);
  attachInterrupt(digitalPinToInterrupt(A1), feed_interrupt, FALLING);
}
```

### After:
```cpp
void setup() {
  // ... RTC, SD, display setup (unchanged)
  
  // Initialize feeder
  feeder.begin(closedpos, openpos);  // Use your position values
  feeder.setFR(FR);
  feeder.setOpenDuration(open_duration);
  
  // Register callbacks
  feeder.setLogCallback(logData);
  feeder.setDisplayCallback(update_display);
  
  // Attach interrupts (same as before)
  attachInterrupt(digitalPinToInterrupt(A2), left_interrupt, FALLING);
  attachInterrupt(digitalPinToInterrupt(A0), right_interrupt, FALLING);
  attachInterrupt(digitalPinToInterrupt(A1), feed_interrupt, FALLING);
  
  // ... rest of setup
}
```

## Step 4: Update Interrupt Handlers

### Before (InterruptRoutines.ino):
```cpp
void left_interrupt() {
  left_touch = 1;
}

void right_interrupt() {
  right_touch = 1;
}

void feed_interrupt() {
  feed_touch = 1;
}
```

### After:
```cpp
void left_interrupt() {
  feeder.handleLeftTouch();
}

void right_interrupt() {
  feeder.handleRightTouch();
}

void feed_interrupt() {
  feeder.handleFeederTouch();
}
```

## Step 5: Replace Feeder Functions

### Delete or comment out MoveFeeder.ino
The library now handles all feeder movement. Delete these functions:
- `feeder_open()`
- `feeder_close()`
- `shake()`
- `shake_food()`

If you need them elsewhere, use:
```cpp
feeder.feederOpen();
feeder.feederClose();
feeder.shake();
feeder.shakeFood();
```

## Step 6: Update run() Function

### Before (run.ino):
```cpp
void run() {
  unsigned long current = millis();

  if (current >= next_interval && mode == 0) {
    check_inputs(closedpos, openpos, open_duration);  
    next_interval = current + display_interval;
  }

  else if (current >= next_interval && mode == 1) {
    free_inputs(closedpos, openpos);
    next_interval = current + display_interval;
    if (wake_counter % 180 == 0) {
      shake_food();
    }
  }
}
```

### After:
```cpp
void run() {
  unsigned long current = millis();

  if (current >= next_interval && mode == 0) {
    feeder.checkInputs(open_duration);  // Simplified!
    next_interval = current + display_interval;
  }

  else if (current >= next_interval && mode == 1) {
    feeder.freeInputs();  // Simplified!
    next_interval = current + display_interval;
    if (wake_counter % 180 == 0) {
      feeder.shakeFood();
    }
  }
}
```

## Step 7: Delete Checkinputs.ino

The library handles all input checking. Delete these functions:
- `check_inputs()`
- `checkLeft()`
- `checkRight()`
- `checkFeeder()`
- `free_inputs()`

## Step 8: Update Variable References

Anywhere you access feeder counters, you can use either:

### Option A: Direct access (backward compatible)
```cpp
// Works the same as before
if (feeder.leftPokeCount > 10) {
  // do something
}
```

### Option B: Getter methods (recommended)
```cpp
if (feeder.getLeftPokeCount() > 10) {
  // do something
}
```

## Step 9: Update Display.ino

### Before:
```cpp
void update_display() {
  display.setCursor(0, 0);
  display.print("L:");
  display.print(leftPokeCount);
  display.print(" R:");
  display.print(rightPokeCount);
  display.print(" F:");
  display.print(FeederCount);
  display.refresh();
}
```

### After:
```cpp
void update_display() {
  display.setCursor(0, 0);
  display.print("L:");
  display.print(feeder.leftPokeCount);  // or feeder.getLeftPokeCount()
  display.print(" R:");
  display.print(feeder.rightPokeCount);  // or feeder.getRightPokeCount()
  display.print(" F:");
  display.print(feeder.FeederCount);     // or feeder.getFeederCount()
  display.refresh();
}
```

## Step 10: Update LogData.ino

### Before:
```cpp
void logData() {
  logfile.print(millis());
  logfile.print(",");
  logfile.print(leftPokeCount);
  logfile.print(",");
  logfile.print(rightPokeCount);
  logfile.print(",");
  logfile.print(FeederCount);
  // ... etc
}
```

### After:
```cpp
void logData() {
  logfile.print(millis());
  logfile.print(",");
  logfile.print(feeder.leftPokeCount);
  logfile.print(",");
  logfile.print(feeder.rightPokeCount);
  logfile.print(",");
  logfile.print(feeder.FeederCount);
  // ... etc
}
```

## Complete Conversion Checklist

- [ ] Install TumbleFeeder library
- [ ] Add `#include <TumbleFeeder.h>` to header
- [ ] Create `TumbleFeeder feeder;` object
- [ ] Remove old feeder-related global variables
- [ ] Update `setup()` with `feeder.begin()` and callbacks
- [ ] Update interrupt handlers to call `feeder.handleXXX()`
- [ ] Delete/comment out MoveFeeder.ino
- [ ] Update `run()` to use `feeder.checkInputs()`
- [ ] Delete/comment out Checkinputs.ino
- [ ] Update all variable references to `feeder.variableName`
- [ ] Test on hardware!

## Benefits After Migration

✅ **Cleaner code**: Feeder logic is encapsulated  
✅ **Reusable**: Use the library across multiple projects  
✅ **Maintainable**: Bug fixes in one place  
✅ **Flexible**: Easy to swap between FR schedules  
✅ **Professional**: Standard Arduino library format  

## Troubleshooting

### "Feeder not responding"
- Check servo positions: `feeder.setPositions(0, 150)`
- Verify interrupts are attached correctly
- Check pin connections match hardcoded pins

### "Counts not incrementing"
- Ensure callbacks are registered: `feeder.setLogCallback(logData)`
- Check ISRs are calling `feeder.handleXXX()` methods
- Verify touch sensors are wired correctly (A2, A0, A1)

### "Compile errors"
- Make sure library is in Arduino libraries folder
- Restart Arduino IDE after installing library
- Check you removed duplicate function definitions

## Need Help?

Open an issue on GitHub with:
- Your error message
- Code snippet showing the problem
- What you've already tried
