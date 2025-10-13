#include <conio.h>
#include "Person.h"
#include "StoreData.h"
Person::Person ( const Vector2D& pos ) : WorldObject(pos), _type(WorldObject::TYPE::PERSON) {}

void Person::move()
{
	if ( _kbhit() )
	{
		switch ( _getch() )
		{
			case 'a': _position.setX( _position.x() - 1 ); break;
			case 'w': _position.setY( _position.y() - 1 ); break;
			case 's': _position.setY( _position.y() + 1 ); break;
			case 'd': _position.setX( _position.x() + 1 ); break;
		}
	}
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
	move();
}



float Person::data() const
{
	return -1.f;
}

void Person::storeData( StoreData& storeData ) const
{
	storeData.store( this );
}