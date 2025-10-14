#include "HandleData.h"
#include "WorldObject.h"
#include "Vector.h"
#include "utils.h"

#include <iostream>
#include <algorithm>
#include <windows.h>

HandleData::HandleData() : _start( std::chrono::steady_clock::now() ), _maxTemperature( 35.f )
{
	
}

void HandleData::clear()
{
	_temperatures.clear();
	_distances.clear();
	_movements.clear();
	_start = std::chrono::steady_clock::now();
}

void HandleData::store( const WorldObject* sensor )
{
	WorldObject::TYPE type = sensor->type();
	if ( type == WorldObject::TYPE::TEMPERATURE_SENSOR )
	{
		auto now = std::chrono::steady_clock::now();
		std::chrono::duration<double> elapsed = now - _start;
		if ( sensor->data() > _maxTemperature )
		{
			_temperatures.push_back( { sensor->data(), elapsed.count(), "Temperature over threshold: " } );
			::beep( 800, 400 );
		}
		else { _temperatures.push_back( { sensor->data(), elapsed.count(), "Temperature: " } ); }
	}
	else if ( type == WorldObject::TYPE::DISTANCE_SENSOR )
	{
		std::cout << "STORED DISTANCE" << std::endl;
		auto now = std::chrono::steady_clock::now();
		std::chrono::duration<double> elapsed = now - _start;
		_distances.push_back( { sensor->data(), elapsed.count(), "Distance: "});
	}
	else if ( type == WorldObject::TYPE::MOTION_SENSOR )
	{
		bool detectedMovement = true;
		auto now = std::chrono::steady_clock::now();
		std::chrono::duration<double> elapsed = now - _start;
		_movements.push_back( { detectedMovement, elapsed.count(), "Motion: " } );
	}
}



void HandleData::handleStats()
{
	bool viewing = true;
	while ( viewing )
	{
		int choice = 0;
		std::cout << "View stats: \n1.Average Temperature\n2.Average person distance\n3.Movement detection times\n4.List of all temperatures detected";
		std::cout << "\nwith timestamps\n5.List of all distances person was detected with distance sensor with timestamps\n";
		std::cout << "6.List of all timestamps movement was detected with motion sensor\n7.Sort all\n0.Go back to main" << std::endl;
		std::cin >> choice;
		system( "cls" );
		if ( std::cin.fail() )
		{
			std::cin.clear();
			std::cin.ignore();
			std::string text = "Input number between 1 and 5\n\n";
			for ( int i = 0; i < text.size(); i++ )
			{
				std::cout << text[ i ];
				Sleep( 50 );
			}
			continue;
		}
		switch ( choice )
		{
			case 1:
			{
				if ( _temperatures.size() > 0 )
				{
					float averageTemp = average( _temperatures );
					std::cout << "Average Temperature: " << averageTemp << std::endl;
				}
				else { std::cout << "No temperatures logged" << std::endl; }
			}
			break;
			case 2:
			{
				float averageDistance = average( _distances );
				if ( _distances.size() > 0 ) { std::cout << "Average Distance: " << averageDistance << std::endl; }
				else { std::cout << "Person not detected" << std::endl; }
			}
			break;
			case 3:
			{
				if ( _movements.size() > 0 ) { std::cout << "Person detected " << _movements.size() << " times" << std::endl; }
				else { std::cout << "No logged movements" << std::endl; }
			}
			break;
			case 4:
			{
				if ( _temperatures.size() > 0 )
				{
					for ( const auto& temperature : _temperatures )
					{
						std::cout << temperature.name << temperature.sensorRead << " time: " << temperature.timeStamp;
						std::cout << " seconds since program started\n" << std::endl;
					}
				}
				else
				{
					std::cout << "No logged temperatures\n" << std::endl;
				}
			}
			break;
			case 5:
			{
				if ( _distances.size() > 0 )
				{
					for ( const auto& distance : _distances )
					{
						std::cout << "Distance: " << distance.sensorRead << " time: " << distance.timeStamp << " seconds since program started" << std::endl;
					}
				}
				else { std::cout << "Person not detected" << std::endl; }
			}
			break;
			case 6:
			{
				if ( _movements.size() > 0 )
				{
					for ( const auto& movement : _movements )
					{
						std::cout << "Movement detected at " << movement.timeStamp << " seconds since program started" << std::endl;
					}
				}
				else { std::cout << "No movements logged" << std::endl; Sleep( 1000 ); }
			}
			break;
			case 7:
			{
				sort(_temperatures);
				sort(_distances);
				std::cout << "Temperatures and distances sorted in ascending order" << std::endl;
			}
			break;
			case 0:
			{
				viewing = false;
			}
			break;
		}
	}

}


float HandleData::average(const std::vector<Data>& datas) const
{
	float averageTemp;
	float temporary = 0.f;
	for ( const auto& data : datas )
	{
		temporary += data.sensorRead;
	}
	averageTemp = temporary / datas.size();
	return averageTemp;
}

void HandleData::sort( std::vector<Data>& data )
{
	std::sort( data.begin(), data.end() );
}

void HandleData::setMaxTemperature( float x )
{
	_maxTemperature = x;
}