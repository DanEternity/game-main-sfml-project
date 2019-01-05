#include "game-loader.h"

void GameLoader::Init()
{
	p_bg = new UI_Image();
	p_bg->LoadFromFile("sources/resources/bg.jpg");
	
	p_loadingBar = new UI_Image();
	p_loadingBar->LoadFromFile("sources/resources/loading_bar.jpg");
	//p_loadingBar->sprite()->setPosition({ 500, 550 });
	p_loadingBar->setPosition(500, 550);
	//p_loadingBar->setSize(300, 50);
	//p_loadingBar->setScale(0.5f, 1);

	/* Create loading table */

	/* Post Init */

	levelInitRequired = false; // init completed
}

void GameLoader::Update()
{
	p_bg->draw();
	p_loadingBar->draw();

	/* Resource loading */
}
