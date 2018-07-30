#include "ur_strip.h"

using namespace UrStripColor;
using namespace UrStripMode;

UrStrip::UrStrip(uint16_t n, uint8_t port, neoPixelType t) : Adafruit_NeoPixel(n, port, t) {
  this -> _color = COLOR_WHITE;
  this -> _wait = 20;
  this -> _mode = MODE_OFF;
}


void UrStrip::begin() {
  Adafruit_NeoPixel::begin();
  Serial.begin(9600);
  Serial.print("begin BtSrip with ");
  Serial.print(this -> numPixels());
  Serial.println(" pixels");

  // set initial mode
}

/**
* Decide which function should be done based on given command.
*/
void UrStrip::parse_command(String command) {
  using Utils::is_integer;

  if (command.substring(0, 1) == "b") { // changing brightness
    Serial.println("UrStrip::parse_command: You are changing brightness");
    // call setBrightness here
  }
  else if (is_integer(command)) {
    this -> _mode = command;
    Serial.print("Set mode ");
    Serial.println(this -> _mode);
  } else {
    Serial.print("Error parsing command: ");
    Serial.println(command);
  }
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


void UrStrip::play_mode() {
  using namespace UrStripMode;
  if (this -> _mode == MODE_OFF) this -> _mode_off();
  if (this -> _mode == MODE_RAINBOW_CYCLE) this -> _mode_rainbow_cycle(this -> _wait);
  if (this -> _mode == MODE_WIPE) this -> _mode_color_wipe(this -> _color, this -> _wait);
  this -> _mode_off();
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
