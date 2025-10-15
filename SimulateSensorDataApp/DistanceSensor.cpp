#include "DistanceSensor.h"
#include "HandleData.h"
#include "Utils.h"
#include "Person.h"
#include <iostream>
#include <windows.h>
#include <thread>

DistanceSensor::DistanceSensor( const Vector2D& pos ) : WorldObject( pos ),
_type(WorldObject::TYPE::DISTANCE_SENSOR), _range(10.f), _distance(0), _ticks(0) {}

WorldObject::TYPE DistanceSensor::type() const
{
	return _type;
}

const Vector2D& DistanceSensor::position() const
{
	return _position;
}



void DistanceSensor::runTick(const World* world, HandleData& handleData)
{

	if ( _ticks > 20 )
	{
		if ( isInRange( world->person() ) )
		{
			_distance = ::euclideanDistance( this->position(), world->person()->position() );
			handleData.store( this );
		}
		_ticks = 0;
	}
	_ticks++;
}


float DistanceSensor::data() const
{
	return _distance;
}

bool DistanceSensor::isInRange( Person* person ) const/////PRIVATE/////
{
	return ::euclideanDistance( this->position(), person->position()) <= _range;
}



