#include "ussensor.hpp"

// Source-File for Ultrasonic sensor classes. Each sensor instance has its 2 pins and some utility functions.

// US constructor
US::US(int trigpin, int echopin) {
    set_echopin(echopin);
    set_trigpin(trigpin);
}

// Memberfunctions
// debug function to re-set echo pin occupation
void US::set_echopin(int pin) {
    m_ECHOPIN = pin;
}

// debug function to re-set trigger pin occupation
void US::set_trigpin(int pin) {
    m_TRIGPIN = pin;
}

// getter for distance from sensor and returns as float
float US::get_distance() {
    // TODO content
}

// getter for multiple distance samples, put and sorted into array to delete potential noise samples
float US::get_clean_distance() {
    // TODO content
}