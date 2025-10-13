
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Person.h"
#include "draw.h"
#include "Engine.h"
#include "TemperatureSensor.h"
#include "MotionSensor.h"
#include "House.h"
#include "DistanceSensor.h"


Vector2D setObjectPosition( Draw& draw, Engine::OBJECT_TYPE type, House* house )
{
	int dude = rand() % 100;
	bool placing = true;
	Vector2D objectPos( 0, 0 );
	

	while ( placing )
	{
		//if ( _kbhit() )
		{
			draw.draw( objectPos, type, house );
			if ( static_cast<int>( type ) == 0 ) { std::cout << "\nPLACE TEMPERATURE SENSOR" << std::endl; }
			if ( static_cast<int>( type ) == 1 ) { std::cout << "\nPLACE MOTION SENSOR" << std::endl; }
			if ( static_cast<int>( type ) == 2 ) { std::cout << "\nPLACE DISTANCE SENSOR" << std::endl; }
			if ( static_cast<int>( type ) == 3 ) { std::cout << "\nPLACE PERSON" << std::endl; }
			
			std::cout << "A-LEFT	D-RIGHT		W-UP	S-DOWN		SPACE-DONE" << std::endl;
			switch ( _getch() )
			{
				system( "cls" );
				case 'a': objectPos.setX( objectPos.x() - 1 ); break;
				case 'w': objectPos.setY( objectPos.y() - 1 ); break;
				case 's': objectPos.setY( objectPos.y() + 1 ); break;
				case 'd': objectPos.setX( objectPos.x() + 1 ); break;
				case ' ': placing = false; break;
			}
		}
		
		
	}
	return objectPos;
	}

void setup( Draw & draw, World * world, House * &house )
{
	Engine::OBJECT_TYPE type = Engine::OBJECT_TYPE::NONE;
	
	
	struct Positions
	{
		Vector2D position;
		Engine::OBJECT_TYPE type;
	};
	std::vector<Positions> positions;
	
	for ( int i = 0; i < 4; i++ )
	{
		switch ( i + 1 )
		{
			case 1:
			{
				type = Engine::OBJECT_TYPE::TEMPERATURE_SENSOR;
			}
			break;
			case 2:
			{
				type = Engine::OBJECT_TYPE::MOTION_SENSOR;
			}
			break;
			case 3:
			{
				type = Engine::OBJECT_TYPE::PERSON;
			}
			break;
			case 4:
			{
				type = Engine::OBJECT_TYPE::DISTANCE_SENSOR;
			}
			break;
		}
		Vector2D objPos = setObjectPosition( draw, type, house );
		positions.push_back( { objPos , type } );
	}

	for ( auto pos : positions )
	{
		switch ( pos.type )
		{
			case ( Engine::OBJECT_TYPE::TEMPERATURE_SENSOR ):
			{
				auto object = new TemperatureSensor( pos.position );
				world->addObject( object );
			}
			break;
			case Engine::OBJECT_TYPE::MOTION_SENSOR:
			{
				auto object = new MotionSensor( pos.position );
				world->addObject( object );
			}
			break;
			case ( Engine::OBJECT_TYPE::PERSON ):
			{
				
				Person* person = world->createPerson( pos.position );
				world->addObject( person );
			}
			break;
			case ( Engine::OBJECT_TYPE::DISTANCE_SENSOR ):
			{
				auto object = new DistanceSensor( pos.position );
				world->addObject( object );
			}
			break;
		}
	}
}

void simulate(World* world, const Draw& draw)
{
	while ( true )
	{
		draw.draw( Vector2D( 255, 255 ), Engine::OBJECT_TYPE::NONE, nullptr );
		world->runTick();
	}
}


int main()
{
	World world;
	Draw draw( &world );
	House* house = nullptr;

	while ( true )
	{
		setup( draw, &world, house );
		simulate(&world, draw);
		break;
	}


	// house->setup()
	// world->draw()
	// world->append(&house)

    return 0;
}

