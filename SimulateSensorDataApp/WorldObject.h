#pragma once
#include "Vector2D.h"
#include "World.h"

class Person;
class HandleData;

class WorldObject
{
public:
	enum class TYPE : uint8_t {PERSON, DISTANCE_SENSOR, MOTION_SENSOR, TEMPERATURE_SENSOR, HOUSE, NONE};
	WorldObject( const Vector2D& );
	virtual WorldObject::TYPE type() const = 0;
	virtual const Vector2D& position() const = 0;
	virtual void runTick( const World*, HandleData& ) = 0;
	virtual float data() const = 0;
	float euclideanDistance( WorldObject& other ) const;
	
protected:
	Vector2D _position;
	
};

