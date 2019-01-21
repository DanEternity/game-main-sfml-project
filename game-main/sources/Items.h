#pragma once

#ifndef ITEMS
#define ITEMS

#include <string>
#include "custom-types.h"

#include "ui-objects.h"
#include "effects.h"

class BaseITem;
class UI_ObjectImage;

class BaseItem
{
public:
	BaseItem();

	std::string nameLine;
	std::vector<std::string> descLines; // текстовое описание предмета

	int lvl = 0;
	int rare = 0;

	sf::Vector2i pos = {0, 0};
	int ID = 0; // индекс предмета (используется для идентификации)
	__int64 hashKey = NULL; // hashKey to generate item

	UI_ObjectImage * image = 0;
	bool hasImage = false;
};

class ResourseItem : public BaseItem
{
public:
	// ресурс итем отличается только тем,
	// что его может быть больше чем 1
	int count = 0; 
	int maxCount = 1;
};


class EquipmentItem : public BaseItem
{
public:
	float reqStr;
	float reqAgi;
	float reqInt;
	float reqLvl;

	std::vector<LocalEffect> effect;
};

#endif // !Items