#pragma once

#include "TrajectoryCalculator.h"

// We can initialize TrajectoryCalculator inside this class and
// get results of trajectory positions by time value
// 1) set object - this object will moved like drop with interaction with gravity
// 2) set target - we chose angle of dropping and  start speed of object
// 3) initialize - initialize movement parametrs
// 4,5,6,7..) get position by time - get position coords by time. 
//Return true - if position calculated, false - if trajectory braked with some barrier, or TrCalc not initialized - look in logs.

class CmyMathDll{
public:
	CmyMathDll(bool debugMode = false);

	~CmyMathDll(void);
	
	void setObject(const float x, const float y, const float weight);

	void setTarget(const float angle, const float speed);

	void initialize();

	bool getPositionByTime(const float time, float& x, float& y);

	float getLastX();
	float getLastY();

private:
	TrajectoryCalculator* mCalculator;
	PhysObject* mObj;	
	Position* mLastPoint;

	float mAngle, mSpeed, mLastTime;
	bool mInitialized;	
	bool mIsDubugMode;
};
