#include "Person.h"

Person::Person ( uint8_t x, uint8_t y ) : WorldObject(x, y), _type(WorldObject::TYPE::PERSON) {}

void Person::move()
{
	
}

const Vector2D& Person::position() const
{
	return _position;
}

WorldObject::TYPE Person::type() const
{
	return _type;
}