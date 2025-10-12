#include "House.h"
#include <iostream>

//container is a struct for being able to pass a decayed array (arrays decays to pointers) and still be able to keep the possibility to check size
House::House( const Vector2D& position, const Vector2D& widthLength ) : _widthLength( widthLength ),
_type( WorldObject::TYPE::HOUSE ), _container { 0, _positions, sizeof(_positions)}, _position(position)
{
	//set positions for upper wall
	for ( int x = 0; x < widthLength.width(); x++ )
	{
		_positions[ _container.numberOfVectors ] = Vector2D( x + _position.x(), _position.y() );
		_container.numberOfVectors++;
		
	}

	for ( int x = 0; x < widthLength.width(); x++ )
	{
		_positions[ _container.numberOfVectors ] = Vector2D( x + _position.x(), _position.y() + _widthLength.length() + 1 );
		_container.numberOfVectors++;
	}

	for ( int y = 0; y < widthLength.length(); y++ )
	{
		_positions[ _container.numberOfVectors ] = Vector2D( _position.x(), _position.y() + y + 1 );
		_container.numberOfVectors++;
		_positions[ _container.numberOfVectors ] = Vector2D( _position.x() + _widthLength.width(), position.y() + y + 1);
		_container.numberOfVectors++;
	}
	std::cout << "Counter: " << _container.numberOfVectors << std::endl;
}


const Vector2D& House::widthLength() const
{
	return _widthLength;
}

const House::Array& House::positionsContainer() const
{
	return _container;
}