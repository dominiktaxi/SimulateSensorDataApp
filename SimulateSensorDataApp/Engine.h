#pragma once
#include "World.h"
class Engine
{
public:
	enum class OBJECT_TYPE {HOUSE, TEMPERATURE_SENSOR, MOTION_SENSOR, PERSON, NONE};

private:
	World _world;
};

