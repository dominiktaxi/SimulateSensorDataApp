#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor(uint8_t posX, uint8_t posY) : WorldObject( posX, posY ), _temperature(20.f), 
_type(WorldObject::TYPE::TEMPERATURE_SENSOR){}

const Vector2D& TemperatureSensor::position() const
{
	return _position;
}

void TemperatureSensor::sensor()
{
	
}

WorldObject::TYPE TemperatureSensor::type() const
{
	return TemperatureSensor::TYPE::TEMPERATURE_SENSOR;
}