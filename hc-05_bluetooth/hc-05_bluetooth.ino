/**
 * This example allows user to read messages received by bluetooth and send messages to bluetooth device.
 * 
 * Messages sent from PC are displayed on device and vice versa.
 */

#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 2); // RX, TX
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

char c;
void loop()
{
  if (mySerial.available()) {
    c = mySerial.read();
    Serial.print(c);
  }

  if (Serial.available()) {
    c = Serial.read();
    mySerial.print(c);
  }
}

