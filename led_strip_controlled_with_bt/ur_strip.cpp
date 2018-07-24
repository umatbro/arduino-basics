#include "ur_strip.h"


void UrStrip::begin() {
  Adafruit_NeoPixel::begin();
  Serial.begin(9600);
  Serial.print("begin BtSrip with ");
  Serial.print(this -> numPixels());
  Serial.println(" pixels");

  this -> mode = MODE_OFF;
}
