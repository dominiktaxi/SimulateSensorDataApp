#pragma once
#include "WorldObject.h"
class TemperatureSensor : public WorldObject
{
public:
	TemperatureSensor( const Vector2D& );
	const Vector2D& position() const override;
	void sensor();
	WorldObject::TYPE type() const override;
	void runTick(const World*, StoreData&) override;
	float data() const override;
private:
	float _temperature;
	WorldObject::TYPE _type;
	const char* _name;
	int _ticks;
};

