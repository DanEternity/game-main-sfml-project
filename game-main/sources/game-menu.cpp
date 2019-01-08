#include "game-menu.h"

void GameMenu::Init()
{
	p_menu_bg = new UI_Image();
	p_menu_bg->LoadFromFile("sources/resources/menu_bg.jpg");
}

void GameMenu::Update()
{
	p_menu_bg->draw();
}
