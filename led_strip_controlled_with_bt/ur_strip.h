#ifndef UR_STRIP_H
#define UR_STRIP_H

#include <Adafruit_NeoPixel.h>
#include "utils.h"

namespace UrStripMode {
  const String MODE_OFF = String("0");
  const String MODE_ON_WHITE = String("1");
  const String MODE_RAINBOW_CYCLE = String("2");
  const String MODE_WIPE = String("3");
}

namespace UrStripColor {
  const uint32_t COLOR_WHITE = Adafruit_NeoPixel::Color(255, 255, 255);
}

 // pointer for storing strip action functions
 // those functions will be called with "wait" parameter (telling about animation speed)
typedef void (*strip_action_function)(uint8_t);


class UrStrip : public Adafruit_NeoPixel {
  public:
    // inhehrit constructor
    // using Adafruit_NeoPixel::Adafruit_NeoPixel;
    UrStrip(uint16_t n, uint8_t port=6, neoPixelType t=NEO_GRB + NEO_KHZ800);

    // static functions
    static uint32_t wheel(byte wheel_pos);

    // functions
    void begin();

    // TODO this is not correct
    void parse_command(String);
    // void (*play_mode)(int mode);
    void play_mode();

  // private:
    uint32_t _color;
    uint8_t _wait;
    String _mode;

    void _mode_off();
    void _mode_rainbow_cycle(uint8_t wait);
    void _mode_rainbow(uint8_t wait);
    void _mode_color_wipe(uint32_t color, uint8_t wait);
};

#endif
