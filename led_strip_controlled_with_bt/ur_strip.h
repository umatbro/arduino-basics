#ifndef UR_STRIP_H
#define UR_STRIP_H

#include <Adafruit_NeoPixel.h>

namespace UrStripMode {
  const String MODE_OFF = "0";
  const String MODE_ON_WHITE = "1";
  const String MODE_RAINBOW_CYCLE = "2";
  const String MODE_WIPE = "3";
}

 // pointer for storing strip action functions
 // those functions will be called with "wait" parameter (telling about animation speed)
typedef void (*strip_action_function)(uint8_t);


class UrStrip : public Adafruit_NeoPixel {
  // typedef void (*strip_action_function)(uint8_t);

  public:
    // properties
    // strip_action_function mode;
    // inhehrit constructor
    using Adafruit_NeoPixel::Adafruit_NeoPixel;

    // static functions
    static uint32_t wheel(byte wheel_pos);

    // functions
    void begin();

    // TODO this is not correct
    strip_action_function parse_command(const String&);
    // void (*play_mode)(int mode);

  // private:
    void _mode_off();
    void _mode_rainbow_cycle(uint8_t wait);
    void _mode_rainbow(uint8_t wait);
    void _mode_color_wipe(uint32_t color, uint8_t wait);
};

#endif
