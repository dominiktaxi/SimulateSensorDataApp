#pragma once

#include "Vector.h"
#include "WorldObject.h"
class House
{
public:
	House( const Vector2D& position, const Vector2D& widthHeight );
	
	struct ObjectContainer
	{
		int numberOfVectors;
		Vector2D* positions;
		int size;
	};

	const Vector2D& widthLength() const;
	const ObjectContainer& positionsContainer() const;
private:
	Vector2D _widthLength;
	Vector2D _position;
	static const uint8_t _maxPositions = 60;
	Vector2D _positions[ _maxPositions ];
	ObjectContainer _container;
	WorldObject::TYPE _type;
};

