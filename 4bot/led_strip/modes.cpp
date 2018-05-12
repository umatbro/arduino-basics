#include "modes.h"

bool start = 0;

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

void switch_pink_white(Adafruit_NeoPixel& line)
{
  start = !start;
  for (int i = 0; i < line.numPixels(); i++)
  {
    line.setPixelColor(
      i,
      (i + start) % 3 == 0 ? WHITE : PINK
    );
  }
  line.show();
  delay(1000);
}

