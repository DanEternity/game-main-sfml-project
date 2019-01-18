#pragma once

#ifndef LANDING_MANAGER
#define LANDING_MANAGER

#include "base-manager.h"
#include "custom-types.h"
#include "characters.h"

class LandingManager : public BaseManager
{
public:
	virtual void Update(); // Primary update method
	virtual void Init(); // Primary init method
	virtual void Destroy(); // Primary destroy // I will call this method after landing is finished 



private:
	// local variables goes here
};

#endif // !LANDING_MANAGER
