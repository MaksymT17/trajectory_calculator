#ifndef PHYSOBJ_HEADER
#define PHYSOBJ_HEADER
#include "Position.h"
class PhysObject
{
public:
	PhysObject(Position pos, float weight);
	~PhysObject();

	Position mPosition;
	float mWeight;
};
#endif