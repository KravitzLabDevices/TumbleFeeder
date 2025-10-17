/*****************************************************************
 * REAL-TIME CLOCK FUNCTIONS
 * 
 * This file contains functions for interacting with the DS3231
 * Real-Time Clock module. The RTC maintains accurate time even
 * when the device is powered off (it has a backup battery).
 * 
 * The RTC is used for:
 * - Timestamping data log entries
 * - Creating timestamped filenames
 * - Displaying current date/time on screen
 *****************************************************************/

/*****************************************************************
 * SD CARD TIMESTAMP CALLBACK
 * 
 * This function is called by the SdFat library whenever it needs
 * to timestamp a file (creation, modification). By providing this
 * callback, files on the SD card will have accurate timestamps
 * from the RTC instead of default placeholder values.
 * 
 * Registered in Startup.ino with:
 *   SdFile::dateTimeCallback(dateTime);
 * 
 * PARAMETERS:
 * - date: Pointer to uint16_t that receives FAT-format date
 * - time: Pointer to uint16_t that receives FAT-format time
 * 
 * FAT FORMAT:
 * Date: bits 15-9=year-1980, bits 8-5=month, bits 4-0=day
 * Time: bits 15-11=hour, bits 10-5=minute, bits 4-0=second/2
 * 
 * The FAT_DATE and FAT_TIME macros handle the bit packing.
 *****************************************************************/
void dateTime(uint16_t* date, uint16_t* time) {
  DateTime rnow = rtc.now();  // Get current time from RTC
  
  // Pack date into FAT format (year, month, day)
  *date = FAT_DATE(rnow.year(), rnow.month(), rnow.day());

  // Pack time into FAT format (hour, minute, second)
  *time = FAT_TIME(rnow.hour(), rnow.minute(), rnow.second());
}
