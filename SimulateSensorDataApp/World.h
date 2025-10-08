#pragma once
#include "WorldObject.h"
#include "House.h"

class World
{
public:
	World();
	~World();
	struct ObjectContainer
	{
		WorldObject** worldObjects;
		uint8_t objectAmount;
		uint8_t size;
	};
	void addWorldObject( WorldObject* obj );
	float temperature() const;
	float humidity() const;
	const ObjectContainer& worldObjects() const;
private:
	ObjectContainer _container;
	static const uint8_t _maxObjects = 10;
	WorldObject* _worldObjects[_maxObjects];
	float _temperature;
	float _humidity;
	House _house;
};

