#pragma once


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "global-manager.h"
#include "game-loader.h"
#include "game-menu.h"

#include <vector>




class GlobalManager; // forward definition of classes
class GameLoader;
class GameMenu;

extern sf::RenderWindow * g_wnd; // main window pointer
extern GlobalManager * g_mgr; // Global manager pointer
extern GameLoader * g_loader; // Game loader pointer
extern GameMenu * g_menu; // GameMenu manager pointer

extern std::vector<sf::Texture *> textures;
