#pragma once
#include "Vector.h"
#include "World.h"
#include "Engine.h"
#include "House.h"
#include <cstdint>


class Draw
{
public:
	Draw( World* world);
	void draw( const Vector2D& pos, Engine::OBJECT_TYPE type ) const;
private:
	World* _world;
};

