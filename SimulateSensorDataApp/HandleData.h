#pragma once

#include <vector>
#include <chrono>§
#include <string>

class Vector2D;
class WorldObject;

class HandleData
{
public:
	HandleData();
	struct SensorData
	{
		float sensorRead;
		std::string timeStamp;
		std::string name;
		bool operator<( const SensorData& other ) const
		{
			return sensorRead < other.sensorRead;
		}
	};
	struct DataFromMovementSensor
	{
		bool detectedMovement;
		std::string timeStamp;
		std::string name;
	};
	
	void clear();
	void store( const WorldObject* );

	void handleStats();

	void setMaxTemperature(float);
	bool storeToHDD();
	bool loadFromHDD();
private:
	std::vector<SensorData> _temperatures;
	std::vector<SensorData> _distances;
	std::vector<DataFromMovementSensor> _movements;
	float _maxTemperature;
	float average(const std::vector<SensorData>&) const;
	void sort( std::vector<SensorData>& );
};

