#include "DistanceSensor.h"
#include "StoreData.h"
#include "Utils.h"
#include "Person.h"

DistanceSensor::DistanceSensor( const Vector2D& pos ) : WorldObject( pos ),
_type(WorldObject::TYPE::DISTANCE_SENSOR), _range(10), _distance(0) {}

WorldObject::TYPE DistanceSensor::type() const
{
	return _type;
}

const Vector2D& DistanceSensor::position() const
{
	return _position;
}



void DistanceSensor::runTick(Person* person)
{
	if ( isInRange( person->position() ) )
	{
		_distance = ::euclideanDistance( this->position(), person->position() );
	}
}



float DistanceSensor::data() const
{
	return _distance;
}

bool DistanceSensor::isInRange( const Vector2D& pos ) const/////PRIVATE/////
{
	return ::euclideanDistance( this->position(), pos) <= _range;
}

void DistanceSensor::storeData( StoreData& storeData ) const
{
	storeData.store( this );
}