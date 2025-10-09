#include "DistanceSensor.h"

WorldObject::TYPE DistanceSensor::type() const
{
	return _type;
}

const Vector2D& DistanceSensor::position() const
{
	return _position;
}

int DistanceSensor::range() const
{
	return _range;
}