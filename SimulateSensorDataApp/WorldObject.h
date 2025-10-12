#pragma once
#include "Vector.h"


class Person;
class StoreData;

class WorldObject
{
public:
	enum class TYPE : uint8_t {PERSON, DISTANCE_SENSOR, MOTION_SENSOR, TEMPERATURE_SENSOR, HOUSE, NONE};
	WorldObject( const Vector2D& );
	virtual WorldObject::TYPE type() const = 0;
	virtual const Vector2D& position() const = 0;
	virtual void runTick( Person* ) = 0;
	virtual int range() const = 0;
	virtual float data() const = 0;
	virtual void storeData( StoreData& ) const = 0;
	bool isInRange( const WorldObject&, WorldObject::TYPE type ) const;
	float euclideanDistance( WorldObject& other ) const;
	
protected:
	Vector2D _position;
	
};

