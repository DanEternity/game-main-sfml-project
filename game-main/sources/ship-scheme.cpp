#include "ship-scheme.h"

void ShipScheme::create(int id)
{
	switch (id)
	{
	case 0: // test
		schemeDebug();
		break;
	default:
		break;
	}
}

bool ShipScheme::checkSlotComp(ModuleItem * module, int id)
{
	if (module == NULL)
		return false;
	else
		return (module->slot == slots[id].s);
}

void ShipScheme::setModule(ModuleItem * module, int id)
{
	slots[id].m = module;
}

void ShipScheme::schemeDebug()
{
	slots.assign(8, QShipSlotCell());
	slots[0].s = slot_MainWeapon;
	slots[1].s = slot_MainWeapon;
	slots[2].s = slot_Core;
	slots[3].s = slot_System;
	slots[4].s = slot_HyperDrive;
	slots[5].s = slot_Engine;
	slots[6].s = slot_Universal;
	slots[7].s = slot_Universal;

	powerProduced = 0;
	powerUsed = 0;
	powerFree = 0;

	ActionPoints = 5; 
	Evasion = -40;
	Mobility = 15; 
	Stealth = -25; 
	StealthTier = 0; 
	SensorPower = 5; 
	SensorTier = 0; 
	HyperDriveSpeed = 0;  
	HyperDriveTier = 0; 
	HyperDriveFuelCost = 0;
	Hull = 1000; 
	HullResist[0] = 40; 
	HullResist[1] = 15;
	HullReg = 0;
	Shield = 0;
	ShieldResist[0] = 0; 
	ShieldResist[1] = 0;
	ShieldReg = 0;

	MissileDefense = 0; 
	MissileDefenseTier = 0; 
	HullStructureStability = 0; 
	ShieldStructureStability = 0;
}
