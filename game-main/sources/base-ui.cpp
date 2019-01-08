#include "base-ui.h"
#include "game-enviroment.h"

void BaseUIElem::setPosition(int x, int y)
{
	p_x = x;
	p_y = y;
}

void BaseUIElem::setSize(int width, int heigh)
{
	type = square;
	p_w = width;
	p_h = heigh;
}

void BaseUIElem::setSize(double radius)
{
	type = circle;
	p_r = radius;
}

void BaseUIElem::setFormType(BaseUIElemFormType form)
{
	type = form;
}

void BaseUIElem::setVisibility(bool mode)
{
	p_visible = mode;
}

void BaseUIElem::setActive(bool mode)
{
	p_active = mode;
}

BaseUIElemFormType BaseUIElem::getFormType()
{
	return type;
}

std::pair<int, int> BaseUIElem::getSize()
{
	return { p_w, p_h };
}

double BaseUIElem::getRadius()
{
	return p_r;
}

std::pair<int, int> BaseUIElem::getPosition()
{
	return { p_x, p_y };
}

bool BaseUIElem::visible()
{
	return p_visible;
}

bool BaseUIElem::active()
{
	return p_active;
}

void BaseUIElem::draw()
{
}

bool BaseUIElem::inside(int x, int y)
{
	if (type == square)
		return (x > p_x && y > p_y && x < p_x + p_w && y < p_y + p_h);
	else
		return (p_r * p_r > (p_w - x) * (p_w - x) + (p_h - y) * (p_h - y));
}

void UI_Image::draw()
{
	if (visible())
		g_wnd->draw(*p_s);
}

void UI_Image::LoadFromFile(std::string FileName)
{
	// Load a sprite to display

	sf::Texture * tex = new sf::Texture();
	if (!tex->loadFromFile(FileName))
		Log("ERROR: texture loading failure!");

	textures.push_back(tex);

	p_s = new sf::Sprite(*tex);

	setVisibility(true);
}

void UI_Image::LoadFromSprite(sf::Sprite * Sprite)
{
	if (Sprite == NULL)
	{
		Log("Error. You are trying to bind Sprite == NULL. Operation canceled.");
		return;
	}
	p_s = Sprite;

	setVisibility(true);
}

void UI_Image::setPosition(int x, int y)
{
	BaseUIElem::setPosition(x, y);
	p_s->setPosition(x, y);
}

void UI_Image::setSize(int width, int heigh)
{
	BaseUIElem::setSize(width, heigh);
	double sx, sy;
	sx = double(width) / p_s->getTexture()->getSize().x;
	sy = double(heigh) / p_s->getTexture()->getSize().y;
	p_s->setScale(sx, sy);
}

void UI_Image::setScale(double sx, double sy)
{
	p_s->setScale(sx, sy);
}

sf::Sprite * UI_Image::sprite()
{
	return p_s;
}

UI_collection::~UI_collection()
{
	for (int i(0); i < p_list.size(); i++)
	{
		p_list[i]->~BaseUIElem();
	}
}

void UI_collection::draw()
{
	for (int i(0); i < p_list.size(); i++)
		p_list[i]->draw();
}

void UI_collection::setPosition(int x, int y)
{
	BaseUIElem::setPosition(x, y);
	int dx = x - p_x;
	int dy = y - p_y;

	for (int i(0); i < p_list.size(); i++)
	{
		auto pos = p_list[i]->getPosition();
		p_list[i]->setPosition(pos.first + dx, pos.second + dy);
	}
}

void UI_collection::setSize(int width, int heigh)
{
	BaseUIElem::setSize(width, heigh);
	//double sx = double(width) / p_s->getTexture()->getSize().x;
	//double sy = double(heigh) / p_s->getTexture()->getSize().y;
	//p_s->setScale(sx, sy);
}

void UI_collection::addElem(BaseUIElem * elem)
{
	if (elem == NULL)
	{
		Log("Error. You are trying to add elem == NULL. Operation canceled.");
		return;
	}
	p_list.push_back(elem);
}
