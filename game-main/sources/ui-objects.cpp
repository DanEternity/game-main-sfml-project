#include "ui-objects.h"

UI_ObjectImage::UI_ObjectImage()
{
}

UI_ObjectImage::UI_ObjectImage(int ID)
{
	globalID = GetUID();
	localID = ID;
}

void UI_ObjectImage::draw()
{
	UI_Image::draw();
}

void UI_ObjectImage::setPosition(int x, int y)
{
	UI_Image::setPosition(x, y);
}

void UI_ObjectImage::setSize(int width, int heigh)
{
	UI_Image::setSize(width, heigh);
}

void UI_TextureImage::draw()
{
	p_canvas->draw( *p_sprite );
}

void UI_TextureImage::setPosition(int x, int y)
{
	BaseUIElem::setPosition(x, y);
	p_sprite->setPosition(x, y);
}

void UI_TextureImage::setSize(int width, int heigh)
{
	BaseUIElem::setSize(width, heigh);
	auto sz = p_sprite->getTexture()->getSize();
	p_sprite->setScale(width/sz.x, heigh/sz.y);
}

void UI_TextureImage::setScale(double sx, double sy)
{
	p_sprite->setScale(sx, sy);
}

void UI_TextureImage::setTexture(sf::RenderTexture * texture)
{
	p_canvas = texture;
}

void UI_TextureImage::getSprite(sf::Sprite * sprite)
{
	sprite = p_sprite;
}

void UI_MultiObject::draw()
{
	p_canvas->clear();

	for (int i(0); i < p_list.size(); i++)
	{
		p_list[i]->draw();
	}

	p_canvas->display();

	if (instantDraw)
	{
		const sf::Texture& tex = p_canvas->getTexture();
		p_sprite->setTexture(tex);
	}

}

void UI_MultiObject::setPosition(int x, int y)
{
	BaseUIElem::setPosition(x, y);
	p_sprite->setPosition(x, y);
}

void UI_MultiObject::setSize(int width, int heigh)
{
	p_w = width;
	p_h = heigh;

	p_canvas->~RenderTexture();
	p_canvas = new sf::RenderTexture();

	if (!p_canvas->create(width, heigh))
	{
		// error
	}



}

sf::RenderTexture * UI_MultiObject::getCanvas()
{
	return p_canvas;
}

UI_MultiObject::UI_MultiObject(int x, int y)
{
	p_canvas = new sf::RenderTexture();
	if (!p_canvas->create(x, y))
	{
		// error
	}
	p_w = x;
	p_h = y;

	p_sprite = new sf::Sprite();

}
