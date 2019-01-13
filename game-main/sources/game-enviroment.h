#pragma once


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "global-manager.h"
#include "game-loader.h"
#include "game-menu.h"
#include "adventure-main.h"
#include "Ship.h"


#include <vector>
#include <queue>



class GlobalManager; // forward definition of classes
class GameLoader;
class GameMenu;
class UI_Controller;
class AdventureManager;
class Ship;

extern sf::RenderWindow * g_wnd; // main window pointer
extern GlobalManager * g_mgr; // Global manager pointer
extern GameLoader * g_loader; // Game loader pointer
extern GameMenu * g_menu; // GameMenu manager pointer
extern AdventureManager * g_adv; // Adventure manager pointer
extern Ship * g_ship; // Player's main ship

extern std::vector<sf::Texture *> textures;
extern sf::Font * fontArial;

/* functions */

int GetUID();

/* System info */

extern int sys_screen_w;
extern int sys_screen_h;

/* Game settings */

extern int resolution_w; // x
extern int resolution_h; // y



/* Game information */

extern std::queue<QGlobalEvent> EventList; // Events



