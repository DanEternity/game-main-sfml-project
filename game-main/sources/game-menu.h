#pragma once

#include "base-manager.h"
#include "custom-types.h"
#include "base-ui.h"
#include "ui-controller.h"
#include "game-enviroment.h"
#include "sprites.h"
#include "debug.h"
#include "ui-text.h"


#include <vector>

class GameMenu : public BaseManager
{
public:
	virtual void Init() override;
	virtual void Update() override;


private:

	UI_Controller ui_ctrl;

	UI_Image *p_menu_bg;
	UI_Image *p_play_button;
	UI_Image *p_continue_button;
	UI_Image *p_stats_button;
	UI_Image *p_settings_button;
	UI_Image *p_credits_button;
	UI_Image *p_exit_button;

	std::vector<UI_Image *> bsqc;
};

