#include "landing-main.h"
#include <cstdlib>
#include <ctime>
#include "ui-line.h"

void LandingManager::Update()
{
	DrawMap();

	switch (state)
	{
	case LMState_idle:
		baseUI_Controller->Update();
		break;
	case LMState_choose:
		Log("qqqqqq");
		state = LMState_idle;
		break;
	case LMState_inventory:

		break;
	default:
		break;
	}
}

void LandingManager::Init()
{
	if (!UI_Initialized)
	{
		InitUI();
		if (debugMode)
			debug();
	}
	

	levelInitRequired = false;
}

void LandingManager::Destroy()
{
}

void LandingManager::setData(LandModeGameData * data)
{
}

void LandingManager::setValue(int id_val, int val)
{
}

void LandingManager::DrawMap()
{
	mainBG->draw();
	PointsMap->draw();

	for (LMPoint point : map)
	{
		for (int i(0); i < point.connections.size(); i++)
		{
			Line line;
			if (point.visible && map[point.connections[i]].visible)
				line.drawLine(point.x + 12, point.y + 12, map[point.connections[i]].x + 12, map[point.connections[i]].y + 12, sf::Color::Black);
		}
	}
	for (LMPoint point : map)
	{
		if (point.visible)
			point.PointsUI->draw();
	}

}

void LandingManager::InitUI()
{
	UI_Initialized = true;
	mainBG = new UI_ObjectImage(10);
	mainBG->LoadFromSprite(UI_background[0]);
	mainBG->setPosition(0, 0);

	PointsMap = new UI_ObjectImage();
	PointsMap->LoadFromSprite(UI_PointsMap);
	PointsMap->setPosition(200, 100);

	CreateLMPoints();

	baseUI_Controller = new UI_Controller();

	for (int i(0); i < map.size(); i++)
	{
		map[i].PointsUI = new UI_ObjectImage(i);
		int id = baseUI_Controller->AddElement(map[i].PointsUI);
		baseUI_Controller->RegisterEvent(id, onRelease, UIEventHandle);
		map[i].PointsUI->LoadFromSprite(UI_Point);
		map[i].PointsUI->setPosition(map[i].x, map[i].y);
	}

	/*int id = baseUI_Controller->AddElement(mainBG);
	baseUI_Controller->RegisterEvent(id, onRelease, UIEventHandle);*/
}

void LandingManager::debug()
{
	
}

void LandingManager::CreateLMPoints()
{
	//srand(time(NULL));
	LMPoint temp;
	temp.x = 500;
	temp.y = 350;
	temp.visible = true;
	temp.connections.push_back(1);
	map.push_back(temp);
	temp.visible = false;
	temp.x = 600;
	temp.y = 350;
	temp.connections.push_back(0);
	temp.connections.push_back(2);
	temp.connections.push_back(3);
	map.push_back(temp);
	temp.connections.clear();
	temp.x = 700;
	temp.y = 300;
	temp.connections.push_back(1);
	map.push_back(temp);
	temp.connections.clear();
	temp.x = 700;
	temp.y = 400;
	temp.connections.push_back(1);
	map.push_back(temp);
	temp.connections.clear();

}

void UIEventHandle(UIEventData * data)
{
	//g_land->state = LMState_choose;
	/*int id = data->ref->localID;
	if (id == 10)
		g_land->state = LMState_choose;*/

	int id = data->ref->localID;
	for (int i(0); i < g_land->map.size(); i++)
	{
		if (i == id)
			if (g_land->map[i].visible)
			{
				Log("onReleased point" + std::to_string(id));
				for (int i : g_land->map[id].connections)
				{
					g_land->map[i].visible = true;
				}
			}
			else Log("onReleased point" + std::to_string(id) + " but it not visible");
	}
}
