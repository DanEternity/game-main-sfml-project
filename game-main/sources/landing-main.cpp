#include "landing-main.h"

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
}

void LandingManager::InitUI()
{
	UI_Initialized = true;
	mainBG = new UI_ObjectImage(10);
	mainBG->LoadFromSprite(UI_background[0]);
	mainBG->setPosition(0, 0);

	baseUI_Controller = new UI_Controller();

	/*int id = baseUI_Controller->AddElement(mainBG);
	baseUI_Controller->RegisterEvent(id, onRelease, UIEventHandle);*/
}

void LandingManager::debug()
{

}

void UIEventHandle(UIEventData * data)
{
	//g_land->state = LMState_choose;
	/*int id = data->ref->localID;
	if (id == 10)
		g_land->state = LMState_choose;*/
}
