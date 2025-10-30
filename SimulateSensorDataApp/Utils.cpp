#include "Utils.h"
#include <cmath>
#include <thread>
#include <windows.h>
#include <random>

float euclideanDistance( Vector2D pos1, Vector2D pos2 )
{
    return sqrt( std::pow( pos1.x() - pos2.x(), 2 ) + std::pow( pos2.y() - pos1.y(), 2 ) );
}

//std::thread for making it possible to run alongside main loop without pausing it
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

std::string localTime()
{
	time_t now;
	struct tm date;
	char buffer[ 26 ];

	time( &now );
	localtime_s( &date, &now );
	asctime_s( buffer, sizeof( buffer ), &date ); 

	std::string removeEndl( buffer );
	removeEndl.pop_back(); //remove \n so it only returns time without a new line

	return removeEndl;
}

bool stringToBoolean(const std::string& text)
{
	if ( text == "0" ) { return false; }
	
	return true;
}