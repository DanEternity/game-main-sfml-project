#include "adventure-main.h"



void AdventureManager::Init()
{
	if (!initEventRequired)
	{
		levelInitRequired = false;
		return;
	}

	QGlobalEvent initData;
	if (EventList.empty())
	{
		Log("Critical failure! No data to init adventure level. App will be closed.");
		std::system("PAUSE");
		return;
	}
	initData = EventList.front();
	EventList.pop();

	switch (initData.type)
	{
	case initGame:
		InitLevel(initData);
		break;
	case initGameDebug:
		InitLevel();
		break;
	default:
		Log("Critical failure! None correct type of event.");
		break;
	}

	levelInitRequired = false;

}

void AdventureManager::Update()
{
	switch (state)
	{
	case AMNone:
		// LUL
		break;
	case AMNormal:
		// primary state
		// can move, open windows, interact, etc...
		ProcessNormalState();
		break;
	default:
		break;
	}
}

void AdventureManager::Destroy()
{
}

void AdventureManager::ProcessNormalState()
{
	// draw bg? LUL 
	// no...
	
	// calc camera
	sf::Vector2f cm = { camX, camY }; // center
	sf::Vector2f cl = { camX - resolution_w / 2, camY - resolution_h / 2 }; // left up
	sf::Vector2f cr = { camX + resolution_w / 2, camY + resolution_h / 2 }; // right down

	// draw objects
	for (int i(0); i < mapObjects.size(); i++)
	{
		if (0) // �������
			continue;
		sf::Vector2f q = { mapObjects[i].x,mapObjects[i].y };
		sf::Vector2f mq = (q - cl) / mapScale;

		mapObjects[i].model->setScale(1.f / mapScale, 1.f / mapScale);
		mapObjects[i].model->setPosition(mq.x, mq.y);
		mapObjects[i].model->sprite()->setRotation(mapObjects[i].rotation);
		mapObjects[i].model->draw();
	}
}

void AdventureManager::InitLevel(QGlobalEvent q)
{
}

void AdventureManager::InitLevel(bool debug)
{
	AMObject buff;
	// 1
	buff.x = 500;
	buff.y = 500;
	buff.sizeX = 500;
	buff.sizeY = 500;
	buff.model = new UI_ObjectImage(1);
	buff.model->LoadFromFile("sources/resources/world_1/test.png");
	buff.model->sprite()->setOrigin({ 0.5f*500, 0.5f*500 });	
	mapObjects.push_back(buff);
	// 2
	buff.x = 1100;
	buff.y = 500;
	buff.model = new UI_ObjectImage(2);
	buff.model->LoadFromFile("sources/resources/world_1/test.png");
	buff.model->sprite()->setOrigin({ 0.5f * 500, 0.5f * 500 });
	buff.rotation = 90;
	mapObjects.push_back(buff);



	camX = 1600 / 2 + 400;
	camY = 900 / 2;

	state = AMNormal;
}
