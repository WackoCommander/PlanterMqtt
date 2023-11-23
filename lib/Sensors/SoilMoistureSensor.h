#pragma once

#include <Arduino.h>
#include "Sensor.h"
class SoilMoistureSensor : public Sensor
{
    public:
        SoilMoistureSensor();
        int Attach(int, int);
        int GetReading();
    private:
        bool attached_;
        int pin_power_;
        int pin_reading_;
};