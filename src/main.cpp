#include <Arduino.h>
#include "ussensor.h"

Ultrasonic us1(23, 22); // setting up distance sensor on given pins

const int movedetec = 4; // movement detector signal pin
int moveCurrent = LOW;
int movePrev = LOW;

const int laser = 36; // laser bridge analog pin
int laservalue = 0; // ldr value
int laservalueOld = 0;  // old ldr value

const int RED = 12;
const int YELLOW = 14;
const int GREEN = 27;

bool parked;

bool checkMotion() {
  movePrev = moveCurrent;               // set prev as old value
  moveCurrent = digitalRead(movedetec); // sets current as new value
  if (movePrev == LOW && moveCurrent == HIGH) // positive flank
  { 
    return true;
  }
  else {
    return false;
  }
}

void parkingRoutine() {
    laservalueOld = laservalue;
    laservalue = analogRead(laser);
    if((laservalue-laservalueOld) > 500) {
      digitalWrite(GREEN, LOW);
      digitalWrite(YELLOW, LOW);
      digitalWrite(RED, HIGH);
      parked = true;
    }
}

void setup() {

  // setup serial connection
  Serial.begin(9600);
  pinMode(movedetec, INPUT);
  pinMode(laser, INPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
}

void loop() {
  // get distance each second

  int dist = int(us1.get_distance());
  Serial.println("Distance: " + dist);
  delay(500);
  
  /*
  parked = false;
  if(checkMotion()) {
    while(!parked) {

    }
    parkingRoutine();
  } else {
    delay(3000);
  }
  */
}