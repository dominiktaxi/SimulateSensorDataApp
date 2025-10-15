#include "Utils.h"
#include <cmath>
#include <thread>
#include <windows.h>
#include <random>

float euclideanDistance( Vector2D pos1, Vector2D pos2 )
{
    return sqrt( std::pow( pos1.x() - pos2.x(), 2 ) + std::pow( pos2.y() - pos1.y(), 2 ) );
}

//COPIED AND PASTED//I DONT UNDERSTAND OTHER THAN THAT THIS CAN RUN SEPERATELY FROM THE MAIN LOOP//
void beep( int freq, int duration )
{
	std::thread( [ freq, duration ] ()
	{
		Beep( freq, duration );
	} ).detach();
}

float randomFloat( float min, float max )
{
	std::random_device rd;
	std::mt19937 gen( rd() );
	std::uniform_real_distribution<float> dist( min, max );
	return dist( gen );
}

int randomInt( int min, int max )
{
	std::random_device rd;
	std::mt19937 gen( rd() );
	std::uniform_int_distribution<int> dist( min, max );
	return dist( gen );
}