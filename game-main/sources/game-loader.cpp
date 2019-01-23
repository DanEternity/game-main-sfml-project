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

	/* Menu buttons */

	tex_name.push_back(base + "start1normal.png");
	sprite_pointer.push_back(&menu_btsNormal[0]);
	tex_name.push_back(base + "start1hover.png");
	sprite_pointer.push_back(&menu_btsHover[0]);
	tex_name.push_back(base + "start1onclick.png");
	sprite_pointer.push_back(&menu_btsOnClick[0]);

	tex_name.push_back(base + "continue1normal.png");
	sprite_pointer.push_back(&menu_btsNormal[1]);
	tex_name.push_back(base + "continue1hover.png");
	sprite_pointer.push_back(&menu_btsHover[1]);
	tex_name.push_back(base + "continue1onclick.png");
	sprite_pointer.push_back(&menu_btsOnClick[1]);

	tex_name.push_back(base + "options1normal.png");
	sprite_pointer.push_back(&menu_btsNormal[2]);
	tex_name.push_back(base + "options1hover.png");
	sprite_pointer.push_back(&menu_btsHover[2]);
	tex_name.push_back(base + "options1onclick.png");
	sprite_pointer.push_back(&menu_btsOnClick[2]);

	tex_name.push_back(base + "stats1normal.png");
	sprite_pointer.push_back(&menu_btsNormal[3]);
	tex_name.push_back(base + "stats1hover.png");
	sprite_pointer.push_back(&menu_btsHover[3]);
	tex_name.push_back(base + "stats1onclick.png");
	sprite_pointer.push_back(&menu_btsOnClick[3]);

	tex_name.push_back(base + "exit1normal.png");
	sprite_pointer.push_back(&menu_btsNormal[4]);
	tex_name.push_back(base + "exit1hover.png");
	sprite_pointer.push_back(&menu_btsHover[4]);
	tex_name.push_back(base + "exit1onclick.png");
	sprite_pointer.push_back(&menu_btsOnClick[4]);

	tex_name.push_back(base + "credits_button.jpg");
	sprite_pointer.push_back(&menu_btsNormal[5]);
	tex_name.push_back(base + "credits_button.jpg");
	sprite_pointer.push_back(&menu_btsHover[5]);
	tex_name.push_back(base + "credits_button.jpg");
	sprite_pointer.push_back(&menu_btsOnClick[5]);

	tex_name.push_back(base + "settings_button.jpg");
	sprite_pointer.push_back(&menu_btsNormal[6]);
	tex_name.push_back(base + "settings_button.jpg");
	sprite_pointer.push_back(&menu_btsHover[6]);
	tex_name.push_back(base + "settings_button.jpg");
	sprite_pointer.push_back(&menu_btsOnClick[6]);

	tex_name.push_back(base + "btn_arrow_left.png");
	sprite_pointer.push_back(&menu_btsNormal[7]);
	tex_name.push_back(base + "btn_arrow_left.png");
	sprite_pointer.push_back(&menu_btsHover[7]);
	tex_name.push_back(base + "btn_arrow_left.png");
	sprite_pointer.push_back(&menu_btsOnClick[7]);

	tex_name.push_back(base + "btn_arrow_right.png");
	sprite_pointer.push_back(&menu_btsNormal[8]);
	tex_name.push_back(base + "btn_arrow_right.png");
	sprite_pointer.push_back(&menu_btsHover[8]);
	tex_name.push_back(base + "btn_arrow_right.png");
	sprite_pointer.push_back(&menu_btsOnClick[8]);

	/* Scroller textures */

	tex_name.push_back(base + "scroller/base_400.png");
	sprite_pointer.push_back(&scroller_base_400);
	tex_name.push_back(base + "scroller/b1_normal.png");
	sprite_pointer.push_back(&scroller_btn_v1[0]);
	tex_name.push_back(base + "scroller/b1_hover.png");
	sprite_pointer.push_back(&scroller_btn_v1[1]);
	tex_name.push_back(base + "scroller/b1_pressed.png");
	sprite_pointer.push_back(&scroller_btn_v1[2]);

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

		//textures.push_back(tex);

		*sprite_pointer[idx] = new sf::Sprite(*tex);
		idx++;
	}
	else
	{
		loadCompleted = true;
	}


	if (loadCompleted)
		g_mgr->setCurLevel(1);

}
