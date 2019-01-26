#pragma once

#ifndef ADVENTURE_MANAGER
#define ADVENTURE_MANAGER

//#include <SFML\Graphics.hpp>

#include "base-manager.h"
#include "ui-objects.h"
#include "ui-controller.h"
#include "game-enviroment.h"
#include "debug.h"
#include "game-data-global.h"
#include "module-info.h"
#include "sprites.h"

#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>


class UI_ObjectImage;
class UI_ScrollerObject;

struct AMObject
{
	UI_ObjectImage * model;
	float x = 0, y = 0;
	float scaleX = 1, scaleY = 1;
	float sizeX = 1, sizeY = 1;
	float rotation = 0;
};

struct AMZone
{
	UI_ObjectImage * marker;
	float x, y;
	int scriptData;

	int level;
	int danger;
};

enum AMState
{
	AMNone,
	AMNormal,
	AMShip,
	AMLab,
	AMCrew,
	AMCraft,
	AMStorage,
	AMStats,
	AMHangar,
	AMEvent
};

class ZoneObject
{
public:

};

enum AMTask
{

};

struct AMContextStatus
{
	bool active;
	AMTask advancedTask;
	int i1;
	int i2;

	void * v0; // custom struct;

	AMContextStatus();
};

class AdventureManager : public BaseManager
{
public:
	virtual void Init(); // Primary init method
	virtual void Update(); // Primary update method
	virtual void Destroy(); // Primary destroy 

	/* Game status */
	AMState state;
	AMContextStatus context;
	
	std::stack<AMState> stack; // 

private:
	void initUI();
	
	void processBaseState();
	void processShipWindowMain();
	void processShipWindowShip();
	void processShipWindowStorage();

	void drawMainUI();

	bool initEventRequired = true;

	void InitLevel(QGlobalEvent q);
	void InitLevel(bool debug = true);

	/* map data */

	std::vector<AMObject> mapObjects;;
	std::vector<AMZone> mapZones;
	
	float mapScale = 1;
	float camX, camY; // ship coordinates;

	/* UI and testing*/

	UI_ScrollerObject * testScroller;

	/* Controls flags */

	bool controlsDebug = true; //
	bool controlsShipMovement = true; // ship can move (disabled when other window open)
	bool controlsMainButtons = true; // buttons in main screen can be pressed, updated etc...
	bool controlsWorldScrolling = true; // 
	bool controlsKeyboardWindowSwitch = true; // can open/close windows wia keyboard buttons

	/* main screen ui elements */
	bool UI_initialized = false;

	UI_ObjectImage * leftTopElem;
	UI_ObjectImage * leftDownElem;
	UI_ObjectImage * rightDownElem;
	UI_ObjectImage * rightTopElem;

	UI_text * text;

	UI_ObjectImage * btnShip;
	UI_ObjectImage * btnCharacters;
	UI_ObjectImage * btnMap;
	UI_ObjectImage * btnLog;
	UI_ObjectImage * btnMenu;

	UI_ObjectImage * hullBar;
	UI_ObjectImage * ShieldBar;
	UI_ObjectImage * fuelBar;

	UI_ObjectImage * shipImage;

	UI_ObjectImage * windowBG;

	UI_Controller * mainScreenUIController;

	UI_TextObject * textObject;
	
};



#endif // !ADVENTURE_MANAGER