#pragma once

#include "base-manager.h"

class SpaceBattleManager : public BaseManager
{
public:
	virtual void Update(); // Primary update method
	virtual void Init(); // Primary init method
	virtual void Destroy(); // Primary destroy 

private:

};
