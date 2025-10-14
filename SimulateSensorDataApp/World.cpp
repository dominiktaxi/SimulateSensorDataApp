#include "World.h"
#include <iostream>
#include <windows.h>
#include <random>
#include "Person.h"
#include "HandleData.h"
#include "Vector.h"
#include "Utils.h"

World::World() : _temperature( 0.f ), _humidity( 0.f ), _person( nullptr ) , _ticks( 0 ), _handleData()
{
	
}
World::~World()
{
	for ( int i = 0; i < _worldObjects.size(); i++ )
	{
		delete _worldObjects[ i ];
		_worldObjects[ i ] = nullptr;
	}
	_worldObjects.clear();
}

void World::clear()
{
	for ( auto object : _worldObjects )
	{
		delete object;
		object = nullptr;
	}
	_worldObjects.clear();
	_person = nullptr; //person is also in _worldObjects - already deleted
	_handleData.clear();
}

void World::runTick()
{
		float maxTemp = 40.f;
		float minTemp = 17.5f;
		_temperature = randomTemperature( minTemp, maxTemp );
		for ( auto obj : _worldObjects )
		{
			obj->runTick( this, _handleData );
		}
		_ticks = 0;
	_person->runTick(this, _handleData);
}


float World::temperature() const
{
	return _temperature;
}

float World::humidity() const
{
	return _humidity;
}




Person* World::spawnPerson( const Vector2D& pos )
{
	if ( _person == nullptr )
	{
		auto person = new Person( pos );
		_person = person;
		_worldObjects.push_back( person );
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


void World::viewStats()
{
	_handleData.handleStats();
}

float World::randomTemperature(float min, float max) const
{
	std::random_device rd;
	std::mt19937 gen( rd() );
	std::uniform_real_distribution<float> dist( min, max );
	return dist( gen );
}

void World::setMaxTemperature( float x )
{
	_handleData.setMaxTemperature( x );
}