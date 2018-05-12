#ifndef MODES_H
#define MODES_H
#include <Adafruit_NeoPixel.h>

const uint32_t PINK = Adafruit_NeoPixel::Color(100, 0, 100);
const uint32_t WHITE = Adafruit_NeoPixel::Color(69, 69, 69);

void fill_pink_and_white(Adafruit_NeoPixel& line);
void switch_pink_white(Adafruit_NeoPixel& line);

#endif
