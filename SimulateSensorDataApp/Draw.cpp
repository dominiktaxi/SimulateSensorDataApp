#include "Draw.h"
#include "Vector.h"
#include "House.h"

#include <iostream>

Draw::Draw(World* world) : _world(world) {}

void Draw::draw(const Vector2D& pos, Engine::OBJECT_TYPE type, House* house) const
{
	bool drawEmptySpace = true;
	int numberOfObjects = _world->worldObjects().objectAmount;
	WorldObject** _worldObjects = _world->worldObjects().worldObjects;
	system( "cls" );
	for ( int y = 0; y < 30; y++ )
	{
		std::cout << std::endl;
		for ( int x = 0; x < 70; x++ )
		{
			if ( house != nullptr )
			{
				for ( int i = 0; i < house->positionsContainer().numberOfVectors; i++ )
				{
					if ( house->positionsContainer().positions[ i ] == Vector2D( x, y ) )
					{
						std::cout << "*";
						drawEmptySpace = false;
					}
				}
			}
			for ( int i = 0; i < numberOfObjects; i++ )
			{
				if ( _worldObjects[ i ]->position() == Vector2D( x, y ) )
				{
					if ( _worldObjects[ i ]->type() == WorldObject::TYPE::MOTION_DISTANCE_SENSOR ) 
						{ std::cout << "M"; continue; 
							drawEmptySpace = false; 
						}
					else if ( _worldObjects[ i ]->type() == WorldObject::TYPE::TEMPERATURE_SENSOR )
						{ std::cout << "T"; continue;
							drawEmptySpace = false; 
						}
					else if ( _worldObjects[ i ]->type() == WorldObject::TYPE::PERSON ) 
					{
						std::cout << "P"; continue;
						drawEmptySpace = false;
					}
				}
				
			}
			if ( pos == Vector2D( x, y ) )
			{
				std::cout << "O";
			}
			if(drawEmptySpace) std::cout << " ";
			drawEmptySpace = true;
		}
	}

}