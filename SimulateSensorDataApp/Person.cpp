#include <conio.h>
#include "Person.h"
#include "HandleData.h"
Person::Person ( const Vector2D& pos ) : WorldObject(pos), _type(WorldObject::TYPE::PERSON) {}

void Person::moveRight()
{
	_position.setX( _position.x() + 1 );
}

void Person::moveLeft()
{
	_position.setX( _position.x() - 1 );
}

void Person::moveDown()
{
	_position.setY( _position.y() + 1 );
}

void Person::moveUp()
{
	_position.setY( _position.y() - 1 );
}

const Vector2D& Person::position() const
{
	return _position;
}

WorldObject::TYPE Person::type() const
{
	return _type;
}

void Person::runTick( const World* world, HandleData& handleData )
{
	//move();
}



float Person::data() const
{
	return -1.f;
}

void Person::handleData( HandleData& handleData ) const
{
	handleData.store( this );
}