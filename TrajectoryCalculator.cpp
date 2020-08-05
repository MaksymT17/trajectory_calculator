#include <math.h>
#include "TrajectoryCalculator.h"

const float G_VALUE = 9.81054; 

TrajectoryCalculator::TrajectoryCalculator(PhysObject obj, float angle, float speed) :
	mObj(obj),
	mAngle(angle),
	mSpeed(speed)
{}
TrajectoryCalculator::~TrajectoryCalculator()
{}

Position TrajectoryCalculator::getPositionForTime(float time)
{
	Position pos;

	if (time < 0)
		return pos;

	pos.mX = mObj.mPosition.mX + mSpeed * time * cos(mAngle*3.14 / 180.0);
	pos.mY = mObj.mPosition.mY + mSpeed * time * sin(mAngle*3.14 / 180.0) - ((G_VALUE*time*time) / 2);

	return pos;
}
