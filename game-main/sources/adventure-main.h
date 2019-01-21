#pragma once

#ifndef ADVENTURE_MANAGER
#define ADVENTURE_MANAGER

//#include <SFML\Graphics.hpp>

#include "base-manager.h"
#include "ui-objects.h"
#include "ui-controller.h"
#include "game-enviroment.h"
#include "debug.h"

#include <vector>
#include <algorithm>
#include <cmath>



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
	AMNormal
};

class ZoneObject
{
public:

};

class AdventureManager : public BaseManager
{
public:
	virtual void Init(); // Primary init method
	virtual void Update(); // Primary update method
	virtual void Destroy(); // Primary destroy 

	AMState state;

private:
	void ProcessNormalState();

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
};



#endif // !ADVENTURE_MANAGER