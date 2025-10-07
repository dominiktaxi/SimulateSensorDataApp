#pragma once

#include "Vector.h"
#include "WorldObject.h"
class House : public WorldObject
{
public:
	House( const Vector2D& position, const Vector2D& widthHeight );
	WorldObject::TYPE type() const override;
	const Vector2D& position() const override;
	const Vector2D& widthLength() const;
private:
	Vector2D _widthLength;
	static const uint8_t _maxPositions = 60;
	Vector2D _positions[ _maxPositions ];
	WorldObject::TYPE _type;
};

