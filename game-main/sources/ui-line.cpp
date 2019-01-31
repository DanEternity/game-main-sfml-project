#include "ui-line.h"

void Line::drawLine(int x1, int y1, int x2, int y2, sf::Color color)
{
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(x1, y1)),
		sf::Vertex(sf::Vector2f(x2, y2))
	};

	line[0].color = color;
	line[1].color = color;

	g_wnd->draw(line, 2, sf::Lines);
}