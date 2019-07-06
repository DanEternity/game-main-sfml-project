#include "landing-main.h"
#include <cstdlib>
#include <ctime>
#include "ui-line.h"

void LandingManager::Update()
{
	switch (state)
	{
	case LMState_idle:
		DrawMap();
		baseUI_Controller->Update();
		break;
	case LMState_choose:
		DrawMap();
		DrawAskWindow();
		baseUI_Controller->Update();
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

void LandingManager::DrawAskWindow()
{
	askWindow->draw();
	askWindowYES->draw();
	askWindowNO->draw();

	text->setCharacterSize(28);
	text->outTextXY(680, 480, "Yes");
	text->outTextXY(870, 480, "No");
	text->setCharacterSize(24);
	text->outTextXY(630, 370, "Do you really want to go here?");
	if (!falseStartChoose)
	{
		text->outTextXY(630, 390, "You cant go here");
	}
}

void LandingManager::InitUI()
{
	UI_Initialized = true;

	falseStartChoose = true;

	baseUI_Controller = new UI_Controller();
	text = new UI_text(fontArial);
	*text->textStream << sf::Color::Blue;

	mainBG = new UI_ObjectImage(50);
	mainBG->LoadFromSprite(UI_background[0]);
	mainBG->setPosition(0, 0);

	PointsMap = new UI_ObjectImage();
	PointsMap->LoadFromSprite(UI_PointsMap);
	PointsMap->setPosition(200, 100);

	askWindow = new UI_ObjectImage();
	askWindow->LoadFromSprite(UI_askWindow);
	askWindow->setPosition(600, 325);

	askWindowYES = new UI_ObjectImage(51);
	int id = baseUI_Controller->AddElement(askWindowYES);
	baseUI_Controller->RegisterEvent(id, onRelease, UIEventHandle);
	askWindowYES->LoadFromSprite(UI_askWindow);
	askWindowYES->setSize(80, 50);
	askWindowYES->setPosition(670, 475);

	askWindowNO = new UI_ObjectImage(52);
	int id1 = baseUI_Controller->AddElement(askWindowNO);
	baseUI_Controller->RegisterEvent(id1, onRelease, UIEventHandle);
	askWindowNO->LoadFromSprite(UI_askWindow);
	askWindowNO->setSize(80, 50);
	askWindowNO->setPosition(850, 475);

	CreateLMPoints();


	
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
	temp.x = 600;
	temp.y = 350;
	temp.connections.push_back(0);
	temp.connections.push_back(2);
	temp.connections.push_back(3);
	map.push_back(temp);
	temp.visible = false;
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

	getStarted.push_back(0);

	for (int i(0); i < map.size(); i++)
	{
		map[i].PointsUI = new UI_ObjectImage(i);
		int id = baseUI_Controller->AddElement(map[i].PointsUI);
		baseUI_Controller->RegisterEvent(id, onRelease, UIEventHandle);
		map[i].PointsUI->LoadFromSprite(UI_Point);
		map[i].PointsUI->setPosition(map[i].x, map[i].y);
	}

}

void UIEventHandle(UIEventData * data)
{
	//g_land->state = LMState_choose;
	/*int id = data->ref->localID;
	if (id == 10)
		g_land->state = LMState_choose;*/

	int id = data->ref->localID;
	Log("Id is " + std::to_string(id));
	if (g_land->state == LMState_idle) 
	{
		g_land->lastPointClicked = id;
		g_land->state = LMState_choose;
	}
	else if (g_land->state == LMState_choose)
	{

		if (id == 51)
		{
			for (int i(0); i < g_land->getStarted.size(); i++)
			{
				if (g_land->getStarted[i] == g_land->lastPointClicked)
				{
					g_land->wasStart == true;
					if (g_land->wasStart)
					{
						for (int j : g_land->map[g_land->lastPointClicked].connections)
						{
							//доделать проверку соседства
						}
					}
					for (int i(0); i < g_land->map.size(); i++)
						g_land->map[i].isActive = false;
					g_land->map[g_land->lastPointClicked].isActive = true;
					g_land->map[g_land->lastPointClicked].wasThere = true;
					g_land->changePointsState();
					g_land->rightChoose = true;
					for (int i : g_land->map[g_land->lastPointClicked].connections)
					{
						g_land->map[i].visible = true;
						if (g_land->map[i].wasThere == false) g_land->getStarted.push_back(i);
					}

					g_land->state = LMState_idle;
					
				}
			}
			if (g_land->rightChoose == false) g_land->falseStartChoose = false;
			g_land->rightChoose = false;
		}
		if (id == 52)
		{
			g_land->falseStartChoose = true;
			g_land->state = LMState_idle;
		}
	}
}

void LandingManager::changePointsState()
{
	for (int i(0); i < map.size(); i++)
		if (map[i].isActive)
		{
			int x = map[i].x;
			int y = map[i].y;
			map[i].PointsUI->LoadFromSprite(UI_currentLocationLanding);
			map[i].PointsUI->setPosition(x, y);
		}
		else if (map[i].wasThere)
		{
			int x = map[i].x;
			int y = map[i].y;
			map[i].PointsUI->LoadFromSprite(UI_PointWas);
			map[i].PointsUI->setPosition(x, y);
		}
		else
		{
			int x = map[i].x;
			int y = map[i].y;
			map[i].PointsUI->LoadFromSprite(UI_Point);
			map[i].PointsUI->setPosition(x, y);
		}

}