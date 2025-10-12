#include "WorldObject.h"
#include "StoreData.h"
#include "Person.h"
#include "Utils.h"

WorldObject::WorldObject(const Vector2D& pos) : _position( pos ) {}

//check if objects are in range of the distance sensor
bool WorldObject::isInRange(const WorldObject& other, WorldObject::TYPE type) const
{
	if ( this->type() == TYPE::DISTANCE_SENSOR )
	{
		const float distance = ::euclideanDistance( this->position(), other.position() );
		return distance <= this->range();
	}
	return false;
}

float WorldObject::euclideanDistance( WorldObject& other ) const
{
	return ::euclideanDistance( this->position(), other.position());
}