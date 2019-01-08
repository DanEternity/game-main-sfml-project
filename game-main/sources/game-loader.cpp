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

	p_text = new UI_text(fontArial);
	p_text->setPosition(520, 610);

	/* Create loading table */

	std::string base = "sources/resources/";

	// example
	tex_name.push_back(base + "testSprite.png"); // texture file name
	sprite_pointer.push_back(&TestObject1);		 // pointer to SpriteObject

	// Для удобство лучше сохранять все спрайты в одном файле
	// это не обязательно, но так будет проще их потом искать
	// в данном примере указатель ссылайте на TestObject1, 
	// который находится в файле sprites.h

	// Чтобы использовать загруженный спрайт нужно у объекта
	// интерфейса вызвать метод LoadFromSprite() и передать
	// в качестве параметра это спрайт (в данном случае
	// это будет TestObject1)

	/* Post Init */

	levelInitRequired = false; // init completed
}

void GameLoader::Update()
{
	p_bg->draw();
	p_loadingBar->draw();

	*(p_text->textStream) << "Loading...";
	p_text->setColor(sf::Color::White);
	p_text->draw();

	/* Resource loading */

	if (idx < tex_name.size())
	{
		// Loading sprite texture
		sf::Texture * tex = new sf::Texture();
		if (!tex->loadFromFile(tex_name[idx]))
			Log("ERROR: texture loading failure!");

		textures.push_back(tex);

		*sprite_pointer[idx] = new sf::Sprite(*tex);
		idx++;
	}
	else
	{
		//loadCompleted = true;
	}


	if (loadCompleted)
		g_mgr->setCurLevel(1);

}
