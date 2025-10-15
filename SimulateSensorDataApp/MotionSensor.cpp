#include "MotionSensor.h"
#include <iostream>
#include "utils.h"
#include "HandleData.h"
#include "Person.h"

MotionSensor::MotionSensor(const Vector2D& pos) : WorldObject( pos ), _elementCounter(0),
_type(WorldObject::TYPE::MOTION_SENSOR), _range(6.f) {}

const Vector2D& MotionSensor::position() const
{
	return _position;
}

WorldObject::TYPE MotionSensor::type() const
{
	return _type;
}


void MotionSensor::runTick( const World* world, HandleData& handleData)
{
	if ( isInRange( world->person() ) )
	{
		_positions[ _elementCounter ] = world->person()->position();
		_elementCounter++;

		if ( _elementCounter > 1 ) { _elementCounter = 0; }
		
		if ( detectedMovement() )
		{
			handleData.store( this );
		}
	}
}

float MotionSensor::data() const
{
	return -1.f;
}

bool MotionSensor::detectedMovement()
{
	return _positions[ 0 ] != _positions[ 1 ];
}

bool MotionSensor::isInRange( Person* person )
{
	auto position = person->position();
	auto distance = ::euclideanDistance( position, this->position() );
	return distance <= _range;
}