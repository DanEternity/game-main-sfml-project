#include "ui-controller.h"

int UI_Controller::AddElement(BaseUIElem * ui_element)
{
	p_list.push_back(UIEventState_private());
	int idx = p_list.size() - 1;
	p_list[idx].p = ui_element;
	return idx;
}

bool UI_Controller::RegisterEvent(int id, UIEventType eventType, func_pointer_void_data_uiHandler eventHandler)
{
	if (id < 0 || id > p_list.size() - 1)
		return false;
	if (eventHandler == NULL)
		return false;

	switch (eventType)
	{
	case onPress:
	case onRelease:	
	case onHoverBegin:
	case onHoverEnd:
		p_list[id].flagReg[eventType] = true;
		p_list[id].funcPointer[eventType] = eventHandler;
		return true;
	default:
		return false;
	}
	return false;
}

bool UI_Controller::DeleteEvent(int id, UIEventType eventType)
{
	if (id < 0 || id > p_list.size() - 1)
		return false;
	switch (eventType)
	{
	case onPress:
	case onRelease:
	case onHoverBegin:
	case onHoverEnd:
		p_list[id].flagReg[eventType] = false;
		p_list[id].funcPointer[eventType] = NULL;
		return true;
	default:
		return false;
		break;
	}
	return false;
}

void UI_Controller::DispatchEvents()
{
	//int m_x, m_y;
	auto mp = sf::Mouse().getPosition();
	bool m_left = sf::Mouse().isButtonPressed(sf::Mouse().Left);
	bool m_right = sf::Mouse().isButtonPressed(sf::Mouse().Right);
	auto wnd_pos = g_wnd->getPosition();

	//Log("MOUSE -> " + std::to_string(mp.x) + " " + std::to_string(mp.y));

	mp -= wnd_pos;
	mp.x -= 7;
	mp.y -= 31;


	UIEventData buff;
	buff.mouse_x = mp.x;
	buff.mouse_y = mp.y;
	buff.mouse_bt_l = m_left;
	buff.mouse_bt_r = m_right;
	buff.mouse_change_l = (m_left != p_m_l);
	buff.mouse_change_r = (m_right != p_m_r);
	
	for (int i(0); i < p_list.size(); i++)
	{
		UIEventState_private* q = &p_list[i];
		buff.objectID = i;
		buff.ref = q->p;

		if (q->p->inside(mp.x, mp.y))
		{
			if (!q->p_inside)
			{
				q->p_inside = true;
				
				if (q->flagReg[onHoverBegin])
				{
					// call onHoverBegin
					Logs("Call onHoverBegin for object [");
					Logp(q->p);
					Logln("]");
					buff.eventType = onHoverBegin;
					q->funcPointer[onHoverBegin](&buff);
				}
			}
			if ((!p_m_l && m_left || !p_m_r && m_right)&& q->flagReg[onPress])
			{
				// call onPress
				Logs("Call onPress for object [");
				Logp(q->p);
				Logln("]");
				buff.eventType = onPress;
				q->funcPointer[onPress](&buff);
			}

			if ((p_m_l && !m_left || p_m_r && !m_right)&& q->flagReg[onRelease])
			{
				// call onRelease
				Logs("Call onRelease for object [");
				Logp(q->p);
				Logln("]");
				buff.eventType = onRelease;
				q->funcPointer[onRelease](&buff);
			}
		}
		else
			if (q->p_inside)
			{
				q->p_inside = false;

				if (q->flagReg[onHoverEnd])
				{
					// call onHoverEnd
					Logs("Call onHoverEnd for object [");
					Logp(q->p);
					Logln("]");
					buff.eventType = onHoverEnd;
					q->funcPointer[onHoverEnd](&buff);
				}
			}
	}
	p_m_l = m_left;
	p_m_r = m_right;
}

void UI_Controller::Update()
{

	DispatchEvents();

}

sf::Vector2i UI_Controller::getMouseXY()
{
	auto mp = sf::Mouse().getPosition();
	auto wnd_pos = g_wnd->getPosition();

	mp -= wnd_pos;
	mp.x -= 7;
	mp.y -= 31;
	return mp;
}

bool UI_Controller::mouseLeftButton()
{
	return sf::Mouse().isButtonPressed(sf::Mouse().Left);
	
}

bool UI_Controller::mouseRightButton()
{
	return sf::Mouse().isButtonPressed(sf::Mouse().Right);
}
