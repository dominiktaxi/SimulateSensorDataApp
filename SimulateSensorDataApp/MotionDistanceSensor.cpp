#include "MotionDistanceSensor.h"

MotionDistanceSensor::MotionDistanceSensor(uint8_t posX, uint8_t posY) : WorldObject( posX, posY ), 
_type(WorldObject::TYPE::MOTION_DISTANCE_SENSOR), _range(3) {}

const Vector2D& MotionDistanceSensor::position() const
{
	return _position;
}


WorldObject::TYPE MotionDistanceSensor::type() const
{
	return _type;
}