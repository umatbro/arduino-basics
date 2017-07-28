#include <CapacitiveSensor.h>

class BareSensor : public CapacitiveSensor{
private:
  
public:
  int sensor_threshold;
  BareSensor(
    int sensor_pin,
    int receive_pin,
    int threshold=5000);
};
