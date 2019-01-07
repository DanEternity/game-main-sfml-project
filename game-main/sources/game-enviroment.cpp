#include "game-enviroment.h"

sf::RenderWindow * g_wnd; // main window pointer
GlobalManager * g_mgr; // Global manager pointer
GameLoader * g_loader; // Game loader pointer
GameMenu * g_menu; // GameMenu manager pointer

std::vector<sf::Texture *> textures;