/*

    
*/

//Lukas: sätt house i world


#include <iostream>
#include <windows.h>
//#include <stdio.h>
#include <conio.h>
#include "Person.h"
#include "draw.h"
#include "Engine.h"
#include "TemperatureSensor.h"
#include "MotionSensor.h"
#include "House.h"

// Header example
namespace ObjectPosition {
	Vector2D setObjectPosition( Draw&, Engine::OBJECT_TYPE, House* );
}

Vector2D setObjectPosition( Draw& draw, Engine::OBJECT_TYPE type, House* house )
{
	
		int dude = rand() % 100;
		bool choosing = true;
		Vector2D objectPos( 0, 0 );

		while ( choosing )
		{
			//if ( _kbhit() )
			{
				switch ( _getch() )
				{
					system( "cls" );
					case 'a': objectPos.setX( objectPos.x() - 1 ); break;
					case 'w': objectPos.setY( objectPos.y() - 1 ); break;
					case 's': objectPos.setY( objectPos.y() + 1 ); break;
					case 'd': objectPos.setX( objectPos.x() + 1 ); break;
					case ' ': choosing = false; break;
				}
			}
			draw.draw( objectPos, type, house );
		}
		return objectPos;
	}

void setup( Draw & draw, World * world, House * &house )
{
	Engine::OBJECT_TYPE type = Engine::OBJECT_TYPE::NONE;
	int choice;
	std::cout << "Choose what to place:\n1.Temperature Sensor\n2.Motion Sensor\n3.Person\n4.House\n5.Distance Sensor " << std::endl;
	std::cin >> choice;
	switch ( choice )
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
			type = Engine::OBJECT_TYPE::HOUSE;
		}
		break;
		case 5:
		{
			type = Engine::OBJECT_TYPE::DISTANCE_SENSOR;
		}
		break;
	}


	Vector2D pos = setObjectPosition( draw, type, house );


	switch ( type )
	{
		case ( Engine::OBJECT_TYPE::TEMPERATURE_SENSOR ):
		{
			world->addObject( new TemperatureSensor( pos ) );
		}
		break;
		case Engine::OBJECT_TYPE::MOTION_SENSOR:
		{
			auto object = new MotionSensor( pos );
			world->addObject( object );
		}
		break;
		case ( Engine::OBJECT_TYPE::PERSON ):
		{
			auto object = new Person( pos );
			world->addObject( object );
		}
		break;
		case ( Engine::OBJECT_TYPE::HOUSE ):
		{
			std::cout << "Choose width and height (19 x 19 max)" << std::endl;

			int width = 0;
			int length = 0;

			std::cin >> width;

			std::cout << "Choose length" << std::endl;

			std::cin.clear();
			std::cin >> length;
			if ( width < 20 && width > 0 && length < 20 && length > 0 )
			{
				if ( house == nullptr )
				{
					house = new House( pos, Vector2D( width, length ) );
					std::cout << "HOUSE PLACED" << std::endl;
				}
				else
				{
					std::cout << "HOUSE ALREADY PLACED" << std::endl;
				}
			}

		}
		break;
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
	}


	// house->setup()
	// world->draw()
	// world->append(&house)

    return 0;
}

