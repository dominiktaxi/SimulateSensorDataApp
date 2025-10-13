#include "Utils.h"
#include <cmath>
#include <thread>
#include <windows.h>

float euclideanDistance( Vector2D pos1, Vector2D pos2 )
{
    return sqrt( std::pow( pos1.x() - pos2.x(), 2 ) + std::pow( pos2.y() - pos1.y(), 2 ) );
}

void beep( int freq, int duration )
{
	std::thread( [ freq, duration ] ()
	{
		Beep( freq, duration );
	} ).detach();
}