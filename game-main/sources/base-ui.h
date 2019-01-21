#pragma once

#include <SFML\Graphics.hpp>

#include "custom-types.h"
#include "wnd-utils.h"
#include "debug.h"

#include <algorithm>

class BaseUIElem
{
public:
	int globalID = 0;
	int localID = 0;

	//BaseUIElem();
	virtual void draw();
	virtual void setPosition(int x, int y);
	virtual void setSize(int width, int heigh);
	void setSize(double radius);
	void setFormType(BaseUIElemFormType form);
	void setVisibility(bool mode);
	void setActive(bool mode);

	BaseUIElemFormType getFormType();
	std::pair<int, int> getSize();
	double getRadius();
	std::pair<int, int> getPosition();
	bool visible();
	bool active();

	
	bool inside(int x, int y);
	
protected:
	int p_x = 0, p_y = 0; // координаты верхнего правого угла
	int p_w = 0, p_h = 0; // ширина, высота
	double p_r = 0;       // радиус (для объектов типа circle)

	bool p_visible = false;
	bool p_active = false;

	UIElementType uiClassType = base;
	BaseUIElemFormType type = square;
};

class UI_Image : public BaseUIElem
{
public:
	virtual void draw() override;
	void LoadFromFile(std::string FileName); // Creates sprite object from file
	void LoadFromSprite(sf::Sprite * Sprite); // Creates sprite object from texture from other sprite
	void SetSprite(sf::Sprite * Sprite); // Modifies sprite with texture from other sprite
	void CopyTexture(sf::Sprite * Sprite); // Modifies or creates sprite with texture from other sprite
	virtual void setPosition(int x, int y) override;
	virtual void setSize(int width, int heigh) override;
	void setScale(double sx, double sy);


	sf::Sprite * sprite();
protected:
	sf::Sprite * p_s;
};

class UI_collection : public BaseUIElem
{
public:
	~UI_collection();

	virtual void draw() override;
	//void LoadFromFile(std::string FileName);
	//void LoadFromSprite(sf::Sprite * Sprite);
	virtual void setPosition(int x, int y) override;
	virtual void setSize(int width, int heigh) override;
	//void setScale(double sx, double sy);

	void addElem(BaseUIElem * elem);
protected:
	std::vector<BaseUIElem *> p_list;
};