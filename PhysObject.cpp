#include "stdafx.h"
#include "PhysObject.h"

PhysObject::PhysObject(Position pos, float weight) :
		mPosition(pos),
		mWeight(weight)
	{}
PhysObject::~PhysObject()
	{}

