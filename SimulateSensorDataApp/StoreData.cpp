#include "StoreData.h"
#include "WorldObject.h"
#include "Vector.h"

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