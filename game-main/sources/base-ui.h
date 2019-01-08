#pragma once

#include <SFML\Graphics.hpp>

#include "custom-types.h"
//#include "game-enviroment.h"

#include <algorithm>

class BaseUIElem
{
public:
	//BaseUIElem();
	

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

	virtual void draw();
	bool inside(int x, int y);
	
private:
	int p_x = 0, p_y = 0; // ���������� �������� ������� ����
	int p_w = 0, p_h = 0; // ������, ������
	double p_r = 0;       // ������ (��� �������� ���� circle)

	bool p_visible = false;
	bool p_active = false;

	UIElementType uiClassType = base;
	BaseUIElemFormType type = square;
};

class UI_Image : public BaseUIElem
{
public:
	virtual void draw() override;
	void LoadFromFile(std::string FileName);
	virtual void setPosition(int x, int y) override;
	virtual void setSize(int width, int heigh) override;
	void setScale(double sx, double sy);


	sf::Sprite * sprite();
private:
	sf::Sprite * p_s;
};