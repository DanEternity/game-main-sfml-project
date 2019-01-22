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

extern sf::Sprite * itemInfoBoxBackground;