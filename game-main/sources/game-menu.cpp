#include "game-menu.h"

void GameMenu::Init()
{
	p_menu_bg = new UI_Image();
	p_menu_bg->LoadFromFile("sources/resources/menu_bg.jpg");

	p_play_button = new UI_Image();
	//p_play_button->LoadFromFile("sources/resources/play_button.jpg");
	//
	bsqc.push_back(p_play_button);

	p_continue_button = new UI_Image();
	//p_continue_button->LoadFromFile("sources/resources/continue_button.jpg");
	//
	bsqc.push_back(p_continue_button);

	p_stats_button = new UI_Image();
	//p_stats_button->LoadFromFile("sources/resources/stats_button.jpg");
	//
	bsqc.push_back(p_stats_button);

	p_settings_button = new UI_Image();
	//p_settings_button->LoadFromFile("sources/resources/settings_button.jpg");
	//
	bsqc.push_back(p_settings_button);

	p_exit_button = new UI_Image();
	//p_exit_button->LoadFromFile("sources/resources/exit_button.jpg");
	//
	bsqc.push_back(p_exit_button);

	p_credits_button = new UI_Image();
	p_credits_button->LoadFromFile("sources/resources/credits_button.jpg");
	p_credits_button->setPosition(650, 830);
	bsqc.push_back(p_credits_button);

	for (int i(0); i < bsqc.size()-1; i++)
		bsqc[i]->LoadFromSprite(menu_btsNormal[i]);

	p_play_button->setPosition(450, 300);
	p_continue_button->setPosition(850, 300);
	p_stats_button->setPosition(450, 400);
	p_settings_button->setPosition(850, 400);
	p_exit_button->setPosition(650, 560);

	levelInitRequired = false;
}

void GameMenu::Update()
{
	p_menu_bg->draw();
	for (int i(0); i < bsqc.size(); i++)
		bsqc[i]->draw();
}
