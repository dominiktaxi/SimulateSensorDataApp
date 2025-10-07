#include "Utils.h"
#include <cmath>

float euclideanDistance( Vector2D pos1, Vector2D pos2 )
{
    return sqrt( std::pow( pos1.x() - pos2.x(), 2 ) + std::pow( pos2.y() - pos1.y(), 2 ) );
}