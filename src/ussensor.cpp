#include "Arduino.h"
#include "ussensor.h"
// Source-File for Ultrasonic sensor classes. Each sensor instance has its 2 pins and some utility functions.

// US constructor
Ultrasonic::Ultrasonic(int trigpin, int echopin) {
    this->m_TRIGPIN = trigpin;
    this->m_ECHOPIN = echopin;
    pinMode(m_TRIGPIN, OUTPUT);
    pinMode(m_ECHOPIN, INPUT);
}

// Memberfunctions
// debug function to re-set echo pin occupation
void Ultrasonic::set_echopin(int pin) {
    this->m_ECHOPIN = pin;
}

// debug function to re-set trigger pin occupation
void Ultrasonic::set_trigpin(int pin)
{
    this->m_TRIGPIN = pin;
}

// getter for distance from sensor and returns as float
float Ultrasonic::get_distance()
{
    digitalWrite(m_TRIGPIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(m_TRIGPIN, LOW);
    // get signal duration in microsecs
    float duration = pulseIn(m_ECHOPIN, HIGH);
    // calc distance from duration
    float distance = duration /53;
    return distance;
}