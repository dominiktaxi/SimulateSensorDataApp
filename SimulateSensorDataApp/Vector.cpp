#include "Vector.h"

Vector2D::Vector2D( int x, int y ) : _x( x ), _y( y ) {}

Vector2D Vector2D::operator+( const Vector2D& other ) const
{
	return Vector2D( _x + other._x, _y + other._y );
}

Vector2D Vector2D::operator-( const Vector2D& other ) const
{
	return Vector2D( _x - other._x, _y - other._y );
}

bool Vector2D::operator==( const Vector2D& other ) const
{
	return ( _x == other._x && _y == other._y );
}

uint8_t Vector2D::x() const
{
	return _x;
}

uint8_t Vector2D::y() const
{
	return _y;
}

void Vector2D::setX(uint8_t x)
{
	_x = x;
}

void Vector2D::setY( uint8_t y )
{
	_y = y;
}