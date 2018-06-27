#include <RH_ASK.h>
#include <SPI.h>

const int LED_PIN = A5;
const int RX_PIN = 9;

// constructor takes these parameters:
// * communication speed (bits  per sec)
// * pin for receiver
// * transmitter data pin
// * transmitter  controller (not used in the example)
RH_ASK driver(2000, RX_PIN, 9, 10);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
