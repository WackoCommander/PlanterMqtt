#pragma once

#include <string>
#include "SoilMoistureSensor.h"

class Plant
{
public:
    Plant(std::string name);
    int AttachSensors(int soil_sensor_pin_power, int soil_sensor_pin_reading);
private:
    std::string name_;
    SoilMoistureSensor sensor_soil_moisture_;
};