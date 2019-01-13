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
	float dt = g_mgr->deltaTime();
	if (dt < 0)
		Log("UULULULULULULU");
	// debug;;;
	if (0)
	{
		//mapScale += g_mgr->deltaTime();
		mapScale += 0.001f;

		if (mapScale > 5)
			mapScale = .4f;


	}

	// end;;;

	/* read keyboard */

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp))
	{
		mapScale += dt * 2;
		mapScale = std::min(mapScale, 5.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown))
	{
		mapScale -= dt * 2;
		mapScale = std::max(mapScale, 1.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		camX -= dt * 200.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		camX += dt * 200.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		camY -= dt * 200.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		camY += dt * 200.f;

		//sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
	//	sf::Keyboard::isKeyPressed(sf::Keyboard::Left)

	// draw bg? LUL 
	// no...
	
	// calc camera
	sf::Vector2f cm = { camX, camY }; // center
	sf::Vector2f cl = { camX - (resolution_w / 2 * mapScale), camY - (resolution_h / 2 * mapScale) }; // left up
	sf::Vector2f cr = { camX + (resolution_w / 2 * mapScale), camY + (resolution_h / 2 * mapScale) }; // right down

	// draw objects
	for (int i(0); i < mapObjects.size(); i++)
	{
		if (0) // условие
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


	mapScale = 1.f;
	camX = 1600 / 2 + 400;
	camY = 900 / 2;

	state = AMNormal;
}
