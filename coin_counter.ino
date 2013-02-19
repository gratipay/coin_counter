#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include <OneButton.h>


Adafruit_7segment counter = Adafruit_7segment();
OneButton resetButton(11, true);
OneButton incrementSwitch(3, true);
int count;

// Logic

void reset()
{
  count = 0;
  counter.print(0, DEC);        // turns everything off
  counter.writeDigitNum(4, 0);  // writes a zero on the right
  counter.writeDisplay();       // == flush
}

void increment()
{
  count = count == 9999 ? 0 : count + 1;
  counter.print(count, DEC);
  counter.writeDisplay();
}


// Arduino Hooks

void setup()
{
  counter.begin(0x70); // ???
  counter.setBrightness(0);
  
  reset();
  
  incrementSwitch.setClickTicks(10);
  incrementSwitch.attachClick(increment);
  
  resetButton.setPressTicks(10);
  resetButton.attachPress(reset);
}

void loop()
{
  resetButton.tick();
  incrementSwitch.tick();
  delay(1);
}
