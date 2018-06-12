#include "DHT.h"
#define DHT_PIN A5

DHT dht;

void setup() {
  Serial.begin(9600);
  dht.setup(DHT_PIN);
}

void loop() {
  int humidity = dht.getHumidity();
  Serial.print(humidity);
  Serial.print("%RH | ");
  
  int temperature = dht.getTemperature();
  Serial.print(temperature);
  Serial.println("*C");
 
  delay(2000); 
}
