#pragma once
#include "WorldObject.h"
class TemperatureSensor : public WorldObject
{
public:
	TemperatureSensor( const Vector2D& );
	const Vector2D& position() const override;
	void sensor();
	WorldObject::TYPE type() const override;
	int range() const override;
	void runTick(Person*, StoreData&) override;
	void storeData( StoreData& ) const override;
	float data() const override;
private:
	int8_t _temperature;
	WorldObject::TYPE _type;
	const char* _name;
};

