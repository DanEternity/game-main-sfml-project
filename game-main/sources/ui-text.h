#pragma once

#ifndef UI_TEXT
#define UI_TEXT

#include <SFML\Graphics.hpp>

#include <string>

#include "lib\RichText.hpp"
#include "base-ui.h"
#include "game-enviroment.h"
#include "wnd-utils.h"





class UI_text : public BaseUIElem
{
public:
	UI_text();
	UI_text(sf::Font * fontPointer);
	sf::Font * font;
	sfe::RichText * textStream;
	bool staticText = false;

	virtual void setPosition(int x, int y) override;
	virtual void draw() override;

	void setCharacterSize(int size);
	void setColor(sf::Color color);
	void outTextXY(int x, int y, std::string text);

protected:
	sf::Color textColor = sf::Color::Black;
	
};

#endif // !UI_TEXT