#pragma once
#include "WorldObject.h"

class Person : public WorldObject
{
public:
	Person( const Vector2D& );
	void moveRight();
	void moveLeft();
	void moveDown();
	void moveUp();
	const Vector2D& position() const override;
	WorldObject::TYPE type() const override;
	void runTick(const World*, HandleData&) override;
	float data() const override;
	void handleData( HandleData& ) const;
private:
	WorldObject::TYPE _type;
};

