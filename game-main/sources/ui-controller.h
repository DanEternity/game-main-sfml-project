#pragma once

#include <SFML\Window\Mouse.hpp>

#include <vector>
#include <string>
#include <iostream>

#include "base-ui.h"
#include "custom-types.h"
#include "debug.h"
#include "game-enviroment.h"

class UI_Controller
{
public:
	int AddElement(BaseUIElem * ui_element);
	bool RegisterEvent(int id, UIEventType eventType, func_pointer_void_data_uiHandler eventHandler);
	bool DeleteEvent(int id, UIEventType eventType);
	void DispatchEvents();
	void Update();
	sf::Vector2i getMouseXY();
	bool mouseLeftButton();
	bool mouseRightButton();
private:
	//std::vector<BaseUIElem *> p_list;
	std::vector<UIEventState_private> p_list;
	bool p_m_l = false;
	bool p_m_r = false;
};