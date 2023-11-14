#pragma once

#include <Arduino.h>

class SoilMoistureSensor
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