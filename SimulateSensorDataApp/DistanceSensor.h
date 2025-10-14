#pragma once
#include "WorldObject.h"
class DistanceSensor : public WorldObject
{
public:
	DistanceSensor( const Vector2D& );
	WorldObject::TYPE type() const override;
	const Vector2D& position() const override;
	void runTick( const World*, HandleData&) override;
	float data() const override;
private:
	WorldObject::TYPE _type;
	float _range;
	float _distance;
	bool isInRange( Person* ) const;
	int _ticks;
};

