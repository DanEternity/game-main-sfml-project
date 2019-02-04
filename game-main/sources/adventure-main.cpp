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

	if (!UI_initialized)
	{
		initUI();
		UI_initialized = true;
	}

	levelInitRequired = false;
	Log("Level initialized... starting main game...");
}

void AdventureManager::Update()
{

	processBaseState(); // DRAW BASE MAP
	drawShip();

	switch (state)
	{
	case AMNone:
		// LUL
		break;
	case AMNormal:
		// primary state
		// can move, open windows, interact, etc...
		processWorldInteractions();
		break;
	case AMShip:
	case AMLab:
	case AMCrew:
	case AMCraft:
	case AMStorage:
	case AMStats:
	case AMHangar:
		processShipWindowMain();
		break;
	case AMEvent:
		break;
	default:
		break;
	}

	if (!gamePause)
	{
		gd->scriptSystem->update();
		checkScriptBlock();

		if (scriptEvent)
			processScript();
	}

}

void AdventureManager::Destroy()
{
}

void AdventureManager::internalEvent(InternalEventResponse group, int param1, int param2)
{
	switch (group)
	{
	case InternalEventResponse_unspecified:
		break;
	case InternalEventResponse_simpleOk:
		gd->scriptSystem->externalEvent();
		break;
	default:
		break;
	}
}

void AdventureManager::initUI()
{
	
	leftTopElem = new UI_ObjectImage();
	leftTopElem->LoadFromSprite(UI_leftTop);
	leftTopElem->setPosition(0, 0);

	leftDownElem = new UI_ObjectImage();
	leftDownElem->LoadFromSprite(UI_leftDown);
	leftDownElem->setPosition(0, resolution_h - leftDownElem->getSize().second);

	rightDownElem = new UI_ObjectImage();
	rightDownElem->LoadFromSprite(UI_rightDown);
	rightDownElem->setPosition(resolution_w - rightDownElem->getSize().first, resolution_h - rightDownElem->getSize().second);

	rightTopElem = new UI_ObjectImage();
	rightTopElem->LoadFromSprite(UI_rightTop);
	rightTopElem->setPosition(resolution_w - rightTopElem->getSize().first, 0);

	btnShip = new UI_ObjectImage(); // 0
	btnShip->LoadFromSprite(UI_adv_btns[0][0]);
	btnShip->setPosition(resolution_w - 10 - 64, resolution_h - 10 - 64);

	btnMenu = new UI_ObjectImage();
	btnMenu->LoadFromSprite(UI_adv_btns[0][0]);
	btnMenu->setPosition(resolution_w - 10 - 64, 0);

	btnMap = new UI_ObjectImage(); // 2
	btnMap->LoadFromSprite(UI_adv_btns[2][0]);
	btnMap->setPosition(resolution_w - 8 - 48, resolution_h - 10 - 64 - 48 - 48 - 10 - 10);

	btnCharacters = new UI_ObjectImage(); // 1
	btnCharacters->LoadFromSprite(UI_adv_btns[1][0]);
	btnCharacters->setPosition(resolution_w - 8 - 48, resolution_h - 10 - 64 - 48 - 10);

	btnLog = new UI_ObjectImage(); // 3
	btnLog->LoadFromSprite(UI_adv_btns[3][0]);
	btnLog->setPosition(resolution_w - 8 - 48, resolution_h - 10 - 64 - 48 - 48 - 10 - 10 - 58);

	windowBG = new UI_ObjectImage();
	windowBG->LoadFromSprite(UI_adv_window_bg);
	windowBG->setPosition(resolution_w / 2 - 1300 / 2, resolution_h / 2 - 735 / 2);

	UI_text * text = new UI_text(fontArial);

	// here

/*
	UI_ObjectImage * btnShip;
	UI_ObjectImage * btnCharacters;
	UI_ObjectImage * btnMap;
	UI_ObjectImage * btnLog;
	UI_ObjectImage * btnMenu;

	UI_ObjectImage * hullBar;
	UI_ObjectImage * ShieldBar;
	UI_ObjectImage * fuelBar;

	UI_ObjectImage * shipImage;

	UI_Controller * mainScreenUIController;
*/

	/* test */
/*
	textObject = new UI_TextObject();
	textObject->init(fontArial, 400, 400);
	textObject->lineSpacing = 32;
	textObject->lines.push_back("ANDREY P1");
	textObject->lines.push_back("ANDREY P2");
	textObject->lines.push_back("ANDREY P3");
	textObject->lines.push_back("ANDREY P4");
	textObject->lines.push_back("ANDREY P5");
	textObject->lines.push_back("ANDREY P6");
	textObject->lines.push_back("ANDREY P7");
	textObject->lines.push_back("ANDREY P8");
	textObject->lines.push_back("ANDREY P1");
	textObject->lines.push_back("ANDREY P2");
	textObject->lines.push_back("ANDREY P3");
	textObject->lines.push_back("ANDREY P4");
	textObject->lines.push_back("ANDREY P5");
	textObject->lines.push_back("ANDREY P6");
	textObject->lines.push_back("ANDREY P7");
	textObject->lines.push_back("ANDREY P8");
	textObject->lines.push_back("ANDREY P1");
	textObject->lines.push_back("ANDREY P2");
	textObject->lines.push_back("ANDREY P3");
	textObject->lines.push_back("ANDREY P4");
	/*textObject->lines.push_back("ANDREY P5");
	textObject->lines.push_back("ANDREY P6");
	textObject->lines.push_back("ANDREY P7");
	textObject->lines.push_back("ANDREY P8");
	textObject->setPosition(800, 400);*/

	scriptText = new UI_TextObject();
	scriptText->init(fontArial, 400, 400);
	scriptText->lineSpacing = 32;
	scriptText->setPosition(resolution_w / 2 - 200, resolution_h / 2 - 200);

	scriptOkButton = new UI_ObjectImage(1); // used to handle event
	scriptOkButton->LoadFromSprite(UI_rightTop);
	scriptOkButton->setPosition(resolution_w / 2 - 200, resolution_h / 2 + 420);

	scriptTextController = new UI_Controller();
	scriptTextController->AddElement(scriptOkButton);
	scriptTextController->RegisterEvent(0, onRelease, scriptUIEventHandler);
}

void AdventureManager::processBaseState()
{
	float dt = g_mgr->deltaTime();
	
	// debug;;;
	if (1)
	{
		//testScroller->Update();
		//testScroller->draw();
		/*mapScale = 1.f + testScroller->getValue();
		DrawModuleInfoBox(gd->scheme->slots[3].m, 20, 20);*/
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !scriptEvent)
		//{
		//	gd->scriptSystem->execute(1);
		//}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			g_mgr->setCurLevel(3);
		}
		//textObject->update();
		//textObject->rebuildImage = true;
		//textObject->draw();
	}

	// end;;;

	/* read keyboard */
	if (controlsWorldScrolling)
	{
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
	}
	
	if (controlsShipMovement)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			camX -= dt * 200.f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			camX += dt * 200.f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			camY -= dt * 200.f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			camY += dt * 200.f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && zoneId != -1)
		{
			mapZones[zoneId].visited = true;
			mapZones[zoneId].active = false;
			gd->scriptSystem->execute(mapZones[zoneId].scriptData);
		}
	}

	if (controlsKeyboardWindowSwitch)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			state = AMShip;
		}
	}
	// draw bg? LUL 
	// no...
	int ObjectCount = 0;

	// calc camera
	sf::Vector2f cm = { camX, camY }; // center
	sf::Vector2f cl = { camX - (resolution_w / 2 * mapScale), camY - (resolution_h / 2 * mapScale) }; // left up
	sf::Vector2f cr = { camX + (resolution_w / 2 * mapScale), camY + (resolution_h / 2 * mapScale) }; // right down

	// draw objects
	for (int i(0); i < mapObjects.size(); i++)
	{
		auto md = mapObjects[i];
		if (!(md.x + md.sizeX > cl.x && md.x - md.sizeX < cr.x && md.y + md.sizeY > cl.y &&  md.y - md.sizeY < cr.y)) // условие
			continue;
		ObjectCount++;

		sf::Vector2f q = { mapObjects[i].x,mapObjects[i].y };
		sf::Vector2f mq = (q - cl) / mapScale;

		mapObjects[i].model->setScale(1.f / mapScale, 1.f / mapScale);
		mapObjects[i].model->setPosition(mq.x, mq.y);
		mapObjects[i].model->sprite()->setRotation(mapObjects[i].rotation);
		mapObjects[i].model->draw();
	}

	for (int i(0); i < mapZones.size(); i++)
	{
		auto md = mapZones[i];
		if (!mapZones[i].active)
			continue;
		if (!(md.x + 200 > cl.x && md.x - 200 < cr.x && md.y + 200 > cl.y &&  md.y - 200 < cr.y)) // условие
			continue;

		sf::Vector2f q = { mapZones[i].x,mapZones[i].y };
		sf::Vector2f mq = (q - cl) / mapScale;

		mapZones[i].marker->setScale(1.f / mapScale, 1.f / mapScale);
		mapZones[i].marker->setPosition(mq.x, mq.y);
		//mapZones[i].marker->sprite()->setRotation(mapZones[i].rotation);
		mapZones[i].marker->draw();
	}

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	//	Log(std::to_string(ObjectCount));

	drawMainUI();
}

void AdventureManager::processShipWindowMain()
{
	// draw window;
	windowBG->draw();
	processShipWindowButtons();
	// draw buttons;
	switch (state) // specific buttons and functions;
	{
	case AMShip:
		processShipWindowShip();
		break;
	case AMLab:
		processShipWindowLab();
		break;
	case AMCrew:
		processShipWindowCrew();
		break;
	case AMCraft:
		processShipWindowCraft();
		break;
	case AMStorage:
		processShipWindowStorage();
		break;
	case AMStats:
		processShipWindowStats();
		break;
	case AMHangar:
		processShipWindowHangar();
		break;
	default:
		Log("Error! Wrong manager state");
		state = AMNormal;
		break;
	}
}

void AdventureManager::processShipWindowShip()
{
	//gd->mainShip->Hull[3];
}

void AdventureManager::processShipWindowStorage()
{
}

void AdventureManager::processShipWindowLab()
{
}

void AdventureManager::processShipWindowCrew()
{
}

void AdventureManager::processShipWindowCraft()
{
}

void AdventureManager::processShipWindowStats()
{
}

void AdventureManager::processShipWindowHangar()
{
}

void AdventureManager::processShipWindowButtons()
{
	for (int i(0); i < 8; i++)
		if (shipWndBtns[i] != NULL)
			shipWndBtns[i]->draw();
}

void AdventureManager::processWorldInteractions()
{
	zoneId = -1;
	for (int i(0); i < mapZones.size(); i++)
		if (mapZones[i].active && dist2d(camX, camY, mapZones[i].x, mapZones[i].x) < zoneInteractionDistance2)
		{
			// in range

			if (mapZones[i].instaActivation)
			{
				zoneId = i;
				// activate();
			}
			else
			{
				//draw();
				drawMarkerInfo(resolution_w / 2, resolution_h / 2 - 400);
				zoneId = i;
			}
			

			break; // doesn't need to check other points;
		}

}

void AdventureManager::drawShip()
{
	// debug

	ship_sprites[0]->setPosition(resolution_w / 2 - 32, resolution_h / 2 - 32);
	g_wnd->draw(*ship_sprites[0]);
}

void AdventureManager::drawMarkerInfo(int x, int y)
{

	UI_adv_marker_info->setPosition(x, y);
	g_wnd->draw(*UI_adv_marker_info);



}

void AdventureManager::drawMainUI()
{
	leftTopElem->draw();
	leftDownElem->draw();
	rightDownElem->draw();
	rightTopElem->draw();

	btnShip->draw();
	btnLog->draw();
	btnCharacters->draw();
	btnMap->draw();
}

void AdventureManager::checkScriptBlock()
{
	if (gd->scriptSystem->getState() == scriptSystemState_blocked)
	{
		controlsShipMovement = false; // ship can move (disabled when other window open)
		controlsMainButtons = false; // buttons in main screen can be pressed, updated etc...
		controlsWorldScrolling = false; // 
		controlsKeyboardWindowSwitch = false; // can open/close windows wia keyboard buttons
		scriptEvent = true;
		updateScriptData();
	}
	else
	{
		controlsShipMovement = true; // ship can move (disabled when other window open)
		controlsMainButtons = true; // buttons in main screen can be pressed, updated etc...
		controlsWorldScrolling = true; // 
		controlsKeyboardWindowSwitch = true; // can open/close windows wia keyboard buttons
		scriptEvent = false;
		scriptDataUpdated = false;
	}
}

void AdventureManager::updateScriptData()
{
	auto q = gd->scriptSystem->getCurrentElement();
	scriptEventType = q->type;

	switch (scriptEventType)
	{
	case script_base:
		Log("Error! cant handle this type! (Base)");
		break;
	case script_text:
	{
		scriptText->lines.clear();
		auto t = static_cast<TextScript*>(q);
		scriptText->lines = t->text;
		scriptText->rebuildImage = true;
		if (p_last_command != q)
			scriptText->resetScroller();
		p_last_command = q;
	}
		break;
	case script_choose:
		break;
	case script_action:
		break;
	default:
		break;
	}

}

void AdventureManager::processScript()
{
	switch (scriptEventType)
	{
	case script_base:
		// invalid
		break;
	case script_text:
		processTextScript();
		break;
	case script_choose:
		break;
	case script_action:
		break;
	default:
		break;
	}
}

void AdventureManager::processTextScript()
{
	scriptTextController->Update();
	scriptText->update();
	scriptText->draw();
	scriptOkButton->draw();
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

	testScroller = new UI_ScrollerObject();
	//testScroller->Create();
	testScroller->setPosition(1500, 80);

	state = AMNormal;

	ActionScriptDebugText * qq = new ActionScriptDebugText();
	qq->next = 1;
	qq->str = "Script test";
	qq->final = false;
	//qq->type = script_action;
	//qq->acType = ACType_debugText;

	int id = gd->scriptSystem->addLine(qq);

	qq = new ActionScriptDebugText();
	qq->final = true;
	qq->str = "Script test 2";
	
	gd->scriptSystem->addElement(id, qq);

	TextScript * q2 = new TextScript;
	q2->next = 1;
	q2->text.push_back("@[color:green]@[style:italic+bold+underlined]Test line 1");
	q2->text.push_back("@[color:#200#250#100#255]Test @[color:#100#150#250#255]line 2");
	for (int i(0); i<20; i++)
		q2->text.push_back("@[color:#200#250#100#255]Test @[color:#100#150#250#255]line " + std::to_string(i));
	q2->final = false;

	id = gd->scriptSystem->addLine(q2);

	q2 = new TextScript;
	q2->next = 0;
	q2->text.push_back("Test line 3");
	q2->text.push_back("Test line 4");
	q2->final = true;

	gd->scriptSystem->addElement(id, q2);

	AMZone buff2 = AMZone();

	// 1
	buff2.x = 500;
	buff2.y = 500;

	buff2.marker = new UI_ObjectImage(1);
	buff2.marker->LoadFromSprite(UI_adv_marker_base);
	buff2.marker->sprite()->setOrigin({ 128, 128 });
	buff2.level = 1;
	buff2.danger = 2;
	buff2.scriptData = 1;
	buff2.instaActivation = false;
	mapZones.push_back(buff2);

}

AMContextStatus::AMContextStatus()
{
	active = false;
	//advancedTask = 0;
	i1 = 0;
	i2 = 0;
	v0 = nullptr;
}

void scriptUIEventHandler(UIEventData * q)
{
	auto t = q->eventType;

	switch (t)
	{
	case onPress:
		break;
	case onRelease:
		if (q->ref->localID == 1)
			g_adv->internalEvent(InternalEventResponse_simpleOk, 0, 0);
		break;
	case onHoverBegin:
		break;
	case onHoverEnd:
		break;
	default:
		break;
	}
}
