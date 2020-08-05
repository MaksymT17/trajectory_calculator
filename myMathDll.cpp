// myMathDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "myMathDll.h"
#include <stdio.h>
#include <math.h>


CmyMathDll::CmyMathDll(bool debugMode) :
	mCalculator(nullptr),
	mObj(nullptr),
	mLastPoint(new Position(0, 0)),
	mAngle(0.0f),
	mSpeed(0.0f),
	mLastTime(0.0f),
	mInitialized(false)
{
}

CmyMathDll::~CmyMathDll(void)
{
	if (mObj != nullptr)
		delete mObj;

	if (mCalculator != nullptr)
		delete mCalculator;

	if (mLastPoint != nullptr)
		delete mLastPoint;
}

void CmyMathDll::setObject(const float x, const float y, const float weight)
{
	if (mIsDubugMode)
		printf("CmyMathDll::setObject x=%f y%f weight=%f", x, y, weight);

	if (mObj != nullptr)
		delete mObj;

	mInitialized = false;

	mObj = new PhysObject(Position(x, y), weight);
}

void CmyMathDll::setTarget(const float angle, const float speed)
{
	if (mIsDubugMode)
		printf("CmyMathDll::setTarget angle=%f speed=%f", angle, speed);

	mInitialized = false;
	mAngle = angle;
	mSpeed = speed;
}
void CmyMathDll::initialize()
{
	if (mObj != nullptr)
	{
		mCalculator = new TrajectoryCalculator(*mObj, mAngle, mSpeed);
		mInitialized = true;

		if (mIsDubugMode)
			printf("CmyMathDll::initialize Trajectory successfully initialized");
	}
	else
		printf("LIBLOG::Error of initialization Calc\n");
}
float CmyMathDll::getLastX()
{
	return mLastPoint->mX;
}
float CmyMathDll::getLastY()
{
	return mLastPoint->mY;
}

bool CmyMathDll::getPositionByTime(const float time, float& x, float& y)
{
	if (mInitialized && mCalculator != nullptr)
	{
		const Position p = mCalculator->getPositionForTime(time);
		if (p.mY <= 0.0)
		{
			x = p.mX;
			y = p.mY;
			return false;
		}

		mLastPoint->mX = p.mX;
		mLastPoint->mY = p.mY;

		x = p.mX;
		y = p.mY;

		if (mIsDubugMode)
			printf("CmyMathDll::getPositionByTime time=%f x=%f y=%f", time, x, y);

		return true;
	}
	printf("LIBLOG::Critical Error: TrajectoryCalculator not initialized\n");
	return false;
}