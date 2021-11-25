#include <Arduino.h>
#include "ussensor.h"

Ultrasonic us1(23, 22);

void setup() {
  // setup serial connection
  Serial.begin(9600);
}

void loop() {
  // get distance each second
  int dist = int(us1.get_distance());
  printf("Distance: %d \n", dist);
  delay(1000);
}