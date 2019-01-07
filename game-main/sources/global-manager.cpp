#include "global-manager.h"

int GlobalManager::frameCount()
{
	return p_FrameCount;
}

double GlobalManager::deltaTime()
{
	return (p_CurrentCallTime - p_LastCallTime);
}

GlobalManager::GlobalManager()
{

}

void GlobalManager::addLevel(BaseManager * LevelManager)
{
	levels.push_back(LevelManager);
}

void GlobalManager::setCurLevel(int newLevel)
{
	p_cur_lvl = newLevel;
}

void GlobalManager::run()
{
	/*pre update*/

	/*update*/
	if (levels[p_cur_lvl]->levelInitRequired)
		levels[p_cur_lvl]->Init();
	else
		levels[p_cur_lvl]->Update();

	/*post update*/
}
