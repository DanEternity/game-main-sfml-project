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

void UI_ScrollerObject::draw()
{
	area->draw();
	button->draw();
}

void UI_ScrollerObject::setPosition(int x, int y)
{
	area->setPosition(x, y);
	int bt_y = 0;
	bt_y = y + buttonHeigh * ((p_area_size_y - 4) - p_bt_size_y) + 3;
	button->setPosition(x + 3, bt_y);
}

void UI_ScrollerObject::setSize(int width, int heigh)
{
	// i dont know how to change texture size;
}

UI_ScrollerObject::UI_ScrollerObject()
{
	Create();
}

void UI_ScrollerObject::Create()
{
	area = new UI_ObjectImage();
	button = new UI_ObjectImage();

	p_bt_size_x = 10;
	p_bt_size_y = 50;

	p_area_size_x = 16;
	p_area_size_y = 400;

	area->CopyTexture(scroller_base_400);
	button->CopyTexture(scroller_btn_v1[0]);
	button->setSize(24, 50);

	button->setPosition(p_x + 3, p_y + 3);

	scroller_ctrl = new UI_Controller();

	setupController();
}

void UI_ScrollerObject::Create(int bx, int by, int ax, int ay)
{
	area = new UI_ObjectImage();
	button = new UI_ObjectImage();

	p_bt_size_x = 10;
	p_bt_size_y = 50;

	p_area_size_x = 16;
	p_area_size_y = 400;

	if (ay == 400)
	{
		area->CopyTexture(scroller_base_400);
	}
	
	button->CopyTexture(scroller_btn_v1[0]);

	scroller_ctrl = new UI_Controller();

	setupController();
}

void UI_ScrollerObject::HandleEvent(UIEventData * e)
{
	//
	switch (e->eventType)
	{
	case onHoverBegin:
		p_btn_hover = true;
		if (!p_btn_pressed)
			button->SetSprite(scroller_btn_v1[1]);
		break;
	case onHoverEnd:
		p_btn_hover = false;
		if (!p_btn_pressed)
			button->SetSprite(scroller_btn_v1[0]);
		break;
	case onPress:
		p_btn_pressed = true;
		p_old_btn_y = e->mouse_y - button->getPosition().second;
		button->SetSprite(scroller_btn_v1[2]);
		break;
	case onRelease:
		p_btn_pressed = false;
		button->SetSprite(scroller_btn_v1[0]);
		break;
	default:
		break;
	}
}

void UI_ScrollerObject::Update()
{
	scroller_ctrl->Update();

	if (p_btn_pressed)
	{
		if (!scroller_ctrl->mouseLeftButton())
		{
			p_btn_pressed = false;
			button->SetSprite(scroller_btn_v1[0]);
			return;
		}
		auto m = scroller_ctrl->getMouseXY();
		int y = std::max(area->getPosition().second + 3, std::min(m.y - p_old_btn_y, p_area_size_y - p_bt_size_y - 3 + area->getPosition().second));
		button->setPosition(button->getPosition().first, y);
	}
}

void UI_ScrollerObject::setupController()
{
	scroller_ctrl->AddElement(button);
	scroller_ctrl->RegisterEvent(0, onHoverBegin, &UI_ScrollerPrivateEventHandler);
	scroller_ctrl->RegisterEvent(0, onHoverEnd, &UI_ScrollerPrivateEventHandler);
	scroller_ctrl->RegisterEvent(0, onPress, &UI_ScrollerPrivateEventHandler);
	scroller_ctrl->RegisterEvent(0, onRelease, &UI_ScrollerPrivateEventHandler);
	UI_ScrollerPrivateEventRegister(this);
}

void UI_ScrollerPrivateEventRegister(UI_ScrollerObject * target)
{
	UI_ScrollerEventRegTable.push_back(target);
}

void UI_ScrollerPrivateEventHandler(UIEventData * data)
{
	UI_ScrollerEventRegTable[data->objectID]->HandleEvent(data);
}
