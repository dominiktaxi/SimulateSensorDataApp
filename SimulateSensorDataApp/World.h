#pragma once

#include "HandleData.h"
#include <vector>
class Person;

class WorldObject;
class Vector2D;

class World
{
public:
	World();
	~World();

	void clear();
	
	void runTick();
	float temperature() const;
	float humidity() const;
	Person* spawnPerson( const Vector2D& );
	Person* person() const;
	void addObject( WorldObject* );
	const std::vector<WorldObject*>& worldObjects() const;
	void viewStats();
	void setMaxTemperature( float );
private:
	std::vector<WorldObject*> _worldObjects;
	Person* _person;
	HandleData _handleData;
	float _temperature;
	float _humidity;
	unsigned int _ticks;
};

