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

	/* adenture ui textures */

	tex_name.push_back(base + "adventure_ui/InfoBoxBG1.png");
	sprite_pointer.push_back(&itemInfoBoxBackground[0]);
	addResource(&itemInfoBoxBackground[1], base + "adventure_ui/InfoBoxBG1TOP.png");
	addResource(&itemInfoBoxBackground[2], base + "adventure_ui/InfoBoxBG1MID.png");
	addResource(&itemInfoBoxBackground[3], base + "adventure_ui/InfoBoxBG1BOT.png");

	addResource(&UI_leftDown, base + "adventure_ui/leftDown.png");
	addResource(&UI_rightDown, base + "adventure_ui/rightDown.png");
	addResource(&UI_leftTop, base + "adventure_ui/not_found.png");
	addResource(&UI_rightTop, base + "adventure_ui/not_found.png");

	addResource(&UI_adv_element[0], base + "adventure_ui/element_ship_background_right.png");
	addResource(&UI_adv_element[1], base + "adventure_ui/element_ship_background_scheme.png");

	addResource(&UI_adv_btns[0][0], base + "adventure_ui/btnShip.png");
	addResource(&UI_adv_btns[0][1], base + "adventure_ui/btnShip.png");
	addResource(&UI_adv_btns[0][2], base + "adventure_ui/btnShip.png");
	addResource(&UI_adv_btns[1][0], base + "adventure_ui/btnChar.png");
	addResource(&UI_adv_btns[1][1], base + "adventure_ui/btnChar.png");
	addResource(&UI_adv_btns[1][2], base + "adventure_ui/btnChar.png");
	addResource(&UI_adv_btns[2][0], base + "adventure_ui/btnMap.png");
	addResource(&UI_adv_btns[2][1], base + "adventure_ui/btnMap.png");
	addResource(&UI_adv_btns[2][2], base + "adventure_ui/btnMap.png");
	addResource(&UI_adv_btns[3][0], base + "adventure_ui/btnLog.png");
	addResource(&UI_adv_btns[3][1], base + "adventure_ui/btnLog.png");
	addResource(&UI_adv_btns[3][2], base + "adventure_ui/btnLog.png");
	addResource(&UI_adv_btns[4][0], base + "adventure_ui/btnShipFull.png");
	addResource(&UI_adv_btns[4][1], base + "adventure_ui/btnShipFull.png");
	addResource(&UI_adv_btns[4][2], base + "adventure_ui/btnShipFull.png");
	addResource(&UI_adv_btns[5][0], base + "adventure_ui/btnLabFull.png");
	addResource(&UI_adv_btns[5][1], base + "adventure_ui/btnLabFull.png");
	addResource(&UI_adv_btns[5][2], base + "adventure_ui/btnLabFull.png");
	addResource(&UI_adv_btns[6][0], base + "adventure_ui/btnCrewFull.png");
	addResource(&UI_adv_btns[6][1], base + "adventure_ui/btnCrewFull.png");
	addResource(&UI_adv_btns[6][2], base + "adventure_ui/btnCrewFull.png");
	addResource(&UI_adv_btns[7][0], base + "adventure_ui/btnCraftFull.png");
	addResource(&UI_adv_btns[7][1], base + "adventure_ui/btnCraftFull.png");
	addResource(&UI_adv_btns[7][2], base + "adventure_ui/btnCraftFull.png");
	addResource(&UI_adv_btns[8][0], base + "adventure_ui/btnStorageFull.png");
	addResource(&UI_adv_btns[8][1], base + "adventure_ui/btnStorageFull.png");
	addResource(&UI_adv_btns[8][2], base + "adventure_ui/btnStorageFull.png");
	addResource(&UI_adv_btns[9][0], base + "adventure_ui/btnStatsFull.png");
	addResource(&UI_adv_btns[9][1], base + "adventure_ui/btnStatsFull.png");
	addResource(&UI_adv_btns[9][2], base + "adventure_ui/btnStatsFull.png");
	addResource(&UI_adv_btns[10][0], base + "adventure_ui/btnHangarFull.png");
	addResource(&UI_adv_btns[10][1], base + "adventure_ui/btnHangarFull.png");
	addResource(&UI_adv_btns[10][2], base + "adventure_ui/btnHangarFull.png");

	addResource(&UI_adv_window_bg, base + "adventure_ui/windowBG.png");
	addResource(&UI_adv_marker_base, base + "adventure_ui/marker_base_cyan.png");
	addResource(&UI_adv_marker_info, base + "adventure_ui/marker_info.png");
	addResource(&ship_sprites[0], base + "adventure_ui/Ship1.png");

	addResource(&UI_adv_module_slots[slot_Core], base + "adventure_ui/s/slotCore.png");
	addResource(&UI_adv_module_slots[slot_Engine], base + "adventure_ui/s/slotEngine.png");
	addResource(&UI_adv_module_slots[slot_HyperDrive], base + "adventure_ui/s/slotHD.png");
	addResource(&UI_adv_module_slots[slot_System], base + "adventure_ui/s/slotSystem.png");
	addResource(&UI_adv_module_slots[slot_Universal], base + "adventure_ui/s/slotUniversal.png");
	addResource(&UI_adv_module_slots[slot_MainWeapon], base + "adventure_ui/s/slotWep.png");
	addResource(&UI_adv_module_slots[slot_SubWeapon], base + "adventure_ui/s/slotWepSub.png");

	addResource(&UI_module_unknown, base + "m/module_unknown.png");
	addResource(&UI_image_cell_empty, base + "adventure_ui/storage/slot.png");


	/* Backgrounds Landing */

	addResource(&UI_background[0], base + "landing_ui/bg/1.png");

	/* Landing Sprites */

	addResource(&UI_PointsMap, base + "landing_ui/PointsMap.png");
	addResource(&UI_Point, base + "landing_ui/Point.png");
	addResource(&UI_askWindow, base + "landing_ui/askWindow.png");
	addResource(&UI_currentLocationLanding, base + "landing_ui/PointCurrent.png");
	addResource(&UI_PointWas, base + "landing_ui/PointWas.png");

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
		initAllSamples();
		loadCompleted = true;
	}


	if (loadCompleted)
		g_mgr->setCurLevel(1);

}

void GameLoader::addResource(sf::Sprite ** sp, std::string filename)
{
	tex_name.push_back(filename);
	sprite_pointer.push_back(sp);
}
