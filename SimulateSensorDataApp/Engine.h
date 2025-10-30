#pragma once
#include "World.h"
#include "Player.h"
class Engine
{
public:
	Engine();
	enum class OBJECT_TYPE { TEMPERATURE_SENSOR, MOTION_SENSOR, DISTANCE_SENSOR, PERSON, NONE, HOUSE};
	enum class EVENT { MOVE_LEFT, MOVE_RIGHT, MOVE_UP, MOVE_DOWN, RETURN };
	void runTick();
	void clear();
	World* world();
	void spawnPerson();
	void handleEvent(const EVENT& );
	bool storeToHDD();
	bool loadFromHDD();
private:
	World _world;
	Player _player;
};

