#pragma once
#include "World.h"
class WorldObserver
{
	virtual void notifyObserver( World* world, WorldObject::TYPE type ) = 0;
};

