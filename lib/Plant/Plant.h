#pragma once

#include <string>
#include "SoilMoistureSensor.h"
#include <DHT.h>
class Plant
{
public:
    Plant(std::string name);
    // Plant(Plant &copy);
    int AttachSensors(int soil_sensor_pin_power, int soil_sensor_pin_reading, int temp_humidity_sensor_pin);
    std::string GetName();
    int GetSoilMoisture();
    int GetTemperature();
    int GetHumidity();
protected:
    std::string name_;
private:
    SoilMoistureSensor sensor_soil_moisture_;
    int moisture_;
    DHT* dht_;
    int temperature_;
    int humidity_;
};