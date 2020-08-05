
#pragma once
#include "Position.h"
#include "PhysObject.h"

class TrajectoryCalculator
{
public:
	TrajectoryCalculator(PhysObject obj, float angle, float speed);

	~TrajectoryCalculator();

	Position getPositionForTime(float time);

private:
	PhysObject mObj;
	float mAngle;
	float mSpeed;
};
