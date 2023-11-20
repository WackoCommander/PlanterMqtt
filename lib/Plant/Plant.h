#pragma once

#include <string>
#include "SoilMoistureSensor.h"

class Plant
{
public:
    Plant(std::string name);
    // Plant(Plant &copy);
    int AttachSensors(int soil_sensor_pin_power, int soil_sensor_pin_reading);
    std::string GetName();
    int GetSoilMoisture();
protected:
    std::string name_;
private:
    SoilMoistureSensor sensor_soil_moisture_;
};