#pragma once

#include "ship.h"
#include "ship-scheme.h"
#include "items.h"
#include "effects.h"

#include <vector>

class Ship;
class BaseItem;
class ShipScheme;

class ShipStorage
{
public:
	ShipStorage();
	std::vector<BaseItem*> items;
	int rows; // y
	int columns; // x
	int size;
	int freeSpace;
	void create(int size);
	void addItem(BaseItem * item);
	void addItem(BaseItem * item, int cellID, bool raiseErrorOnBlockedCell);
	void update();
	void draw();

	int sx = 900;
	int sy = 600;
	void setPosition(int x, int y);

	void removeItem(int id, bool callDelete = false);



private:
	UI_TableObject * p_obj;
};
class ShipManager
{
public:
	Ship * ship;
	ShipScheme * scheme;
	ShipStorage * storage;

	void clearStats();
	void updateStats();
	void applyEffect(LocalEffect * effect);
	void applyModuleStatEffect(LocalEffect * effect);

	void init(ShipScheme * scheme);
	void debug();
};
