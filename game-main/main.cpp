/*SFML INCLUDES*/
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

/*STD INCLUDES*/
#include <iostream>

/*GAME INCLUDES*/
#include "sources\game-enviroment.h"
#include "sources\sprites.h"
#include "sources\debug.h"

/*CODE*/
int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML window");
	g_wnd = &window;

	Log("######## Status window ########");
	Log("Start initialization...");

	g_wnd->setSize({ 1600, 900 });
	g_wnd->setPosition({ 0, 0 });

	g_mgr = new GlobalManager();
	g_loader = new GameLoader();
	g_menu = new GameMenu();

	g_mgr->addLevel(g_loader);
	g_mgr->addLevel(g_menu);
	g_wnd->setFramerateLimit(120);

	// Load a sprite to display
	//sf::Texture texture;
	//if (!texture.loadFromFile("cute_image.jpg"))
	//	return EXIT_FAILURE;
	//sf::Sprite sprite(texture);
	
	// Create a graphical text to display
	//sf::Font font;
	//if (!font.loadFromFile("arial.ttf"))
	//	return EXIT_FAILURE;
	//sf::Text text("Hello SFML", font, 50);
	// Load a music to play
	//sf::Music music;
	//if (!music.openFromFile("nice_music.ogg"))
	//	return EXIT_FAILURE;
	// Play the music
	//music.play();

	// Start the game loop
	Log("Initialization complete");

	while (window.isOpen())
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
		
		// Draw the sprite
		//window.draw(sprite);
		// Draw the string
		//window.draw(text);
		// Update the window
		window.display();
	}
	return EXIT_SUCCESS;
}