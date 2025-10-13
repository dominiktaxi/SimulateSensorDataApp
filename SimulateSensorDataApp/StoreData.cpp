#include "StoreData.h"
#include "WorldObject.h"
#include "Vector.h"

#include <iostream>

StoreData::StoreData() : _start( std::chrono::steady_clock::now() )
{
	
	
}

void StoreData::store( const WorldObject* sensor )
{
	WorldObject::TYPE type = sensor->type();
	if ( type == WorldObject::TYPE::TEMPERATURE_SENSOR )
	{
		auto now = std::chrono::steady_clock::now();
		std::chrono::duration<double> elapsed = now - _start;
		_temperatures.push_back( { sensor->data(), elapsed.count(), "Temperature" } );
	}
	else if ( type == WorldObject::TYPE::DISTANCE_SENSOR )
	{
		std::cout << "STORED DISTANCE" << std::endl;
		auto now = std::chrono::steady_clock::now();
		std::chrono::duration<double> elapsed = now - _start;
		_distances.push_back( { sensor->data(), elapsed.count(), "Distance"});
	}
	else if ( type == WorldObject::TYPE::MOTION_SENSOR )
	{
		bool detectedMovement = true;
		auto now = std::chrono::steady_clock::now();
		std::chrono::duration<double> elapsed = now - _start;
		_movements.push_back( { detectedMovement, elapsed.count(), "Motion" } );
	}
}

void StoreData::printData() const
{
	for (const auto& temps : _temperatures )
	{
		std::cout << "Temperature: " << temps.sensorRead << " At time: " << temps.timeStamp << std::endl;
	}
	for (const auto& movements : _movements )
	{
		std::cout << "Movements detected: " << _movements.size() << " at time: " << movements.timeStamp << std::endl;
	}

	for ( const auto& distance : _distances )
	{
		std::cout << "Person at distance " << distance.sensorRead << " detected at time " << distance.timeStamp << std::endl;
	}
}

void StoreData::viewStats() const
{
	bool viewing = true;
	while ( viewing )
	{
		int choice = 0;
		std::cout << "View stats: \n1.Average Temperature\n2.Average person distance\n3.Movement detection times\n4.List of all temperatures detected";
		std::cout << "\nwith timestamps\n5.List of all distances person was detected with distance sensor with timestamps\n";
		std::cout << "6.List of all timestamps movement was detected with motion sensor\n0.Go back to main" << std::endl;
		std::cin >> choice;
		if ( std::cin.fail() )
		{
			std::cout << "Input number between 1 and 5" << std::endl;
			std::cin.clear();
			continue;
		}
		switch ( choice )
		{
			case 1:
			{
				float averageTemp = average( _temperatures );
				std::cout << "Average Temperature: " << averageTemp << std::endl;
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
						std::cout << "Temperature: " << temperature.sensorRead << " time: " << temperature.timeStamp;
						std::cout << " seconds since program started" << std::endl;
					}
				}
				else
				{
					std::cout << "No logged temperatures" << std::endl;
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
				else { std::cout << "No movements logged" << std::endl; }
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


float StoreData::average(const std::vector<Data>& datas) const
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