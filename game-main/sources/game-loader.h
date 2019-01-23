#pragma once

#ifndef GAME_LOADER
#define GAME_LOADER

#include <SFML/Graphics.hpp>

#include "sprites.h"
#include "game-enviroment.h"
#include "base-manager.h"
#include "base-ui.h"
#include "debug.h"
#include "ui-text.h"
#include "wnd-utils.h"
#include "ui-base-elements.h"

#include <string>
#include <vector>

class UI_text;
class UI_Image;

class GameLoader : public BaseManager
{
public:
	virtual void Init() override;
	virtual void Update() override;

	std::vector<std::string> tex_name;
	std::vector<sf::Sprite**> sprite_pointer;


private:

	int idx = 0;
	bool loadCompleted = false;

	/* Graphics */
	UI_Image *test;
	UI_Image *p_bg;
	UI_Image *p_loadingBar;
	 
	UI_text * p_text;

};

#endif // !GAME_LOADER