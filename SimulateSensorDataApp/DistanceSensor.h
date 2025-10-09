#pragma once
#include "WorldObject.h"
class DistanceSensor : public WorldObject
{
public:
	WorldObject::TYPE type() const override;
	const Vector2D& position() const override;
	int range() const override;
private:

};

