#pragma once
#include "WorldObject.h"
class MotionDistanceSensor : public WorldObject
{
public:
	MotionDistanceSensor( uint8_t posX, uint8_t posY );
	const Vector2D& position() const override;
	WorldObject::TYPE type() const override;
private:
	uint8_t _range;
	WorldObject::TYPE _type;
};

