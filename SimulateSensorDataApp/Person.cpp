#include <conio.h>
#include "Person.h"
#include "StoreData.h"
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

void Person::runTick( const World* world, StoreData& storeData )
{
	//move();
}



float Person::data() const
{
	return -1.f;
}

void Person::storeData( StoreData& storeData ) const
{
	storeData.store( this );
}