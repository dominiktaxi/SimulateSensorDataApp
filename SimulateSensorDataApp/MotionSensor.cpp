#include "MotionSensor.h"

MotionSensor::MotionSensor(uint8_t posX, uint8_t posY) : WorldObject( posX, posY ), 
_type(WorldObject::TYPE::MOTION_DISTANCE_SENSOR), _range(3), _name("motionSensor") {}

const Vector2D& MotionSensor::position() const
{
	return _position;
}


WorldObject::TYPE MotionSensor::type() const
{
	return _type;
}