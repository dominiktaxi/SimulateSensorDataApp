#include "Vector.h"

Vector2D::Vector2D( int x, int y ) : _x( x ), _y( y ) {}

Vector2D::Vector2D() : _x(-1), _y(-1) {}

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

bool Vector2D::operator!=( const Vector2D& other ) const
{
	return ( _x != other._x || _y != other._y );
}

int Vector2D::x() const
{
	return _x;
}

int Vector2D::y() const
{
	return _y;
}

//Return same variables as in x() and y() but with different function name so it is more clear in House class
int Vector2D::width() const
{
	return _x;
}

int Vector2D::length() const
{
	return _y;
}

void Vector2D::setX(int x)
{
	_x = x;
}

void Vector2D::setY( int y )
{
	_y = y;
}