#include "MotionSensor.h"
#include <iostream>
#include "utils.h"
#include "StoreData.h"

MotionSensor::MotionSensor(const Vector2D& pos) : WorldObject( pos ), 
_type(WorldObject::TYPE::MOTION_SENSOR), _range(6), _previousPos(0, 0), _readPreviousPos(false) {}

const Vector2D& MotionSensor::position() const
{
	return _position;
}

WorldObject::TYPE MotionSensor::type() const
{
	return _type;
}


void MotionSensor::runTick(Person* person)
{

}



int MotionSensor::range() const
{
	return _range;
}

float MotionSensor::data() const
{
	return -1.f;
}

bool MotionSensor::detectedMovement( const Vector2D& pos )
{
	if ( !_readPreviousPos )
	{
		_previousPos = pos;
		_readPreviousPos = true;
	}
	float temp = ::euclideanDistance( this->position(), pos );
	return ::euclideanDistance( this->position(), pos ) <= _range;
}

void MotionSensor::storeData( StoreData& storeData ) const
{
	storeData.store( this );
}