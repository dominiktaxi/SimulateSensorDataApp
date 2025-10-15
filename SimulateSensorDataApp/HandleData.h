#pragma once

#include <vector>
#include <chrono>

class Vector2D;
class WorldObject;

class HandleData
{
public:
	HandleData();
	struct Data
	{
		float sensorRead;
		double timeStamp;
		const char* name;
		bool operator<( const Data& other ) const
		{
			return sensorRead < other.sensorRead;
		}
	};
	struct DataFromMovementSensor
	{
		bool detectedMovement;
		double timeStamp;
		const char* name;
	};
	
	void clear();
	void store( const WorldObject* );

	void handleStats();

	void setMaxTemperature(float);
private:
	std::vector<Data> _temperatures;
	std::vector<Data> _distances;
	std::vector<DataFromMovementSensor> _movements;
	std::chrono::time_point<std::chrono::steady_clock> _start;
	float _maxTemperature;
	
	float average(const std::vector<Data>&) const;
	void sort( std::vector<Data>& );
};

