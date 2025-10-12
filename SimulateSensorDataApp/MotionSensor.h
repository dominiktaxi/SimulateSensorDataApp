#pragma once
#include "WorldObject.h"
class MotionSensor : public WorldObject
{
public:
	MotionSensor( const Vector2D& );
	const Vector2D& position() const override;
	WorldObject::TYPE type() const override;
	void runTick(Person*) override;
	
	int range() const override;
	float data() const override;
	void storeData( StoreData& ) const override;
private:
	uint8_t _range;
	WorldObject::TYPE _type;
	Vector2D _previousPos;
	bool _readPreviousPos;
	bool detectedMovement( const Vector2D& );
};

