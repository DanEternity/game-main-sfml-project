#include "game-menu.h"

void GameMenu::Init()
{
	p_menu_bg = new UI_ObjectImage();
	p_menu_bg->LoadFromFile("sources/resources/menu_bg.jpg");

	p_play_button = new UI_ObjectImage(0);
	//p_play_button->LoadFromFile("sources/resources/play_button.jpg");
	//
	bsqc.push_back(p_play_button);

	p_continue_button = new UI_ObjectImage(1);
	//p_continue_button->LoadFromFile("sources/resources/continue_button.jpg");
	//
	bsqc.push_back(p_continue_button);

	p_settings_button = new UI_ObjectImage(2);
	//p_stats_button->LoadFromFile("sources/resources/stats_button.jpg");
	//
	bsqc.push_back(p_settings_button);

	p_stats_button = new UI_ObjectImage(3);
	//p_settings_button->LoadFromFile("sources/resources/settings_button.jpg");
	//
	bsqc.push_back(p_stats_button);

	p_exit_button = new UI_ObjectImage(4);
	//p_exit_button->LoadFromFile("sources/resources/exit_button.jpg");
	//
	bsqc.push_back(p_exit_button);

	p_credits_button = new UI_ObjectImage(5);
	p_credits_button->LoadFromSprite(menu_btsNormal[5]);
	p_credits_button->setPosition(650, 830);
	bsqc.push_back(p_credits_button);

	p_test_button = new UI_ObjectImage(6);
	p_test_button->LoadFromSprite(menu_btsNormal[6]);
	p_test_button->setPosition(650, 330);
	bt_op.push_back(p_test_button);

	for (int i(0); i < bsqc.size()-1; i++)
		bsqc[i]->LoadFromSprite(menu_btsNormal[i]);
	int m_base_x = (0.5f * resolution_w) - 198;
	int m_base_y = (0.10f * resolution_w) + 50;

	for (int i(0); i < bsqc.size() - 1; i++)
		bsqc[i]->setPosition(m_base_x, m_base_y + i * 120);
	//p_play_button->setPosition(450, 300);
	//p_continue_button->setPosition(850, 300);
	//p_stats_button->setPosition(450, 400);
	//p_settings_button->setPosition(850, 400);
	//p_exit_button->setPosition(650, 560);

	p_back_button = new UI_ObjectImage();
	p_back_button->CopyTexture(p_exit_button->sprite());
	p_back_button->setPosition(600, 560);

	bt_op.push_back(p_back_button);
	bt_st.push_back(p_back_button);



	ui_ctrl = new UI_Controller();

	for (int i(0); i < bsqc.size() - 1; i++)
	{
		ui_ctrl->AddElement(bsqc[i]);
		ui_ctrl->RegisterEvent(i, onHoverBegin, &menuEventHandler_main);
		ui_ctrl->RegisterEvent(i, onHoverEnd, &menuEventHandler_main);
		ui_ctrl->RegisterEvent(i, onPress, &menuEventHandler_main);
		ui_ctrl->RegisterEvent(i, onRelease, &menuEventHandler_main);
	}

	ui_ctrl_2 = new UI_Controller();
	for (int i(0); i < bt_op.size(); i++)
	{
		ui_ctrl_2->AddElement(bt_op[i]);
		ui_ctrl_2->RegisterEvent(i, onHoverBegin, &menuEventHandler_options);
		ui_ctrl_2->RegisterEvent(i, onHoverEnd, &menuEventHandler_options);
		ui_ctrl_2->RegisterEvent(i, onPress, &menuEventHandler_options);
		ui_ctrl_2->RegisterEvent(i, onRelease, &menuEventHandler_options);
	}

	ui_ctrl_3 = new UI_Controller();
	for (int i(0); i < bt_st.size(); i++)
	{
		ui_ctrl_3->AddElement(bt_st[i]);
		ui_ctrl_3->RegisterEvent(i, onHoverBegin, &menuEventHandler_stats);
		ui_ctrl_3->RegisterEvent(i, onHoverEnd, &menuEventHandler_stats);
		ui_ctrl_3->RegisterEvent(i, onPress, &menuEventHandler_stats);
		ui_ctrl_3->RegisterEvent(i, onRelease, &menuEventHandler_stats);
	}

	ui_ctrl_4 = new UI_Controller();
	for (int i(0); i < bt_gs.size(); i++)
	{
		ui_ctrl_4->AddElement(bt_gs[i]);
		ui_ctrl_4->RegisterEvent(i, onHoverBegin, &menuEventHandler_gameSetup);
		ui_ctrl_4->RegisterEvent(i, onHoverEnd, &menuEventHandler_gameSetup);
		ui_ctrl_4->RegisterEvent(i, onPress, &menuEventHandler_gameSetup);
		ui_ctrl_4->RegisterEvent(i, onRelease, &menuEventHandler_gameSetup);
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

				for (int i(0); i < bsqc.size() - 1; i++)
					bsqc[i]->setPosition(m_base_x, m_base_y + i * 120);
			}
			ui_ctrl->Update();

			p_menu_bg->draw();
			for (int i(0); i < bsqc.size(); i++)
				bsqc[i]->draw();
		}
		break;
	case options:
		{
			if (initMenuRequired)
			{

			}
			if (p_m_sub_state == subStateNull)
				ui_ctrl_2->Update();

			p_menu_bg->draw();
			p_back_button->draw();
			p_test_button->draw();
		}
		break;
		p_m_state = main_menu;
		break;
	case stats:
		{
			if (initMenuRequired)
			{

			}
			ui_ctrl_3->Update();

			p_menu_bg->draw();
			p_back_button->draw();
		}
		break;
	case gamesetup:
	{
		if (initMenuRequired)
		{

		}
		ui_ctrl_4->Update();
		g_mgr->setCurLevel(2);

	}
	break;
	default:
		p_m_state = main_menu;
		break;
	}
}

void GameMenu::SetButtonState(int list_id, int id, buttonState state, bool advancedMode)
{
	
	//bsqc[id]->LoadFromSprite()
	if (list_id == 0)
	{
		switch (state)
		{
		case normal:
			bsqc[id]->SetSprite(menu_btsNormal[id]);
			break;
		case hover:
			bsqc[id]->SetSprite(menu_btsHover[id]);
			break;
		case pressed:
			bsqc[id]->SetSprite(menu_btsOnClick[id]);
			break;
		case disabled:
			bsqc[id]->SetSprite(menu_btsOnClick[id]);
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
		if (idx == 0)
			g_menu->SetMenuState(main_menu);
		if (idx == 1)
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
