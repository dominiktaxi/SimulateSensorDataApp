#pragma once
#include "Vector.h"
class WorldObject
{
public:
	enum class TYPE : uint8_t {PERSON, MOTION_DISTANCE_SENSOR, TEMPERATURE_SENSOR, HOUSE};
	WorldObject( uint8_t x, uint8_t y ) : _position( Vector2D( x, y ) ) {}
	virtual WorldObject::TYPE type() const = 0;
	virtual const Vector2D& position() const = 0;
	bool isInRange( WorldObject& ) const;
protected:
	Vector2D _position;
};

