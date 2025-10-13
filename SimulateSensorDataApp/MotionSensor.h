#pragma once
#include "WorldObject.h"
class MotionSensor : public WorldObject
{
public:
	MotionSensor( const Vector2D& );
	const Vector2D& position() const override;
	WorldObject::TYPE type() const override;
	void runTick(const World*, StoreData&) override;
	float data() const override;
private:
	uint8_t _elementCounter;
	float _range;
	WorldObject::TYPE _type;
	Vector2D _positions[ 2 ];
	bool detectedMovement();
	bool isInRange( Person* );
};

