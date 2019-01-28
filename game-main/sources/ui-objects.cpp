#include "ui-objects.h"

std::vector<UI_ScrollerObject *> UI_ScrollerEventRegTable;

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

UI_MultiObject::UI_MultiObject()
{
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
		if (e->mouse_change_l)
		{
			p_btn_pressed = true;
			p_old_btn_y = e->mouse_y - button->getPosition().second;
			button->SetSprite(scroller_btn_v1[2]);
		}
		break;
	case onRelease:
		if (e->mouse_change_l)
		{
			p_btn_pressed = false;
			button->SetSprite(scroller_btn_v1[0]);
		}
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
		buttonHeigh = (float(y) - area->getPosition().second + 3) / (p_area_size_y - p_bt_size_y - 3);
	}
}

float UI_ScrollerObject::getValue()
{
	return buttonHeigh;
}

void UI_ScrollerObject::setupController()
{
	int t = scroller_ctrl->AddElement(button);
	scroller_ctrl->RegisterEvent(t, onHoverBegin, &UI_ScrollerPrivateEventHandler);
	scroller_ctrl->RegisterEvent(t, onHoverEnd, &UI_ScrollerPrivateEventHandler);
	scroller_ctrl->RegisterEvent(t, onPress, &UI_ScrollerPrivateEventHandler);
	scroller_ctrl->RegisterEvent(t, onRelease, &UI_ScrollerPrivateEventHandler);
	
	button->localID = UI_ScrollerPrivateEventRegister(this);
}

int UI_ScrollerPrivateEventRegister(UI_ScrollerObject * target)
{
	UI_ScrollerEventRegTable.push_back(target);
	return UI_ScrollerEventRegTable.size() - 1;
}

void UI_ScrollerPrivateEventHandler(UIEventData * data)
{
	UI_ScrollerEventRegTable[data->ref->localID]->HandleEvent(data);
}

UI_TextLineObject::UI_TextLineObject()
{
}

void UI_TextLineObject::draw()
{
	p_canvas->draw(*textStream);
	if (!staticText)
		textStream->clear();

//	p_canvas->draw(*p_sprite);
}

void UI_TextLineObject::setPosition(int x, int y)
{
	BaseUIElem::setPosition(x, y);
	//p_sprite->setPosition(x, y);
	textStream->setPosition(x, y);
}

void UI_TextLineObject::setSize(int width, int heigh)
{
	BaseUIElem::setSize(width, heigh);
}

void UI_TextLineObject::setTexture(sf::RenderTexture * texture)
{
	p_canvas = texture;
}

void UI_TextLineObject::setCanvas(sf::RenderTexture * canvas)
{
	p_canvas = canvas;
}

UI_TextObject::UI_TextObject()
{
}

void UI_TextObject::draw()
{
	if (rebuildImage)
	{
		buildTexture();
		const sf::Texture& tex = p_canvas->getTexture();
		p_sprite->setTexture(tex);
		p_sprite->setTextureRect(sf::IntRect(0, p_h, p_w, -p_h));
	}

	g_wnd->draw(*p_sprite);
	p_Scroller->draw();
}

void UI_TextObject::setPosition(int x, int y)
{
	BaseUIElem::setPosition(x, y);
	p_sprite->setPosition(x, y);
	p_Scroller->setPosition(x + p_w, y + 4);
}

void UI_TextObject::setSize(int width, int heigh)
{
	BaseUIElem::setSize(width, heigh);
}

void UI_TextObject::init(sf::Font * font, int x, int y)
{
	p_Scroller = new UI_ScrollerObject();
	p_text = new UI_TextLineObject();
	//p_canvas = new sf::RenderTexture();

	p_text->font = font; 
	p_text->textStream->setFont(*font);
	p_text->setColor(sf::Color::White);
	p_Scroller->Create();

	p_canvas = new sf::RenderTexture();
	if (!p_canvas->create(x, y))
	{
		// error
	}

	p_w = x;
	p_h = y;

	p_sprite = new sf::Sprite();
	
	p_text->setCanvas(p_canvas);

	p_Scroller->setPosition(x, 0 + 4);

}

void UI_TextObject::buildTexture()
{
	baseY = -1 * p_Scroller->getValue() * std::max(0, CalcHeight() - p_h + lineSpacing + topIndent + 4);
	p_canvas->clear();

	int q = topIndent;

	for (int i(0); i < lines.size(); i++)
	{
		p_text->textStream->setPosition(leftIndent, q + baseY);
		//*(p_text->textStream) << lines[i];
		*p_text->textStream << sf::Color::White << sf::Text::Style::Regular;

		RichStringParse(p_text->textStream, lines[i], values);
		p_text->draw();
		p_text->textStream->clear();
		q += lineSpacing;
	}

}

void UI_TextObject::update()
{
	p_Scroller->Update();
}

int UI_TextObject::CalcHeight()
{
	if (lines.size() == 0)
		return 0;
	return topIndent + (lines.size() - 1) * lineSpacing;
}
