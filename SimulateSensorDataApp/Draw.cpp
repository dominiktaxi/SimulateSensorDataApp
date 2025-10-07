#include "Draw.h"
#include "Vector.h"
#include "House.h"

#include <iostream>

Draw::Draw(World* world) : _world(world) {}

void Draw::draw(const Vector2D& pos, Engine::OBJECT_TYPE type) const
{
	uint8_t numberOfObjects = _world->worldObjects().objectAmount;
	WorldObject** _worldObjects = _world->worldObjects().worldObjects;
	system( "cls" );
	for ( uint8_t y = 0; y < 30; y++ )
	{
		std::cout << std::endl;
		for ( uint8_t x = 0; x < 70; x++ )
		{
			for ( uint8_t i = 0; i < numberOfObjects; i++ )
			{
				if ( type == Engine::OBJECT_TYPE::HOUSE )
				{
					House* house = dynamic_cast<House*>( _worldObjects[ i ] );
					if ( house != nullptr )
					{
						Vector2D houseDimensions = house->widthLength();
						Vector2D housePos = house->position();

						if ( x >= housePos.x() && x <= ( houseDimensions.x() + housePos.x() ) && y == housePos.y() )
						{
							std::cout << "#";
						}
					}
				}
				if ( _worldObjects[ i ]->position() == Vector2D( x, y ) )
				{
					if ( _worldObjects[ i ]->type() == WorldObject::TYPE::MOTION_DISTANCE_SENSOR ) { std::cout << "M"; continue; }
					else if ( _worldObjects[ i ]->type() == WorldObject::TYPE::TEMPERATURE_SENSOR ) { std::cout << "T"; continue; }
					else if ( _worldObjects[ i ]->type() == WorldObject::TYPE::PERSON ) { std::cout << "P"; continue; }
				}
			}
			if ( pos == Vector2D( x, y ) )
			{
				std::cout << "O";
			}
			else
			{
				std::cout << " ";
			}
		}
	}

}