#include "Plant.h"


Plant::Plant(std::string name)
: name_(name)
{
}

int Plant::AttachSensors(int soil_sensor_pin_power, int soil_sensor_pin_reading, int temp_humidity_pin)
{
    Serial.println("Attaching soil moisture sensor..");
    if(!sensor_soil_moisture_.Attach(soil_sensor_pin_power, soil_sensor_pin_reading))
    {
        Serial.println("Attachment to soil moisture sensor successful...");
        return 0;
    }

    dht_ = new DHT(temp_humidity_pin, DHT11);
    return 1;
}

int Plant::GetSoilMoisture()
{
    
    moisture_ = sensor_soil_moisture_.GetReading();
    return moisture_;
}

int Plant::GetTemperature()
{
    temperature_ = dht_->readTemperature();
    return temperature_;
}

std::string Plant::GetName()
{
    return name_;
}
