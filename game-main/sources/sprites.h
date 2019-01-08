#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

extern sf::Sprite * TestObject1;

// Template -> extern sf::Sprite * НАЗВАНИЕ_ОБЪЕКТА;
// Тоже самое НО БЕЗ "extern" следует добавить в sprites.cpp

// List of sf::Sprite

extern sf::Sprite * menu_btsNormal[5]; // normal
extern sf::Sprite * menu_btsHover[5]; // hover
extern sf::Sprite * menu_btsOnClick[5]; // onclick