#include "Plant.h"


Plant::Plant(std::string name)
: name_(name)
{
}

int Plant::AttachSensors(int soil_sensor_pin_power, int soil_sensor_pin_reading)
{
    Serial.println("Attaching soil moisture sensor..");
    if(!sensor_soil_moisture_.Attach(soil_sensor_pin_power, soil_sensor_pin_reading))
    {
        Serial.println("Attachment to soil moisture sensor successful...");
        return 0;
    }
    return 1;
}

int Plant::GetSoilMoisture()
{
    
    moisture_ = sensor_soil_moisture_.GetReading();
    return moisture_;
}


std::string Plant::GetName()
{
    return name_;
}
