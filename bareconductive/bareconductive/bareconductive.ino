/*
  This code will allow to toggle on/off pin just by touching conductive sensor (e.g. foil)
*/
#include <CapacitiveSensor.h>

CapacitiveSensor sensor = CapacitiveSensor(4,2);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin - it's connected with a piece of foil
int pin = 7;
long sensor_thershold = 5000;

void setup()
{
   pinMode(pin,OUTPUT);
   sensor.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
}

boolean on_off_flag = false;
long curr_val = 0;
long prev_val = 0;

void loop()
{
    long start = millis();
    long total1 =  sensor.capacitiveSensor(30);
    curr_val = total1;
    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");

    Serial.println(total1);                  // print sensor output

    if(curr_val > sensor_thershold && prev_val < sensor_thershold){
      on_off_flag = !on_off_flag;
    }

    digitalWrite(pin, on_off_flag);
    delay(10);                             // arbitrary delay to limit data to serial port
    prev_val = curr_val;
}
