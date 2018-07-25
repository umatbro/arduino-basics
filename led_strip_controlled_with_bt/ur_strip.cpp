#include "ur_strip.h"


void UrStrip::begin() {
  Adafruit_NeoPixel::begin();
  Serial.begin(9600);
  Serial.print("begin BtSrip with ");
  Serial.print(this -> numPixels());
  Serial.println(" pixels");

  // set initial mode
}

/**
* Decide which function should be executed based on given command.
*
* Return pointer to a function to be exectued or NULL if command was not recognized.
*/
strip_action_function UrStrip::parse_command(const String& command) {
  // TODO
  // set brightness
  // if (command.substring(0, 1) == "b") {
  //   return NULL;
  // }
  // if (command == UrStripMode::MODE_OFF) {
  //   return this -> _mode_off;
  // }
  // if (command == UrStripMode::MODE_RAINBOW_CYCLE) {
  //   return this -> _mode_rainbow_cycle;
  // }
  // if (command == UrStripMode::MODE_WIPE) {
  //   return this -> _mode_color_wipe;
  // }

  // nothing matches - return NULL
  return NULL;
}


/**
* Input a value 0 to 255 to get a color value.
* The colours are a transition r-g-b back to r
*/
uint32_t UrStrip::wheel(byte wheel_pos) {
  wheel_pos = 255 - wheel_pos;
  if(wheel_pos < 85) {
    return UrStrip::Color(255 - wheel_pos * 3, 0, wheel_pos * 3);
  }
  if(wheel_pos < 170) {
    wheel_pos -= 85;
    return UrStrip::Color(0, wheel_pos * 3, 255 - wheel_pos * 3);
  }
  wheel_pos -= 170;
  return UrStrip::Color(wheel_pos * 3, 255 - wheel_pos * 3, 0);
}

// mode functions
void UrStrip::_mode_off() {
  for (uint16_t i = 0; i < this -> numPixels(); i++) {
    this -> setPixelColor(i, 0, 0, 0);
  }

  this -> show();
}


void UrStrip::_mode_rainbow_cycle(uint8_t wait) {
  for (uint16_t j = 0; j < 256; j++) { // cycles of all colors on wheel
    for (uint16_t i = 0; i < this -> numPixels(); i++) {
      this -> setPixelColor(i, UrStrip::wheel(((i * 256 / this -> numPixels()) + j) & 255));
    }
    this -> show();
    delay(wait);
  }
}


void UrStrip::_mode_rainbow(uint8_t wait) {
  for (uint16_t j = 0; j < 256; j++) {
    for (uint16_t i = 0; i < this -> numPixels(); i++) {
      this -> setPixelColor(i, UrStrip::wheel((i+j) & 255));
    }
    this -> show();
    delay(wait);
  }
}


void UrStrip::_mode_color_wipe(uint32_t color, uint8_t wait) {
  // dim  all pixels
  for (uint16_t i = 0; i < this -> numPixels(); i++) {
    this -> setPixelColor(i, 0, 0, 0);
  }
  this -> show();

  // sequentially show all pixels
  for (uint16_t i = 0; i < this -> numPixels(); i++) {
    this -> setPixelColor(i, color);
    this -> show();
    delay(wait);
  }
}
