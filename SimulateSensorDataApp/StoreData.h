#pragma once

#include <map>
#include <chrono>
#include <vector>
class Vector2D;
class WorldObject;

class StoreData
{
public:
	StoreData();
	struct Data
	{
		float sensorRead;
		double timeStamp;
		const char* name;
	};
	struct DataFromMovementSensor
	{
		bool detectedMovement;
		double timeStamp;
		const char* name;
	};
	void store( const WorldObject* );

	void printData() const;
	void viewStats() const;

private:
	std::vector<Data> _temperatures;
	std::vector<Data> _distances;
	std::vector<DataFromMovementSensor> _movements;
	std::vector<Vector2D> _personPositions;
	std::chrono::time_point<std::chrono::steady_clock> _start;
	

	float average(const std::vector<Data>&) const;
};

