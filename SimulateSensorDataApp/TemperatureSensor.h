#pragma once
#include "WorldObject.h"
class TemperatureSensor : public WorldObject
{
public:
	TemperatureSensor( uint8_t posX, uint8_t posY );
	const Vector2D& position() const override;
	void sensor();
	WorldObject::TYPE type() const override;
private:
	int8_t _temperature;
	WorldObject::TYPE _type;
	const char* _name;
};

