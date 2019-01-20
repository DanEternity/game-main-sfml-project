#pragma once

#include "ship.h"
#include "ship-scheme.h"
#include "items.h"

class ShipStorage
{
public:
	std::vector<BaseItem*> items;

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
