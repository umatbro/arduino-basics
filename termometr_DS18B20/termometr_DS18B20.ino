#include <OneWire.h>
#include <DallasTemperature.h>

#define TERMO_PIN 9

// remember to put 4.7k resistor between data pin and VCC

OneWire oneWire(TERMO_PIN);
DallasTemperature sensors(&oneWire);

void setup(void) {
   Serial.begin(9600);
   sensors.begin();
}

void loop() {
  sensors.requestTemperatures();

  Serial.print("Current temperature: ");
  Serial.println(sensors.getTempCByIndex(0));
  delay(500);
}
