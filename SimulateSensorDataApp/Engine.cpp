#include "Engine.h"
#include <iostream>
#include "utils.h"

Engine::Engine () : _world(), _player() {}

void Engine::runTick()
{
	_world.runTick();
}

void Engine::clear()
{
	_world.clear();
	_player.person() = nullptr;
}

World* Engine::world()
{
	return &_world;
}


void Engine::spawnPerson()
{
	if ( _player.person() == nullptr )
	{
		Person* person = _world.spawnPerson( Vector2D( 20, 15 ) );
		_player.assignPerson( person );
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

bool Engine::storeToHDD()
{
	return _world.storeToHDD();
}

bool Engine::loadFromHDD()
{
	return _world.loadFromHDD();
}