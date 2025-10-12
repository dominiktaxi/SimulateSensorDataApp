#pragma once
#include "WorldObject.h"

class Person : public WorldObject
{
public:
	Person( const Vector2D& );
	void move();
	const Vector2D& position() const override;
	WorldObject::TYPE type() const override;
	void runTick(Person*, StoreData&) override;
	int range() const override;
	float data() const override;
	void storeData( StoreData& ) const override;
private:
	WorldObject::TYPE _type;
};

