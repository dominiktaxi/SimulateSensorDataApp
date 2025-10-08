#pragma once
#include "WorldObject.h"

class Person : public WorldObject
{
public:
	Person( uint8_t x, uint8_t y );
	void move();
	const Vector2D& position() const override;
	WorldObject::TYPE type() const override;
private:
	WorldObject::TYPE _type;
	const char* _name;
};

