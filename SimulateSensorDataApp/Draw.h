#pragma once
#include "Vector2D.h"
#include "World.h"
#include "Engine.h"
#include <cstdint>


class Draw
{
public:
	Draw( World* world);
	void draw( const Vector2D& pos, Engine::OBJECT_TYPE type ) const;
private:
	World* _world;
};

