#ifndef USSENSOR_H
#define USSENSOR_H

#include "Arduino.h"

// Header File for Ultrasonic Distance sensor
class Ultrasonic {
 public:
    Ultrasonic(int trigpin, int echopin);

    float get_distance();

    float get_clean_distance();

    void set_echopin(int pin);

    void set_trigpin(int pin);

 private:
    float m_distance;
    byte m_ECHOPIN;
    byte m_TRIGPIN;
};

#endif