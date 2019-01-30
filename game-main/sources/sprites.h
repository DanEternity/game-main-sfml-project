#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

extern sf::Sprite * TestObject1;

// Template -> extern sf::Sprite * ��������_�������;
// ���� ����� �� ��� "extern" ������� �������� � sprites.cpp

// List of sf::Sprite

extern sf::Sprite * menu_btsNormal[15]; // normal
extern sf::Sprite * menu_btsHover[15]; // hover
extern sf::Sprite * menu_btsOnClick[15]; // onclick

extern sf::Sprite * scroller_base_400; 
extern sf::Sprite * scroller_btn_v1[3];

extern sf::Sprite * itemInfoBoxBackground;

/* adventure ui */
extern sf::Sprite * UI_leftTop;
extern sf::Sprite * UI_leftDown;
extern sf::Sprite * UI_rightTop;
extern sf::Sprite * UI_rightDown;

extern sf::Sprite * UI_adv_btns[40][3];

extern sf::Sprite * UI_adv_window_bg;

/* Backgrounds Landing */

extern sf::Sprite * UI_background[1];