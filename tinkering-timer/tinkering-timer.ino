#include "TimerOne.h"
#include "SevSeg.h"

int count = 0;

SevSeg sevseg;

void setup() {
  byte numDigits = 4;   
  // What pins are your "digit" lines hooked up to?
  byte digitPins[] = {2, 3, 4, 5};
  // What pins are your "segment" lines hooked up to?
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};

  // If COMMON_ANODE makes your display act weird, try COMMON_CATHODE
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);

  Timer1.initialize(100000);
  Timer1.attachInterrupt( tick );
}

void loop() {
  // Print the number in "count", put the decimal point in the 1st position
  sevseg.setNumber(count, 1);
  sevseg.refreshDisplay();
}

void tick() {
  count = (count + 1) % 10000;
}

