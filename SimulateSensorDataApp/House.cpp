#include "House.h"



House::House( const Vector2D& position, const Vector2D& widthLength ) : WorldObject(position.x(), position.y()), _widthLength( widthLength ),
_type(WorldObject::TYPE::HOUSE)
{
	for ( int i = 0; i < _maxPositions; i++ )
	{
		_positions[i] = Vector2D(2, 2);
	}
	for ( uint8_t y = position.y(); y < widthLength.y(); y++ )
	{
		for ( uint8_t x = position.x(); x < widthLength.x(); x++ )
		{

		}
	}
}

WorldObject::TYPE House::type() const
{
	return _type;
}

const Vector2D& House::position() const
{
	return _position;
}

const Vector2D& House::widthLength() const
{
	return _widthLength;
}