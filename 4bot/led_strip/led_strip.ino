#include <Adafruit_NeoPixel.h>
#include "modes.h"

#define LED_DATA_PIN 4

const short num_of_leds = 8;

Adafruit_NeoPixel line = Adafruit_NeoPixel(num_of_leds, LED_DATA_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  line.begin();
}

void loop() {
//  fill_pink_and_white(line);
  switch_pink_white(line);
}
