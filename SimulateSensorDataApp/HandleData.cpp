#include "HandleData.h"
#include "WorldObject.h"
#include "Vector2D.h"
#include "utils.h"

#include <fstream>
#include <iostream>
#include <algorithm>
#include <windows.h>
#include <sstream>

HandleData::HandleData() :  _maxTemperature( 35.f )
{
	
}

void HandleData::clear()
{
	_temperatures.clear();
	_distances.clear();
	_movements.clear();
	std::ofstream( "sensorData/temperatures.txt", std::ios::trunc );
	std::ofstream( "sensorData/distances.txt", std::ios::trunc );
	std::ofstream( "sensorData/movements.txt", std::ios::trunc );
}

void HandleData::store( const WorldObject* sensor )
{
	WorldObject::TYPE type = sensor->type();
	if ( type == WorldObject::TYPE::TEMPERATURE_SENSOR )
	{
		if ( sensor->data() > _maxTemperature )
		{
			_temperatures.push_back( { sensor->data(), ::localTime(), "Temperature over threshold: "});
			::beep( 800, 800 );
		}
		else { ::beep( 200, 400 ); _temperatures.push_back( { sensor->data(), ::localTime(), "Temperature: "}); }
	}
	else if ( type == WorldObject::TYPE::DISTANCE_SENSOR )
	{
		_distances.push_back( { sensor->data(), ::localTime(), "Distance: "});
	}
	else if ( type == WorldObject::TYPE::MOTION_SENSOR )
	{
		bool detectedMovement = true;
		_movements.push_back( { detectedMovement, ::localTime(), "Motion: "});
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
					int temperatureOverThreshold = 0;
					for ( const auto& temperature : _temperatures )
					{
						if ( temperature.name == "Temperature over threshold: " ) { temperatureOverThreshold++; }
						std::cout << temperature.name << temperature.sensorRead << "°C, Time: " << temperature.timeStamp << "\n";
					}
					std::cout << "Temperature reached " << temperatureOverThreshold << " times over the threshold\n" << std::endl;
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
						std::cout << "Distance: " << distance.sensorRead << " time: " << distance.timeStamp << std::endl;
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


float HandleData::average(const std::vector<SensorData>& datas) const
{
	float averageTemp = 0.f;
	float temporary = 0.f;
	for ( const auto& data : datas )
	{
		temporary += data.sensorRead;
	}
	if ( datas.size() > 0 )
	{
		averageTemp = temporary / datas.size();
	}
	return averageTemp;

}

void HandleData::sort( std::vector<SensorData>& data )
{
	std::sort( data.begin(), data.end() );
}

void HandleData::setMaxTemperature( float x )
{
	_maxTemperature = x;
}

bool HandleData::storeToHDD()
{
	bool success = true;
	std::ofstream temperatures( "sensorData/temperatures.txt", std::ios::app );
	std::ofstream distances("sensorData/distances.txt", std::ios::app);
	std::ofstream movements("sensorData/movements.txt", std::ios::app);
	if ( !temperatures || !distances || !movements )
	{
		success = false;
		return success;
	}
	for ( const auto& temperature : _temperatures )
	{
		temperatures << temperature.sensorRead << "," << temperature.timeStamp << "," << temperature.name << "\n";
	}
	for ( const auto& distance : _distances )
	{
		distances << distance.sensorRead << "," << distance.timeStamp << "," << distance.name << "\n";
	}
	for ( const auto& movement : _movements )
	{
		movements << movement.detectedMovement << "," << movement.timeStamp << "," << movement.name << "\n";
	}
	temperatures.close();
	distances.close();
	movements.close();
	return success;
}

bool HandleData::loadFromHDD()
{
	bool success = true;
	std::ifstream temperatures( "sensorData/temperatures.txt" );
	std::string line;
	while ( getline( temperatures, line, '\n') )
	{
		std::stringstream ss( line );
		std::string sensorRead, timeStamp, name;
		getline( ss, sensorRead, ',' );
		getline( ss, timeStamp, ',' );
		getline( ss, name, ',' );

		SensorData data;
		data.name = name;
		data.timeStamp = timeStamp;
		data.sensorRead = std::stof( sensorRead );
		
		//ss >> data.sensorRead;
		_temperatures.push_back( data );
	}
	temperatures.close();
	std::ifstream distances( "sensorData/distances.txt" );

	while ( getline( distances, line, '\n' ) )
	{
		std::stringstream ss( line );
		std::string sensorRead, timeStamp, name;
		getline( ss, sensorRead, ',' );
		getline( ss, timeStamp, ',' );
		getline( ss, name, ',' );
		
		SensorData data;
		data.sensorRead = std::stof( sensorRead );
		data.timeStamp = timeStamp;
		data.name = name;
		_distances.push_back( data );
	}
	distances.close();
	std::ifstream movements( "sensorData/movements.txt" );

	while ( getline( movements, line, '\n') )
	{
		std::stringstream ss( line );
		std::string detectedMovement, timeStamp, name;
		getline( ss, detectedMovement, ',' );
		getline( ss, timeStamp, ',' );
		getline( ss, name, ',' );
		DataFromMovementSensor data;
		data.detectedMovement = ::stringToBoolean( detectedMovement );
		data.timeStamp = timeStamp;
		data.name = name;
		_movements.push_back(data);
	}
	movements.close();
	return success;
}