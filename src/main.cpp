#include <Arduino.h>
#include "ussensor.h"

Ultrasonic us1(23, 22);

void setup() {
  // setup serial connection
  Serial.begin(115200);
}

void loop() {
  // get distance each second
  float dist = us1.get_distance();
  printf("Distance: %f \n", dist);
  delay(1000);
}