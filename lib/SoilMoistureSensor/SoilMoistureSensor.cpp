#include "SoilMoistureSensor.h"

SoilMoistureSensor::SoilMoistureSensor()
{

}

int SoilMoistureSensor::Attach(int pin_power, int pin_reading)
{
    pin_power_ = pin_power;                     // Initialise private members.
    pin_reading_ = pin_reading;
    pinMode(pin_power_, OUTPUT);                // Activate the sensor. Initially keep it off.
    digitalWrite(pin_power_, LOW);
    attached_ = true;
    return 0;
}

int SoilMoistureSensor::GetReading()
{
    if (attached_ == false)                     // If sensor is not attached. Return.
    {
        return 0;
    }
    digitalWrite(pin_power_, HIGH);             // Turn the sensor on.
    delay(10);                                  // Allow power to settle. 
    int reading = analogRead(pin_reading_);     // Get soil moisture reading. 
    digitalWrite(pin_power_, LOW);              // Turn the sensor off.
    return reading;
}