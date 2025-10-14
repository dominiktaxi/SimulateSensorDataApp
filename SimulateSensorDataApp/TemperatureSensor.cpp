#include "TemperatureSensor.h"
#include "HandleData.h"

TemperatureSensor::TemperatureSensor(const Vector2D& pos) : WorldObject( pos ), _temperature(20.f), 
_type(WorldObject::TYPE::TEMPERATURE_SENSOR), _name("temperatureSensor"), _ticks(0){}

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



void TemperatureSensor::runTick( const World* world, HandleData& handleData )
{
	if ( _ticks > 100 )
	{
		_temperature = world->temperature();
		handleData.store( this );
		_ticks = 0;
	}
	_ticks++;
}



float TemperatureSensor::data() const
{
	return _temperature;
}