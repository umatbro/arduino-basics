#include "ur_strip.h"
#include <SoftwareSerial.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 9
#define NUM_LEDS 37
#define BT_TX_PIN 2
#define BT_RX_PIN 3

SoftwareSerial btSerial(BT_RX_PIN, BT_TX_PIN);

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
UrStrip strip = UrStrip(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  Serial.begin(9600);

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  btSerial.begin(9600);
}

String mode = "1";

void loop() {

  if (btSerial.available() > 0) {
    String instruction = btSerial.readStringUntil('\r');
    btSerial.print("Received message: " + instruction);

    mode = instruction;
  }

  if (mode == "0") {
    strip._mode_off();
  } else if (mode == "1") {
    strip._mode_rainbow_cycle(20);
  } else if (mode == "2") {
    strip._mode_color_wipe(0xff4500, 20);
  } else {
    strip._mode_color_wipe(0xffffff, 20);
  }
}
