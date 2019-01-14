#pragma once

#include "base-ui.h"
#include "ui-text.h"
#include "game-enviroment.h"

class UI_ObjectImage : public UI_Image
{
public:

	UI_ObjectImage();
	UI_ObjectImage(int ID);

	virtual void draw() override;
	virtual void setPosition(int x, int y) override;
	virtual void setSize(int width, int heigh) override;
protected:

};

class UI_TextureImage : public BaseUIElem
{
public:
	virtual void draw();
	virtual void setPosition(int x, int y);
	virtual void setSize(int width, int heigh);

	void setScale(double sx, double sy);
	void setTexture(sf::RenderTexture * texture);
	void getSprite(sf::Sprite * sprite);
protected:
	sf::RenderTexture * p_canvas;
	sf::Sprite * p_sprite;
};

class UI_MultiObject : public BaseUIElem
{
public:
	virtual void draw();
	virtual void setPosition(int x, int y);
	virtual void setSize(int width, int heigh);
	sf::RenderTexture * getCanvas();

	// only operate with UI_TextureImage
	// and UI_textObject
	// do not use other object
	std::vector<BaseUIElem * > p_list;
	bool instantDraw = true;

	UI_MultiObject(int x, int y);
protected:
	sf::RenderTexture * p_canvas;
	sf::Sprite * p_sprite;
};