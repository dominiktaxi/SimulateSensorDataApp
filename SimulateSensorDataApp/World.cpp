#include "World.h"
#include <iostream>


World::World() : _temperature(0.f), _humidity(0.f), _container { _worldObjects, 0, sizeof(_worldObjects)}
{
	uint8_t arraySize = sizeof( _worldObjects ) / sizeof( _worldObjects[ 0 ] );
	for ( uint8_t i = 0; i < arraySize; i++ )
	{
		_worldObjects[ i ] = nullptr;
	}
}
World::~World()
{
	for ( int i = 0; i < _container.objectAmount; i++ )
	{
		delete _worldObjects[ i ];
		_worldObjects[ i ] = nullptr;
		_container.objectAmount = 0;
	}
}

void World::addWorldObject( WorldObject* obj )
{
	if ( _container.objectAmount < _maxObjects )
	{
		_worldObjects[ _container.objectAmount ] = obj;
		_container.objectAmount++;
	}
	else
	{
		delete obj;
		std::cout << "maximum number of objects reached" << std::endl;
		return;
	}
}

float World::temperature() const
{
	return _temperature;
}

float World::humidity() const
{
	return _humidity;
}

const World::ObjectContainer& World::worldObjects() const
{
	return _container;
}