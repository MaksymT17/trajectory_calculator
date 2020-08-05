#include "Position.h"

Position::Position(float x , float y) :
mX(x),
mY(y)
{
}

Position::~Position()
{
}

void Position::Move(float dX, float dY)
{
	mX += dX;
	mY += dY;
}
