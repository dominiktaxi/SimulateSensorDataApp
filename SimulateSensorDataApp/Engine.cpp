#include "Engine.h"
#include <iostream>

Engine::Engine () : _world(), _player() {}

World* Engine::world()
{
	return &_world;
}

void Engine::spawnPerson()
{
	if ( _player.person() == nullptr )
	{
		_player.assignPerson( _world.spawnPerson( Vector2D( 20, 15 ) ) );
	}
	else
	{
		std::cout << "Person already placed" << std::endl;
	}
}

void Engine::handleEvent( const EVENT& event )
{
	switch ( event )
	{
		case EVENT::MOVE_DOWN:
		{
			_player.person()->moveDown();
		}
		break;
		case EVENT::MOVE_LEFT:
		{
			_player.person()->moveLeft();
		}
		break;
		case EVENT::MOVE_RIGHT:
		{
			_player.person()->moveRight();
		}
		break;
		case EVENT::MOVE_UP:
		{
			_player.person()->moveUp();
		}
		break;
	}
}