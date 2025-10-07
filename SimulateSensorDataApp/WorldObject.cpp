#include "WorldObject.h"



bool WorldObject::isInRange( WorldObject& other ) const
{
	const Vector2D difference = position() - other.position();
	return true;
}