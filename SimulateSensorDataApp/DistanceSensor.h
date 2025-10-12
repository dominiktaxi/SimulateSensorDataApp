#pragma once
#include "WorldObject.h"
class DistanceSensor : public WorldObject
{
public:
	DistanceSensor( const Vector2D& );
	WorldObject::TYPE type() const override;
	const Vector2D& position() const override;
	void runTick(Person*, StoreData&) override;
	float data() const override;
	void storeData( StoreData& ) const override;
private:
	WorldObject::TYPE _type;
	uint8_t _range;
	float _distance;
	bool isInRange( Person* ) const;
};

