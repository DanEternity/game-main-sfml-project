#include "game-menu.h"

void GameMenu::Init()
{
	text = new UI_text(fontArial);
	text->setColor(sf::Color::White);

	p_menu_bg = new UI_ObjectImage();
	p_menu_bg->LoadFromFile("sources/resources/menu_bg.jpg");

	p_op_wnd_bg = new UI_ObjectImage();
	p_op_wnd_bg->LoadFromFile("sources/resources/window_options_bg.png");
	int posx, posy;
	posx = resolution_w/2 - p_op_wnd_bg->sprite()->getTexture()->getSize().x/2;
	posy = resolution_h/2 - p_op_wnd_bg->sprite()->getTexture()->getSize().y/2;
	p_op_wnd_bg->setPosition(posx, posy);

	p_play_button = new UI_ObjectImage(0);
	//p_play_button->LoadFromFile("sources/resources/play_button.jpg");
	//
	bt_mm.push_back(p_play_button);

	p_continue_button = new UI_ObjectImage(1);
	//p_continue_button->LoadFromFile("sources/resources/continue_button.jpg");
	//
	bt_mm.push_back(p_continue_button);

	p_settings_button = new UI_ObjectImage(2);
	//p_stats_button->LoadFromFile("sources/resources/stats_button.jpg");
	//
	bt_mm.push_back(p_settings_button);

	p_stats_button = new UI_ObjectImage(3);
	//p_settings_button->LoadFromFile("sources/resources/settings_button.jpg");
	//
	bt_mm.push_back(p_stats_button);

	p_exit_button = new UI_ObjectImage(4);
	//p_exit_button->LoadFromFile("sources/resources/exit_button.jpg");
	//
	bt_mm.push_back(p_exit_button);

	p_credits_button = new UI_ObjectImage(5);
	p_credits_button->LoadFromSprite(menu_btsNormal[5]);
	p_credits_button->setPosition(650, 830);
	bt_mm.push_back(p_credits_button);

	p_test_button = new UI_ObjectImage(6);
	p_test_button->LoadFromSprite(menu_btsNormal[6]);
	p_test_button->setPosition(650, 330);
	bt_op.push_back(p_test_button);

	for (int i(0); i < bt_mm.size()-1; i++)
		bt_mm[i]->LoadFromSprite(menu_btsNormal[i]);
	int m_base_x = (0.5f * resolution_w) - 198;
	int m_base_y = (0.10f * resolution_w) + 50;

	for (int i(0); i < bt_mm.size() - 1; i++)
		bt_mm[i]->setPosition(m_base_x, m_base_y + i * 120);
	//p_play_button->setPosition(450, 300);
	//p_continue_button->setPosition(850, 300);
	//p_stats_button->setPosition(450, 400);
	//p_settings_button->setPosition(850, 400);
	//p_exit_button->setPosition(650, 560);

	p_back_button = new UI_ObjectImage(4);
	p_back_button->CopyTexture(p_exit_button->sprite());
	p_back_button->setPosition(600, 560);

	bt_op.push_back(p_back_button);
	bt_op_wnd.push_back(p_back_button);
	bt_st.push_back(p_back_button);

	p_larw_button = new UI_ObjectImage(7);
	p_larw_button->LoadFromSprite(menu_btsNormal[7]);
	p_larw_button->setPosition(posx + 293, posy + 200);
	bt_op_wnd.push_back(p_larw_button);

	p_rarw_button = new UI_ObjectImage(8);
	p_rarw_button->LoadFromSprite(menu_btsNormal[8]);
	p_rarw_button->setPosition(posx + 443, posy + 200);
	bt_op_wnd.push_back(p_rarw_button);



	ui_ctrl_mm = new UI_Controller();

	for (int i(0); i < bt_mm.size() - 1; i++)
	{
		ui_ctrl_mm->AddElement(bt_mm[i]);
		ui_ctrl_mm->RegisterEvent(i, onHoverBegin, &menuEventHandler_main);
		ui_ctrl_mm->RegisterEvent(i, onHoverEnd, &menuEventHandler_main);
		ui_ctrl_mm->RegisterEvent(i, onPress, &menuEventHandler_main);
		ui_ctrl_mm->RegisterEvent(i, onRelease, &menuEventHandler_main);
	}

	ui_ctrl_op = new UI_Controller();
	for (int i(0); i < bt_op.size(); i++)
	{
		ui_ctrl_op->AddElement(bt_op[i]);
		ui_ctrl_op->RegisterEvent(i, onHoverBegin, &menuEventHandler_options);
		ui_ctrl_op->RegisterEvent(i, onHoverEnd, &menuEventHandler_options);
		ui_ctrl_op->RegisterEvent(i, onPress, &menuEventHandler_options);
		ui_ctrl_op->RegisterEvent(i, onRelease, &menuEventHandler_options);
	}

	ui_ctrl_op_wnd = new UI_Controller();
	for (int i(0); i < bt_op_wnd.size(); i++)
	{
		ui_ctrl_op_wnd->AddElement(bt_op_wnd[i]);
		ui_ctrl_op_wnd->RegisterEvent(i, onHoverBegin, &menuEventHandler_options_wnd);
		ui_ctrl_op_wnd->RegisterEvent(i, onHoverEnd, &menuEventHandler_options_wnd);
		ui_ctrl_op_wnd->RegisterEvent(i, onPress, &menuEventHandler_options_wnd);
		ui_ctrl_op_wnd->RegisterEvent(i, onRelease, &menuEventHandler_options_wnd);
	}

	ui_ctrl_st = new UI_Controller();
	for (int i(0); i < bt_st.size(); i++)
	{
		ui_ctrl_st->AddElement(bt_st[i]);
		ui_ctrl_st->RegisterEvent(i, onHoverBegin, &menuEventHandler_stats);
		ui_ctrl_st->RegisterEvent(i, onHoverEnd, &menuEventHandler_stats);
		ui_ctrl_st->RegisterEvent(i, onPress, &menuEventHandler_stats);
		ui_ctrl_st->RegisterEvent(i, onRelease, &menuEventHandler_stats);
	}

	ui_ctrl_ng = new UI_Controller();
	for (int i(0); i < bt_ng.size(); i++)
	{
		ui_ctrl_ng->AddElement(bt_ng[i]);
		ui_ctrl_ng->RegisterEvent(i, onHoverBegin, &menuEventHandler_gameSetup);
		ui_ctrl_ng->RegisterEvent(i, onHoverEnd, &menuEventHandler_gameSetup);
		ui_ctrl_ng->RegisterEvent(i, onPress, &menuEventHandler_gameSetup);
		ui_ctrl_ng->RegisterEvent(i, onRelease, &menuEventHandler_gameSetup);
	}

	levelInitRequired = false;
}

void GameMenu::Update()
{
	switch (p_m_state)
	{
	case main_menu:
		{
			if (initMenuRequired)
			{
				int m_base_x = (0.5f * resolution_w) - 198;
				int m_base_y = (0.10f * resolution_w) + 50;

				for (int i(0); i < bt_mm.size() - 1; i++)
					bt_mm[i]->setPosition(m_base_x, m_base_y + i * 120);
			}
			ui_ctrl_mm->Update();

			p_menu_bg->draw();
			for (int i(0); i < bt_mm.size(); i++)
				bt_mm[i]->draw();
		}
		break;
	case options:
		{
		UpdateOptions();

		}
		break;
		p_m_state = main_menu;
		break;
	case stats:
		{
			if (initMenuRequired)
			{

			}
			ui_ctrl_st->Update();

			p_menu_bg->draw();
			p_back_button->draw();
		}
		break;
	case gamesetup:
	{
		if (initMenuRequired)
		{

		}
		ui_ctrl_ng->Update();
		g_mgr->setCurLevel(2);

	}
	break;
	default:
		p_m_state = main_menu;
		break;
	}
}

void GameMenu::UpdateOptions()
{
	if (initMenuRequired)
	{

	}
	if (p_m_sub_state == subStateNull)
	{
		p_menu_bg->draw();
		p_back_button->draw();
		p_test_button->draw();
		ui_ctrl_op->Update();
	}
	if (p_m_sub_state == optionsWindowed)
	{
		ui_ctrl_op_wnd->Update();
		p_menu_bg->draw();
		p_op_wnd_bg->draw();
		p_larw_button->draw();
		p_rarw_button->draw();
		p_back_button->draw();
		
		text->outTextXY(785, 360, std::to_string(testValue));
		text->draw();
	}


}

void GameMenu::SetButtonState(int list_id, int id, buttonState state, bool advancedMode)
{
	
	//bt_mm[id]->LoadFromSprite()
	if (list_id == 0)
	{
		switch (state)
		{
		case normal:
			bt_mm[id]->SetSprite(menu_btsNormal[id]);
			break;
		case hover:
			bt_mm[id]->SetSprite(menu_btsHover[id]);
			break;
		case pressed:
			bt_mm[id]->SetSprite(menu_btsOnClick[id]);
			break;
		case disabled:
			bt_mm[id]->SetSprite(menu_btsOnClick[id]);
			break;
		default:
			Log("Error. Wrong button state.");
			break;
		}
	}
	if (list_id == 1)
	{
		if (!advancedMode)
		{
			switch (state)
			{
			case normal:
				bt_op[id]->SetSprite(menu_btsNormal[id]);
				break;
			case hover:
				bt_op[id]->SetSprite(menu_btsHover[id]);
				break;
			case pressed:
				bt_op[id]->SetSprite(menu_btsOnClick[id]);
				break;
			case disabled:
				bt_op[id]->SetSprite(menu_btsOnClick[id]);
				break;
			default:
				Log("Error. Wrong button state.");
				break;
			}
		}
		else
		{
			switch (state)
			{
			case normal:
				bt_op[id]->SetSprite(menu_btsNormal[bt_op[id]->localID]);
				break;
			case hover:
				bt_op[id]->SetSprite(menu_btsHover[bt_op[id]->localID]);
				break;
			case pressed:
				bt_op[id]->SetSprite(menu_btsOnClick[bt_op[id]->localID]);
				break;
			case disabled:
				bt_op[id]->SetSprite(menu_btsOnClick[bt_op[id]->localID]);
				break;
			default:
				Log("Error. Wrong button state.");
				break;
			}
		}
	}
	if (list_id == 2)
	{
		switch (state)
		{
		case normal:
			bt_st[id]->SetSprite(menu_btsNormal[id]);
			break;
		case hover:
			bt_st[id]->SetSprite(menu_btsHover[id]);
			break;
		case pressed:
			bt_st[id]->SetSprite(menu_btsOnClick[id]);
			break;
		case disabled:
			bt_st[id]->SetSprite(menu_btsOnClick[id]);
			break;
		default:
			Log("Error. Wrong button state.");
			break;
		}
	}

	if (list_id == 4)
	{
		if (!advancedMode)
		{
			switch (state)
			{
			case normal:
				bt_op_wnd[id]->SetSprite(menu_btsNormal[id]);
				break;
			case hover:
				bt_op_wnd[id]->SetSprite(menu_btsHover[id]);
				break;
			case pressed:
				bt_op_wnd[id]->SetSprite(menu_btsOnClick[id]);
				break;
			case disabled:
				bt_op_wnd[id]->SetSprite(menu_btsOnClick[id]);
				break;
			default:
				Log("Error. Wrong button state.");
				break;
			}
		}
		else
		{
			switch (state)
			{
			case normal:
				bt_op_wnd[id]->SetSprite(menu_btsNormal[bt_op_wnd[id]->localID]);
				break;
			case hover:
				bt_op_wnd[id]->SetSprite(menu_btsHover[bt_op_wnd[id]->localID]);
				break;
			case pressed:
				bt_op_wnd[id]->SetSprite(menu_btsOnClick[bt_op_wnd[id]->localID]);
				break;
			case disabled:
				bt_op_wnd[id]->SetSprite(menu_btsOnClick[bt_op_wnd[id]->localID]);
				break;
			default:
				Log("Error. Wrong button state.");
				break;
			}
		}
	}
}

void GameMenu::SetMenuState(gameMenuState state)
{
	initMenuRequired = true;
	p_m_state = state;
}

void GameMenu::SetMenuSubState(gameMenuSubState state)
{
	initMenuRequired = true;
	p_m_sub_state = state;
}


void menuEventHandler_main(UIEventData * data)
{
	auto type = data->eventType;

	switch (type)
	{
	case onPress:
		{
			int idx = data->objectID;

			g_menu->SetButtonState(0, idx, pressed);
		}
		break;
	case onRelease:
		{
			int idx = data->objectID;

			if (idx == 0)
				g_menu->SetMenuState(gamesetup);
			if (idx == 2)
				g_menu->SetMenuState(options);
			if (idx == 3)
				g_menu->SetMenuState(stats);

			g_menu->SetButtonState(0, idx, hover);
		}
		break;
	case onHoverBegin:
		{
			int idx = data->objectID;

			g_menu->SetButtonState(0, idx, hover);
		}
		break;
	case onHoverEnd:
		{
			int idx = data->objectID;

			g_menu->SetButtonState(0, idx, normal);
		}
		break;
	default:
		break;
	}
}

void menuEventHandler_options(UIEventData * data)
{
	auto type = data->eventType;

	switch (type)
	{
	case onPress:
	{
		int idx = data->ref->localID;
		int idx2 = data->objectID;

		g_menu->SetButtonState(1, idx2, pressed, true);
	}
	break;
	case onRelease:
	{
		int idx = data->ref->localID;
		int idx2 = data->objectID;
		if (idx == 4)
			g_menu->SetMenuState(main_menu);
		if (idx == 6)
			g_menu->SetMenuSubState(optionsWindowed);
		g_menu->SetButtonState(1, idx2, hover, true);
	}
	break;
	case onHoverBegin:
	{
		int idx = data->ref->localID;
		int idx2 = data->objectID;

		g_menu->SetButtonState(1, idx2, hover, true);
	}
	break;
	case onHoverEnd:
	{
		int idx = data->ref->localID;
		int idx2 = data->objectID;

		g_menu->SetButtonState(1, idx2, normal, true);
	}
	break;
	default:
		break;
	}
}

void menuEventHandler_options_wnd(UIEventData * data)
{
	auto type = data->eventType;

	switch (type)
	{
	case onPress:
	{
		int idx = data->ref->localID;
		int idx2 = data->objectID;

		g_menu->SetButtonState(4, idx2, pressed, true);
	}
	break;
	case onRelease:
	{
		int idx = data->ref->localID;
		int idx2 = data->objectID;
		if (idx == 4)
			g_menu->SetMenuSubState(subStateNull);
		
		if (idx == 7)
		{
			testValue -= 1;
		}
		if (idx == 8)
		{
			testValue += 1;
		}

		g_menu->SetButtonState(4, idx2, hover, true);
	}
	break;
	case onHoverBegin:
	{
		int idx = data->ref->localID;
		int idx2 = data->objectID;

		g_menu->SetButtonState(4, idx2, hover, true);
	}
	break;
	case onHoverEnd:
	{
		int idx = data->ref->localID;
		int idx2 = data->objectID;

		g_menu->SetButtonState(4, idx2, normal, true);
	}
	break;
	default:
		break;
	}
}

void menuEventHandler_stats(UIEventData * data)
{
	auto type = data->eventType;

	switch (type)
	{
	case onPress:
	{
		int idx = data->objectID;

		g_menu->SetButtonState(2, idx, pressed);
	}
	break;
	case onRelease:
	{
		int idx = data->objectID;

		if (idx == 0)
			g_menu->SetMenuState(main_menu);
		g_menu->SetButtonState(2, idx, hover);
	}
	break;
	case onHoverBegin:
	{
		int idx = data->objectID;

		g_menu->SetButtonState(2, idx, hover);
	}
	break;
	case onHoverEnd:
	{
		int idx = data->objectID;

		g_menu->SetButtonState(2, idx, normal);
	}
	break;
	default:
		break;
	}
}

void menuEventHandler_gameSetup(UIEventData * data)
{
	auto type = data->eventType;

	switch (type)
	{
	case onPress:
	{
		int idx = data->objectID;

		g_menu->SetButtonState(3, idx, pressed);
	}
	break;
	case onRelease:
	{
		int idx = data->objectID;

		if (idx == 0)
			g_menu->SetMenuState(main_menu);
		g_menu->SetButtonState(3, idx, hover);
	}
	break;
	case onHoverBegin:
	{
		int idx = data->objectID;

		g_menu->SetButtonState(3, idx, hover);
	}
	break;
	case onHoverEnd:
	{
		int idx = data->objectID;

		g_menu->SetButtonState(3, idx, normal);
	}
	break;
	default:
		break;
	}
}
