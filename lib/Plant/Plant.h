#pragma once

class Plant
{
public:
    Plant();
    void SetSoilMoisture(int);
    void SetTemperature(int);
    void SetHumidity(int);
private:
    int soil_moisture_;
    int temperature_;
    int humidity_;
};