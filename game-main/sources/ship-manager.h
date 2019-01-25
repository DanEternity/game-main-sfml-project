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
	std::vector<BaseItem*> items;
	int rows; // y
	int columns; // x
	int size;
	int freeSpace;
	void create(int size);
	void addItem(BaseItem * item);
	void addItem(BaseItem * item, int cellID, bool raiseErrorOnBlockedCell);
	void removeItem(int id, bool callDelete = false);
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
