#include "World.h"
#include <iostream>
#include "Person.h"
#include "StoreData.h"
#include "Vector.h"
#include "Utils.h"

World::World() : _temperature(0.f), _humidity(0.f), _person(nullptr), _ticks(0), _storeData()
{
	
}
World::~World()
{
	for ( int i = 0; i < _worldObjects.size(); i++ )
	{
		delete _worldObjects[ i ];
		_worldObjects[ i ] = nullptr;
		_worldObjects.clear();
	}
}

void World::runTick()
{
	for ( auto obj : _worldObjects )
	{
		obj->runTick(_person, _storeData);
	}
	_ticks++;

}


float World::temperature() const
{
	return _temperature;
}

float World::humidity() const
{
	return _humidity;
}




Person* World::createPerson( const Vector2D& pos )
{
	if ( _person == nullptr )
	{
		auto person = new Person( pos );
		_person = person;
		return person;
	}
	else
	{
		std::cout << "Person already created, nullptr returned" << std::endl;
		return nullptr;
	}
}



Person* World::person() const
{
	return _person;
}

void World::addObject(WorldObject* object)
{
	_worldObjects.push_back( object );
}

const std::vector<WorldObject*>& World::worldObjects() const
{
	return _worldObjects;
}

bool World::personInRange( WorldObject* object )
{
	auto position = object->position();
	auto euclideanDistance = ::euclideanDistance( _person->position(), position );
	auto range = object->range();

	return euclideanDistance <= range;
}

void World::storeData()
{
	/*for ( int i = 0; i < _worldObjects.size(); i++ )
	{
		_worldObjects[ i ]->storeData( _storeData );
	}*/
}