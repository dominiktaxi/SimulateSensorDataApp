#pragma once
#include <cstdint>
class Vector2D
{
public:
	Vector2D( int x, int y );
	Vector2D operator+( const Vector2D& other) const;
	Vector2D operator-( const Vector2D& other ) const;
	bool operator==( const Vector2D& other ) const;
	uint8_t x() const;
	uint8_t y() const;
	void setX(uint8_t x);
	void setY(uint8_t y);
private:
	uint8_t _x;
	uint8_t _y;
};

