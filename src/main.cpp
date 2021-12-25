#include <Arduino.h>
#include "ussensor.h"

Ultrasonic us1(23, 22); // setting up distance sensor on given pins

const int movedetec = 4; // movement detector signal pin
int moveCurrent = LOW;
int movePrev = LOW;

void setup() {
  // setup serial connection
  Serial.begin(9600);
  pinMode(movedetec, INPUT);
}

void loop() {
  // get distance each second
  /*
  int dist = int(us1.get_distance());
  printf("Distance: %d \n", dist);
  delay(1000);
  */
  movePrev = moveCurrent;
  moveCurrent = digitalRead(movedetec);
  if(movePrev == LOW && moveCurrent == HIGH) {
    Serial.println("Motion detected");
  } else if (movePrev == HIGH && moveCurrent == LOW) {
    Serial.println("Motion has stopped");
  }
}