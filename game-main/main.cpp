/*SFML INCLUDES*/
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

/*STD INCLUDES*/
#include <iostream>

/*GAME INCLUDES*/
#include "sources\game-enviroment.h"
#include "sources\sprites.h"
#include "sources\debug.h"
#include "resource.h"
#include "sources\custom-types.h"

void init();
void debug();

/*CODE*/
int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(resolution_w, resolution_h), "SFML window");
	g_wnd = &window;
	
	Log("######## Status window ########");
	Log("Start initialization...");

	init();

	Log("Initialization complete");

	g_mgr->setCurLevel(0);

	// Start the game loop
	while (window.isOpen() && gameRun)
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// Clear screen
		window.clear();

		g_mgr->run(); // update frame
		
		window.display();
	}
	return EXIT_SUCCESS;
}

void init()
{
	g_wnd->setSize({ unsigned int(resolution_w), unsigned int(resolution_h) });

	sys_screen_w = sf::VideoMode::getDesktopMode().width;
	sys_screen_h = sf::VideoMode::getDesktopMode().height;
	
	g_wnd->setPosition({ (sys_screen_w - resolution_w - 4) / 2, (sys_screen_h - resolution_h - 34) / 2 });

	g_mgr = new GlobalManager();
	g_loader = new GameLoader();
	g_menu = new GameMenu();
	g_adv = new AdventureManager();

	g_mgr->addLevel(g_loader);
	g_mgr->addLevel(g_menu);
	g_mgr->addLevel(g_adv);

	g_wnd->setFramerateLimit(120);

	fontArial = new sf::Font();
	fontArial->loadFromFile("sources/fonts/arial.ttf");

	debug();
}

void debug()
{
	QGlobalEvent q;
	q.type = initGameDebug;
	EventList.push(q);
}