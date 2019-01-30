#pragma once

#ifndef LANDING_MANAGER
#define LANDING_MANAGER

#include "game-enviroment.h"
#include "base-manager.h"
#include "custom-types.h"
#include "characters.h"
#include "custom-types.h"
#include "ui-objects.h"


class UI_ObjectImage;

enum LMPointType
{
	qqq,
};

enum LMState
{
	LMState_idle,
	LMState_choose,
	LMState_inventory,
};

struct LMPoint
{
	float x, y; // position
	int script_id;
	LMPointType type;
	std::vector<int> connections;
	bool visible;
	UI_ObjectImage * PointsUI;
};

class LandingManager : public BaseManager
{
public:
	virtual void Update(); // Primary update method
	virtual void Init(); // Primary init method
	virtual void Destroy(); // Primary destroy // I will call this method after landing is finished 

	void setData(LandModeGameData * data); // setup data;

	LMState state = LMState_idle;

	void setValue(int id_val, int val);

private:
	// local variables goes here

	bool debugMode = true;
	std::vector<LMPoint> PointsList;

	void DrawMap();
	void InitUI();
	
	void debug();

	bool UI_Initialized = false;

	std::vector<LMPoint> map;

	void CreateLMPoints();

	/* ui elements */

	UI_ObjectImage * mainBG;
	UI_ObjectImage * PointsMap;
	UI_Controller * baseUI_Controller;
};

void UIEventHandle(UIEventData * data);

#endif // !LANDING_MANAGER
