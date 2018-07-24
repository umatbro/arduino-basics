#include "ur_strip.h"


void UrStrip::begin() {
  Adafruit_NeoPixel::begin();
  Serial.begin(9600);
  Serial.print("begin BtSrip with ");
  Serial.print(this -> numPixels());
  Serial.println(" pixels");

  this -> mode = MODE_OFF;
}


int add(int a, int b) {
  return a + b;
}

int sub(int a, int b) {
  return a - b;
}

/**
* Function to test function pointers
* reference: http://www.learncpp.com/cpp-tutorial/78-function-pointers/
*/
void UrStrip::test() {
  // create function pointer
  int (*fncPtr)(int, int);

  // assign function pointer to add function
  fncPtr = add;

  // func = add;
  int a = 1;
  int b = 2;

  // call function pointer (pointer is pointing to add function)
  int result = (*fncPtr)(a, b);

  Serial.println(int(fncPtr));
  Serial.println((*fncPtr)(a, b));

  fncPtr = sub;
  Serial.println((*fncPtr)(a, b));
}
