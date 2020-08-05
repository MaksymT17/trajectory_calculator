// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the MYMATHDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// MYMATHDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef MYMATHDLL_EXPORTS
#define MYMATHDLL_API __declspec(dllexport)
#else
#define MYMATHDLL_API __declspec(dllimport)
#endif

#include "TrajectoryCalculator.h"

// We can initialize TrajectoryCalculator inside this class and
// get results of trajectory positions by time value
// 1) set object - this object will moved like drop with interaction with gravity
// 2) set target - we chose angle of dropping and  start speed of object
// 3) initialize - initialize movement parametrs
// 4,5,6,7..) get position by time - get position coords by time. 
//Return true - if position calculated, false - if trajectory braked with some barrier, or TrCalc not initialized - look in logs.
class MYMATHDLL_API TrajectoryBuilder {
public:
	TrajectoryBuilder(bool debugMode = false) :
		mIsDubugMode(debugMode)	{};

	//set object - this object will moved like drop with interaction with gravity
	virtual void setObject(const float x, const float y, const float weight){};

	//set target - we chose angle of dropping and  start speed of object
	virtual void setTarget(const float angle, const float speed){};

	//initialize - initialize movement parametrs
	virtual void initialize(){};

	//get position by time - get position coords by time.
	//return true - if success, otherwise - false
	virtual bool getPositionByTime(const float time, float& x, float& y){ return false; };

protected:
	bool mIsDubugMode;
};


// Implementation of TrajectoryBuilder
class MYMATHDLL_API CmyMathDll: TrajectoryBuilder{
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
};
