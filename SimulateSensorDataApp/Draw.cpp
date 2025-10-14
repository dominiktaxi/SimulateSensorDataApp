#include "Draw.h"
#include "Vector.h"
#include "House.h"
#include "WorldObject.h"
#include <iostream>

Draw::Draw(World* world) : _world(world) {}

void Draw::draw(const Vector2D& pos, Engine::OBJECT_TYPE type ) const
{
	bool drawEmptySpace = true;
	size_t numberOfObjects = _world->worldObjects().size();
	std::vector<WorldObject*> worldObjects = _world->worldObjects();
	Person* person = _world->person();
	system( "cls" );
	for ( int y = 0; y < 30; y++ )
	{
		std::cout << std::endl;
		for ( int x = 0; x < 40; x++ )
		{
			for ( int i = 0; i < numberOfObjects; i++ )
			{
				if ( worldObjects[ i ]->position() == Vector2D( x, y ) )
				{
					if ( worldObjects[ i ]->type() == WorldObject::TYPE::MOTION_SENSOR ) 
					{	
						drawEmptySpace = false; 
						std::cout << "M"; continue; 
					}
					else if ( worldObjects[ i ]->type() == WorldObject::TYPE::TEMPERATURE_SENSOR )
					{ 
						drawEmptySpace = false;
						std::cout << "T"; continue;
					}
					else if ( worldObjects[ i ]->type() == WorldObject::TYPE::PERSON ) 
					{
						drawEmptySpace = false;
						std::cout << "P"; continue;
					}
					else if ( worldObjects[ i ]->type() == WorldObject::TYPE::DISTANCE_SENSOR )
					{
						drawEmptySpace = false;
						std::cout << "D"; continue;
					}
				}
			}
			if ( y == 0 )
			{
				std::cout << "#";
				drawEmptySpace = false;
			}
			else if ( x == 0 || x == 39 )
			{
				std::cout << "#";
				drawEmptySpace = false;
			}
			else if ( y == 29 )
			{
				std::cout << "#";
				drawEmptySpace = false;
			}
			if ( pos == Vector2D( x, y ) )
			{
				std::cout << "O";
				drawEmptySpace = false;
			}
			
			if(drawEmptySpace) std::cout << " ";
			drawEmptySpace = true;
		}
	}

}