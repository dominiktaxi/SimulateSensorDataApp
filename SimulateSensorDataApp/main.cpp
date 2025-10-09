/*
        README
    This program will simulate 2 motion sensors, one glass break detector and an alarm in a house. One of the sensors is just outside the door, monitoring movement and distance
    from the outside, the other sensors sits inside and is the one that triggers the alarm. Everything is logged.
    The user will be in the role of a person that will have different options what to do in the simulated world.
    The user can choose to move towards the house, to step back, to break a window or break in through the door.
    
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
		std::cout << "Choose what to place:\n1.Temperature Sensor\n2.Motion Sensor\n3.Person\n4.House " << std::endl;
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
		}


		Vector2D pos = setObjectPosition( draw, type, house );


		switch ( type )
		{
			case ( Engine::OBJECT_TYPE::TEMPERATURE_SENSOR ):
			{
				world->addWorldObject( new TemperatureSensor( pos.x(), pos.y() ) );
			}
			break;
			case Engine::OBJECT_TYPE::MOTION_SENSOR:
			{
				world->addWorldObject( new MotionSensor( pos.x(), pos.y() ) );
			}
			break;
			case ( Engine::OBJECT_TYPE::PERSON ):
			{
				world->addWorldObject( new Person( pos.x(), pos.y() ) );
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

    return 0;
}

