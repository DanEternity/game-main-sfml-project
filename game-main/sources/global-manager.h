#pragma once

#include "base-manager.h"
#include "debug.h"
#include <vector>

#ifndef global_mgr
#define global_mgr

class GlobalManager
{
public:
	GlobalManager();

	int frameCount();	
	double deltaTime();

	void addLevel(BaseManager* LevelManager);
	void setCurLevel(int newLevel);
	void run();

	std::vector<BaseManager*> levels;

private:
	__int64 p_FrameCount = 0;
	double p_LastCallTime = 0;
	double p_CurrentCallTime = 0;
	int p_cur_lvl = 0;
	//bool levelInitRequired = true;
};


#endif // global_mgr
