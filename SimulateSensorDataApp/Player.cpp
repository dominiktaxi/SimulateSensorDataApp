#include "Player.h"

void Player::assignPerson( Person* person )
{
	_person = person;
}

Person* Player::person()
{
	return _person;
}