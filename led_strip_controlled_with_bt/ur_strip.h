#ifndef UR_STRIP_H
#define UR_STRIP_H

#include <Adafruit_NeoPixel.h>

#define MODE 1000
#define MODE_OFF MODE + 1


class UrStrip : public Adafruit_NeoPixel {
  public:
    int mode;
    // inhehrit constructor
    using Adafruit_NeoPixel::Adafruit_NeoPixel;

    void begin();
    // void (*play_mode)(int mode);
    void test();
};

#endif
