#include "WorldObject.h"



bool WorldObject::isInRange( WorldObject& other ) const
{
	const Vector2D difference = this->position() - other.position();
	return true;
}

float WorldObject::euclideanDistance( WorldObject& other ) const
{
	return ::euclideanDistance( this->position(), other.position());
}