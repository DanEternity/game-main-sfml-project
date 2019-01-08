#include "ui-text.h"

UI_text::UI_text(sf::Font * fontPointer)
{
	textStream = new sfe::RichText(*fontPointer);
	font = fontPointer;
	*textStream << textColor;
}

void UI_text::setPosition(int x, int y)
{
	BaseUIElem::setPosition(x, y);
	if (textStream == NULL)
	{
		return;
	}
	textStream->setPosition(x, y);
}

void UI_text::draw()
{
	g_wnd->draw(*textStream);
	if (!staticText)
		textStream->clear();
}

void UI_text::setCharacterSize(int size)
{
	if (textStream == NULL)
	{
		return;
	}
	textStream->setCharacterSize(size);
}

void UI_text::setColor(sf::Color color)
{
	textColor = color;
	*textStream << color;
}

void UI_text::outTextXY(int x, int y, std::string text)
{
	textStream->setPosition(x, y);
	*textStream << text;
}
