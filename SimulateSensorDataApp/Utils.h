#pragma once

#include "Vector2D.h"
#include <string>
float euclideanDistance( Vector2D pos1, Vector2D pos2 );

void beep(int, int);

float randomFloat( float min, float max );
int randomInt( int, int );

std::string localTime();

bool stringToBoolean(const std::string&);