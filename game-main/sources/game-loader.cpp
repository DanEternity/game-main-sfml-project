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

	// ��� �������� ����� ��������� ��� ������� � ����� �����
	// ��� �� �����������, �� ��� ����� ����� �� ����� ������
	// � ������ ������� ��������� �������� �� TestObject1, 
	// ������� ��������� � ����� sprites.h

	// ����� ������������ ����������� ������ ����� � �������
	// ���������� ������� ����� LoadFromSprite() � ��������
	// � �������� ��������� ��� ������ (� ������ ������
	// ��� ����� TestObject1)

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
