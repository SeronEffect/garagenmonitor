#ifndef USSENSOR_H
#define USSENSOR_H

// Header File for Ultrasonic Distance sensor
class US
{
private:
    float m_distance;
    int m_ECHOPIN;
    int m_TRIGPIN;

public:
    US(int trigpin, int echopin);

    float get_distance() {return m_distance;}

    float get_clean_distance() {return m_distance;}

    void set_echopin(int pin);

    void set_trigpin(int pin);
};

#endif