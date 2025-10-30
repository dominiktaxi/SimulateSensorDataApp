
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Person.h"
#include "draw.h"
#include "Engine.h"
#include "TemperatureSensor.h"
#include "MotionSensor.h"
#include "DistanceSensor.h"
#include "Utils.h"
#include "Globals.h"

const int WIDTH = 40;
const int HEIGHT = 30;
const float maxTemperature = 40.f;
const float minTemperature = 17.5f;

//This function sets position of objects through a "game-like" experience and returns it in my custom made class Vector2D
Vector2D setObjectPosition( Draw& draw, Engine::OBJECT_TYPE type )
{
	bool placing = true;
	Vector2D objectPos( WIDTH / 2, HEIGHT / 2 );
	while ( placing )
	{
		{
			draw.draw( objectPos, type );
			if ( static_cast<int>( type ) == 0 ) { std::cout << "\nPLACE TEMPERATURE SENSOR" << std::endl; }
			if ( static_cast<int>( type ) == 1 ) { std::cout << "\nPLACE MOTION SENSOR" << std::endl; }
			if ( static_cast<int>( type ) == 2 ) { std::cout << "\nPLACE DISTANCE SENSOR" << std::endl; }

			std::cout << "A = LEFT		D = RIGHT		W = UP		S = DOWN		SPACE = PLACE" << std::endl;
			switch ( _getch() )
			{
				system( "cls" );
				case 'a': if ( objectPos.x() > 1 )  objectPos.setX( objectPos.x() - 1 ); break;
				case 'w': if ( objectPos.y() > 1 ) objectPos.setY( objectPos.y() - 1 ); break;
				case 's': if ( objectPos.y() < HEIGHT - 2 ) objectPos.setY( objectPos.y() + 1 ); break;
				case 'd': if ( objectPos.x() < WIDTH - 2 ) objectPos.setX( objectPos.x() + 1 ); break;
				case ' ': placing = false; break;
			}
		}
	}
	return objectPos;
}

//this function handles all the setup that needs to be done before the whole program can start running and collecting data
void setup( Draw & draw, Engine* engine )
{
	Engine::OBJECT_TYPE type = Engine::OBJECT_TYPE::NONE;
	World* world = engine->world();
	
	struct Positions
	{
		Vector2D position;
		Engine::OBJECT_TYPE type;
	};
	std::vector<Positions> positions;
	
	//Carl Johan tips: använd en array med object types istället
	//std::array<Engine::OBJECT_TYPE, 3> sensorTypes = { type, type, type}
	for ( int i = 0; i < 3; i++ )
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
				type = Engine::OBJECT_TYPE::DISTANCE_SENSOR;
			}
			break;
		}
		//obtaining objectpositions and storing them in positions vector
		Vector2D objPos = setObjectPosition( draw, type );
		positions.push_back( { objPos , type } );
	}
	//looping throug positions vector to create new objects in world
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
			case ( Engine::OBJECT_TYPE::DISTANCE_SENSOR ):
			{
				auto object = new DistanceSensor( pos.position );
				world->addObject( object );
			}
			break;
		}
	}
	while ( true )
	{
		float maxTemp = 0.f;
		std::cout << "Set temperature threshold: ";
		std::cout << "(temperature will vary between " << minTemperature << " and " << maxTemperature << ")" << std::endl;
		std::cin >> maxTemp;
		system( "cls" );
		if ( std::cin.fail() )
		{
			std::cin.clear();
			std::cin.ignore(); // behöver en limit
			std::cout << "Enter a numeric value" << std::endl;
		}
		else
		{
			world->setMaxTemperature( maxTemp );
			break;
		}
	}
}



//draw.draw handles drawing the visual world
//world-runTick() handles every sensor read, temperature changes and user input to change person position


void simulate(Engine* engine, const Draw& draw)
{
	bool running = true;
	while ( running )
	{
		//same function as used in setting object position, but now the arguments are unnecessary
		draw.draw( Vector2D( 255, 255 ), Engine::OBJECT_TYPE::NONE );
		engine->runTick();
		std::cout << "\nPress P to return" << std::endl;
		std::cout << "High pitch, longer beep = Temperature over threshold\nLow pitched short beep = Temperature logged" << std::endl;
		if ( _kbhit() )
		{
			switch ( _getch() )
			{
				case 'p': running = false; break;
				case 'w': engine->handleEvent( Engine::EVENT::MOVE_UP );    break;
				case 's': engine->handleEvent( Engine::EVENT::MOVE_DOWN );  break;
				case 'a': engine->handleEvent( Engine::EVENT::MOVE_LEFT );	break;
				case 'd': engine->handleEvent( Engine::EVENT::MOVE_RIGHT );	break;
			}
		}
	}
}

void menu(Engine* engine, const Draw& draw)
{
	int choice = 0;
	while ( choice != 4 && choice != 3)
	{
		system( "cls" );
		std::cout << "1.Simulate\n2.View stats\n3.Clear everything and setup again\n4.Quit" << std::endl;
		std::cin >> choice;
		if ( std::cin.fail() || choice < 1 || choice > 4 )
		{
			std::string text = "Enter a number between 1 and 3          ";
			for ( int i = 0; i < text.size(); i++ )
			{
				std::cout << text[ i ] << std::endl;
				Sleep( 300 );
				std::cin.ignore();
				std::cin.clear();
				continue;
			}
		}
		else
		{
			switch ( choice )
			{
				case 1: simulate(engine, draw); break;
				case 2: engine->world()->viewStats(); break;
				case 3: engine->clear(); break;
			}
		}
	}
}

void fakeLoading()
{
	std::cout << "LOADING\n" << std::endl;
	std::string loading = "* * * * * * * * * * * * * * * * * * * *";
	float percentage = 2.5f;
	
	for ( int i = 0; i < loading.size(); i++ )
	{
		int sleepTime = ::randomInt( 100, 600 );
		system( "cls" );
		for ( int j = 0; j < i + 1; j++ )
		{
			std::cout << loading[ j ];
		}
		percentage += 2.5f;
		std::cout << std::endl << percentage << "%" << std::endl;
		Sleep( sleepTime );
	}
	Sleep( 600 );
}

int main()
{
	fakeLoading();
	Engine engine;
	World* world = engine.world();
	Draw draw( world );

	if ( !engine.loadFromHDD() )
	{
		std::cout << "No data stored from previous readings" << std::endl;
		Sleep( 5000 );
	}
	
	while ( !world->worldObjects().size() )
	{
		setup( draw, &engine );
		engine.spawnPerson();
		menu( &engine, draw );
	}

	if ( !engine.storeToHDD() )
	{
		std::cerr << "Data could not be stored" << std::endl;
		return 1;
	}
    return 0;
}

