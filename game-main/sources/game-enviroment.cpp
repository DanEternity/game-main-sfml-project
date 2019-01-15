#include "game-enviroment.h"

sf::RenderWindow * g_wnd; // main window pointer
GlobalManager * g_mgr; // Global manager pointer
GameLoader * g_loader; // Game loader pointer
GameMenu * g_menu; // GameMenu manager pointer
AdventureManager * g_adv; // Adventure manager pointer

std::vector<sf::Texture *> textures;
sf::Font * fontArial;

int sys_screen_w;
int sys_screen_h;

int resolution_w = 1600; // x
int resolution_h = 900; // y

int testValue = 0;

bool gameRun = true;

/* Game constants */

//const int HullResistN = 2;
//const int ShieldResistN = 2;

std::queue<QGlobalEvent> EventList; // Events

int GetUID()
{
	static int baseID = 0;
	return (baseID++);
}
