#include "modes.h"

void fill_pink_and_white(Adafruit_NeoPixel& line)
{
  for (int i = 0; i < line.numPixels(); i++) 
  {
    if (i%2 == 0)
    {
      line.setPixelColor(i, PINK);
    }
    else
    {
      line.setPixelColor(i, WHITE);
    }
    line.show();
    delay(500);
  }
  line.clear();
  line.show();
}

