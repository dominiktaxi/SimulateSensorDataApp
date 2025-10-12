#include "Person.h"
#include "StoreData.h"
Person::Person ( const Vector2D& pos ) : WorldObject(pos), _type(WorldObject::TYPE::PERSON) {}

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

void Person::runTick( Person* )
{

}

int Person::range() const
{
	return -1;
}

float Person::data() const
{
	return -1.f;
}

void Person::storeData( StoreData& storeData ) const
{
	storeData.store( this );
}