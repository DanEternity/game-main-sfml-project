#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

extern sf::Sprite * TestObject1;

// Template -> extern sf::Sprite * НАЗВАНИЕ_ОБЪЕКТА;
// Тоже самое НО БЕЗ "extern" следует добавить в sprites.cpp

// List of sf::Sprite

extern sf::Sprite * menu_btsNormal[15]; // normal
extern sf::Sprite * menu_btsHover[15]; // hover
extern sf::Sprite * menu_btsOnClick[15]; // onclick

extern sf::Sprite * scroller_base_400; 
extern sf::Sprite * scroller_btn_v1[3];

extern sf::Sprite * itemInfoBoxBackground[4];

/* adventure ui */
extern sf::Sprite * UI_leftTop;
extern sf::Sprite * UI_leftDown;
extern sf::Sprite * UI_rightTop;
extern sf::Sprite * UI_rightDown;

extern sf::Sprite * UI_adv_element[15];
extern sf::Sprite * UI_adv_btns[40][3];

extern sf::Sprite * UI_adv_window_bg;

extern sf::Sprite * UI_adv_marker_base;
extern sf::Sprite * UI_adv_marker_info;

extern sf::Sprite * UI_adv_module_slots[8];
extern sf::Sprite * UI_module_unknown;
extern sf::Sprite * UI_image_cell_empty;
/* ships */

extern sf::Sprite * ship_sprites[20];

/* Backgrounds Landing */
extern sf::Sprite * UI_background[1];

/* Landing Sprites */
extern sf::Sprite * UI_PointsMap;
extern sf::Sprite * UI_Point;
extern sf::Sprite * UI_lineElement;