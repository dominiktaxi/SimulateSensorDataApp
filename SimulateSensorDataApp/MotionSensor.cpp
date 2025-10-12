#include "MotionSensor.h"
#include <iostream>
#include "utils.h"
#include "StoreData.h"
#include "Person.h"

MotionSensor::MotionSensor(const Vector2D& pos) : WorldObject( pos ), _elementCounter(0),
_type(WorldObject::TYPE::MOTION_SENSOR), _range(6) {}

const Vector2D& MotionSensor::position() const
{
	return _position;
}

WorldObject::TYPE MotionSensor::type() const
{
	return _type;
}


void MotionSensor::runTick(Person* person, StoreData& storeData)
{
	if ( isInRange( person ) )
	{
		_positions[ _elementCounter ] = person->position();
		_elementCounter++;

		if ( _elementCounter > 1 ) { _elementCounter = 0; }
		
		if ( detectedMovement() )
		{
			storeData.store( this );
		}
	}
}



int MotionSensor::range() const
{
	return _range;
}

float MotionSensor::data() const
{
	return -1.f;
}

bool MotionSensor::detectedMovement()
{
	return _positions[ 0 ] != _positions[ 1 ];
}

void MotionSensor::storeData( StoreData& storeData ) const
{
	storeData.store( this );
}

bool MotionSensor::isInRange( Person* person )
{
	auto position = person->position();
	auto distance = ::euclideanDistance( position, this->position() );
	return distance <= _range;
}