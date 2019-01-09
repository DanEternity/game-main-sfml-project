#pragma once

#ifndef GAME_MENU
#define GAME_MENU

#include "base-manager.h"
#include "custom-types.h"
#include "base-ui.h"
#include "ui-controller.h"
#include "game-enviroment.h"
#include "sprites.h"
#include "debug.h"
#include "ui-text.h"

#include <vector>

class UI_Controller;

class GameMenu : public BaseManager
{
public:
	virtual void Init() override;
	virtual void Update() override;
	void SetButtonState(int list_id, int id, buttonState state);
	void SetMenuState(gameMenuState state);
private:

	gameMenuState p_m_state = main_menu;

	UI_Controller * ui_ctrl;
	UI_Controller * ui_ctrl_2;

	UI_Image *p_menu_bg;
	UI_Image *p_play_button;
	UI_Image *p_continue_button;
	UI_Image *p_stats_button;
	UI_Image *p_settings_button;
	UI_Image *p_credits_button;
	UI_Image *p_exit_button;

	UI_Image *p_back_button;

	std::vector<UI_Image *> bsqc;
	std::vector<UI_Image *> bt_op;
};

void hoverEvent(UIEventData * data);
void hoverEventEnd(UIEventData * data);
void releaseEvent(UIEventData * data);
void releaseEvent_options(UIEventData * data);
void pressEvent(UIEventData * data);

void menuEventHandler_main(UIEventData * data);

#endif // !GAME_MENU