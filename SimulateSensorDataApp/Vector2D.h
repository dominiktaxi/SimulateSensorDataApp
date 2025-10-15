#pragma once
#include <cstdint>
class Vector2D
{
public:
	Vector2D( int x, int y );
	Vector2D();
	Vector2D operator+( const Vector2D& other) const;
	Vector2D operator-( const Vector2D& other ) const;
	bool operator==( const Vector2D& other ) const;
	bool operator!=( const Vector2D& other ) const;
	int x() const;
	int y() const;
	void setX(int x);
	void setY(int y);
private:
	int _x;
	int _y;
};

