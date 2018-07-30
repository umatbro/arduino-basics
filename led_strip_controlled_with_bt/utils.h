#ifndef UTILS_H
#define UTILS_H

#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
 #include <pins_arduino.h>
#endif
#include <ctype.h>

namespace Utils {
    bool is_integer(String check_val);
}

#endif