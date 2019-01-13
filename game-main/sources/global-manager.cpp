#include "global-manager.h"

int GlobalManager::frameCount()
{
	return p_FrameCount;
}

double GlobalManager::deltaTime()
{
	return (p_CurrentCallTime.asSeconds());
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
	Log("Global manager: Change level to " + std::to_string(newLevel));
	p_cur_lvl = newLevel;
}

void GlobalManager::run()
{
	/*pre update*/
	p_CurrentCallTime = p_Clock.restart();


	/*update*/
	if (levels[p_cur_lvl]->levelInitRequired)
		levels[p_cur_lvl]->Init();
	else
		levels[p_cur_lvl]->Update();

	/*post update*/
	p_LastCallTime = p_CurrentCallTime;
}
