#pragma once

#include "base-manager.h"
#include "custom-types.h"
#include "base-ui.h"
#include "ui-controller.h"
#include "game-enviroment.h"
#include "sprites.h"
#include "debug.h"

class GameMenu : public BaseManager
{
public:
	virtual void Init() override;
	virtual void Update() override;


private:

	UI_Controller ui_ctrl;
	UI_Image *p_menu_bg;
};

