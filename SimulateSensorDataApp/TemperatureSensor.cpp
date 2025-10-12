#include "TemperatureSensor.h"
#include "StoreData.h"

TemperatureSensor::TemperatureSensor(const Vector2D& pos) : WorldObject( pos ), _temperature(20.f), 
_type(WorldObject::TYPE::TEMPERATURE_SENSOR), _name("temperatureSensor"){}

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

int TemperatureSensor::range() const
{
	return -1; //useless method
}

void TemperatureSensor::runTick( Person* person )
{

}

void TemperatureSensor::storeData( StoreData& storeData) const
{
	storeData.store( this );
}

float TemperatureSensor::data() const
{
	return _temperature;
}