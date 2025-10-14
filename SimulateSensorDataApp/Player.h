#pragma once
#include "Person.h"
class Player
{
public:
	Player() = default;
	void assignPerson( Person* );
	Person* person();
private:
	Person* _person;
};

