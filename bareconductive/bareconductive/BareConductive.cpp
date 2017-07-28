#include "BareConductive.h"
BareSensor::BareSensor(
  int sensor_pin,
  int receive_pin,
  int threshold)
: CapacitiveSensor(sensor_pin, receive_pin)
{
  this -> sensor_threshold = threshold;
}
