#pragma once

#ifndef GAME_LOADER
#define GAME_LOADER

#include <SFML/Graphics.hpp>

#include "sprites.h"
#include "game-enviroment.h"
#include "base-manager.h"
#include "base-ui.h"
#include "debug.h"

#include <string>
#include <vector>

void Log(std::string data);

class GameLoader : public BaseManager
{
public:
	virtual void Init() override;
	virtual void Update() override;

	std::vector<std::string> tex_name;
	std::vector<sf::Sprite*> sprite_pointer;


private:

	int idx = 0;

	/* Graphics */

	UI_Image *p_bg;
	UI_Image *p_loadingBar;
};

#endif // !GAME_LOADER