#include "WorldObject.h"
#include "HandleData.h"
#include "Person.h"
#include "Utils.h"

WorldObject::WorldObject(const Vector2D& pos) : _position( pos ) {}



float WorldObject::euclideanDistance( WorldObject& other ) const
{
	return ::euclideanDistance( this->position(), other.position());
}