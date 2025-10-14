#pragma once

#include "StoreData.h"
#include <map>
#include <vector>
class Person;

class WorldObject;
class Vector2D;

class World
{
public:
	World();
	~World();
	
	void runTick();
	float temperature() const;
	float humidity() const;
	Person* spawnPerson( const Vector2D& );
	Person* person() const;
	void addObject( WorldObject* );
	const std::vector<WorldObject*>& worldObjects() const;
	void printData() const;
	void viewStats();
private:
	std::vector<WorldObject*> _worldObjects;
	Person* _person;
	StoreData _storeData;
	float _temperature;
	float _humidity;
	unsigned int _ticks;

	float randomTemperature(float, float) const;
};

