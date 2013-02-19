#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include <OneButton.h>


Adafruit_7segment counter = Adafruit_7segment();
OneButton incrementSwitch(3, true);

void setup()
{
  counter.begin(0x70); // ???
  counter.setBrightness(0);
  
  reset();
  
  incrementSwitch.setClickTicks(10);
  incrementSwitch.attachClick(increment);
}

int count = 0;

void reset()
{
  counter.writeDigitNum(4, 0);
  counter.writeDisplay();
}

void increment()
{
  count = count == 9999 ? 0 : count + 1;
  counter.print(count, DEC);
  counter.writeDisplay();
}

void loop()
{
  incrementSwitch.tick();
  delay(1);
}
