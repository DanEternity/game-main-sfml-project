#pragma once

#ifndef UI_OBJECTS
#define UI_OBJECTS



#include "ui-controller.h"
#include "base-ui.h"
#include "ui-text.h"
#include "game-enviroment.h"

class UI_Controller;

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

class UI_ScrollerObject : public BaseUIElem
{
public:
	virtual void draw();
	virtual void setPosition(int x, int y);
	virtual void setSize(int width, int heigh);

	UI_ScrollerObject();
	void Create();
	void Create(int bx, int by, int ax = 16, int ay = 400);

	void HandleEvent(UIEventData * e);
	void Update();
	float getValue(); 

	UI_ObjectImage * button;
	UI_ObjectImage * area;

	bool autoSizeButton = false;
	

private:
	int p_bt_size_x;
	int p_bt_size_y;

	int p_area_size_x;
	int p_area_size_y;

	UI_Controller * scroller_ctrl;
	float buttonHeigh = 0.f;

	int p_old_btn_y;
	bool p_btn_pressed = false;
	bool p_btn_hover = false;
	void setupController();
	
};

static std::vector<UI_ScrollerObject *> UI_ScrollerEventRegTable;
void UI_ScrollerPrivateEventRegister(UI_ScrollerObject * target);
void UI_ScrollerPrivateEventHandler(UIEventData * data);

#endif // !UI_OBJECTS