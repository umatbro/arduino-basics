#include <CapacitiveSensor.h>

class BareSensor : public CapacitiveSensor{
public:
  BareSensor(int sensor_pin, int receive_pin);
};

