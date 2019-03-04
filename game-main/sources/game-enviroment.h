#pragma once


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <vector>
#include <queue>

#include "custom-types.h"
#include "global-manager.h"
//#include "landing-main.h"

class GlobalManager; // forward definition of classes
class GameLoader;
class GameMenu;
class UI_Controller;
class AdventureManager;
class Ship;
class LandingManager;

extern GlobalManager * g_mgr; // Global manager pointer
extern GameLoader * g_loader; // Game loader pointer
extern GameMenu * g_menu; // GameMenu manager pointer
extern AdventureManager * g_adv; // Adventure manager pointer
extern LandingManager * g_land; // landing pointer
//extern Ship * g_ship; // Player's main ship

//extern std::vector<sf::Texture *> textures;


/* functions */

int GetUID();

/* System info */

extern int sys_screen_w;
extern int sys_screen_h;

/* Game settings */

extern int resolution_w; // x
extern int resolution_h; // y

extern int testValue;

extern int storageTableBaseX;
extern int storageTableBaseY;


/* Game information */

extern bool gameRun;
extern std::queue<QGlobalEvent> EventList; // Events



