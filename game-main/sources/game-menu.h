#pragma once

#ifndef GAME_MENU
#define GAME_MENU

#include "base-manager.h"
#include "custom-types.h"
#include "ui-objects.h"
#include "ui-controller.h"
#include "game-enviroment.h"
#include "sprites.h"
#include "debug.h"
#include "ui-text.h"

#include <vector>

class UI_Controller;
class UI_ObjectImage;

class GameMenu : public BaseManager
{
public:
	virtual void Init() override;
	virtual void Update() override;
	////////////////////////////////////


	void UpdateOptions();
	void SetButtonState(int list_id, int id, buttonState state, bool advancedMode = false);
	void SetMenuState(gameMenuState state);
	void SetMenuSubState(gameMenuSubState state);
	bool initMenuRequired;

private:

	gameMenuState p_m_state = main_menu;
	gameMenuSubState p_m_sub_state = subStateNull;

	UI_Controller * ui_ctrl_mm;
	UI_Controller * ui_ctrl_op;
	UI_Controller * ui_ctrl_st;
	UI_Controller * ui_ctrl_ng;
	UI_Controller * ui_ctrl_op_wnd;

	UI_ObjectImage *p_menu_bg;
	UI_ObjectImage *p_op_wnd_bg; // windowed options background
	UI_ObjectImage *p_play_button;
	UI_ObjectImage *p_continue_button;
	UI_ObjectImage *p_stats_button;
	UI_ObjectImage *p_settings_button;
	UI_ObjectImage *p_credits_button;
	UI_ObjectImage *p_exit_button;

	UI_ObjectImage *p_back_button;
	UI_ObjectImage *p_test_button;

	UI_ObjectImage *p_larw_button; // left arrow
	UI_ObjectImage *p_rarw_button; // right arrow

	UI_text * text;

	std::vector<UI_ObjectImage *> bt_mm; // main menu buttons
	std::vector<UI_ObjectImage *> bt_op; // options buttons
	std::vector<UI_ObjectImage *> bt_op_wnd; // windowed options buttons
	std::vector<UI_ObjectImage *> bt_st; // statistics buttons
	std::vector<UI_ObjectImage *> bt_ng; // new game setup buttons
};


void menuEventHandler_main(UIEventData * data);
void menuEventHandler_options(UIEventData * data);
void menuEventHandler_stats(UIEventData * data);
void menuEventHandler_gameSetup(UIEventData * data);
void menuEventHandler_options_wnd(UIEventData * data);

#endif // !GAME_MENU