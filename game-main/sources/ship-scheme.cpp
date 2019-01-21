#include "ship-scheme.h"

void ShipScheme::create(int id)
{
	Logs("Loading ship scheme ");
	Log(std::to_string(id));
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
	if (!checkSlotComp(module, id))
	{
		Log("Error slot type mismatch!");
		return;
	}
	Logs("Module installed in slot ");
	Log(std::to_string(id));
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

	SystemModuleItem * p = new SystemModuleItem();
	WeaponModuleItem * w;

	p->nameLine = "Sample";
	p->image = NULL;
	p->descLines.push_back("Sample description");
	p->lvl = 1;
	p->rare = 1;
	p->powerUsage = 1;
	LocalEffect eff = LocalEffect();
	eff.type = ModuleStat; // do not change
	eff.subType = StatPowerSupply;
	eff.f1 = 10; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	eff.subType = StatHull;
	eff.f1 = 125; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	p->slot = slot_Universal;
	p->type = moduleTypeSys;

	delete(p);

	p = new SystemModuleItem(); // и так далее // объ€вл€ть p второй раз не нужно
								// только создать новый объект через new
	p->nameLine = "Click";
	p->image = NULL;
	p->descLines.push_back("Base sensor");
	p->lvl = 1;
	p->rare = 1;
	p->powerUsage = 1;
	eff.type = ModuleStat; // do not change
	eff.subType = StatSensorPower;
	eff.f1 = 50; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	eff.subType = StatSensorTier;
	eff.f1 = 1; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	p->slot = slot_Universal;
	p->type = moduleTypeSys;
	setModule(p, 7);

	p = new SystemModuleItem(); // и так далее // объ€вл€ть p второй раз не нужно
								// только создать новый объект через new
	p->nameLine = "Prototype";
	p->image = NULL;
	p->descLines.push_back("Shield generator prototype");
	p->lvl = 1;
	p->rare = 1;
	p->powerUsage = 2;
	eff.type = ModuleStat; // do not change
	eff.subType = StatShield;
	eff.f1 = 100; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	eff.subType = StatShieldResist;
	eff.i1 = 0;
	eff.f1 = 1; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	eff.subType = StatShieldResist;
	eff.i1 = 1;
	eff.f1 = 1.5f; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	p->slot = slot_Universal;
	p->type = moduleTypeSys;
	setModule(p, 6);

	p = new SystemModuleItem(); // и так далее // объ€вл€ть p второй раз не нужно
								// только создать новый объект через new
	p->nameLine = "Atom-300";
	p->image = NULL;
	p->descLines.push_back("First gen nuclear reactor");
	p->lvl = 1;
	p->rare = 1;
	p->powerUsage = 0;
	eff.type = ModuleStat; // do not change
	eff.subType = StatPowerSupply;
	eff.f1 = 30; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	eff.subType = StatActionPoints;
	eff.f1 = 10; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	p->slot = slot_Core;
	p->type = moduleTypeSys;
	setModule(p, 2);

	p = new SystemModuleItem(); // и так далее // объ€вл€ть p второй раз не нужно
								// только создать новый объект через new
	p->nameLine = "Jump-prototype";
	p->image = NULL;
	p->descLines.push_back("Hyper drive core prototype");
	p->lvl = 1;
	p->rare = 1;
	p->powerUsage = 25;
	eff.type = ModuleStat; // do not change
	eff.subType = StatHyperDriveSpeed;
	eff.f1 = 10; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	eff.subType = StatHyperDriveTier;
	eff.f1 = 1; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	eff.subType = StatHyperDriveFuelCost;
	eff.f1 = 100; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	p->slot = slot_HyperDrive;
	p->type = moduleTypeSys;
	setModule(p, 4);

	p = new SystemModuleItem(); // и так далее // объ€вл€ть p второй раз не нужно
								// только создать новый объект через new
	p->nameLine = "Alice";
	p->image = NULL;
	p->descLines.push_back("Space ship's system prototype");
	p->lvl = 1;
	p->rare = 1;
	p->powerUsage = 2;
	eff.type = ModuleStat; // do not change
	eff.subType = StatHyperDriveSpeed;
	eff.f1 = 0; // +X
	eff.f2 = 2; // +X%
	p->effects.push_back(eff);
	eff.subType = StatPowerSupply;
	eff.f1 = 0; // +X
	eff.f2 = 10; // +X%
	p->effects.push_back(eff);
	eff.subType = StatHyperDriveFuelCost;
	eff.f1 = 0; // +X
	eff.f2 = 10; // +X%
	p->effects.push_back(eff);
	eff.subType = StatSensorPower;
	eff.f1 = 0; // +X
	eff.f2 = 10; // +X%
	p->effects.push_back(eff);
	eff.subType = StatShield;
	eff.f1 = 0; // +X
	eff.f2 = 10; // +X%
	p->effects.push_back(eff);
	eff.subType = StatMissileDefense;
	eff.f1 = 20; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	eff.subType = StatMissileDefenseTier;
	eff.f1 = 1; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	p->slot = slot_System;
	p->type = moduleTypeSys;
	setModule(p, 3);

	p = new SystemModuleItem(); // и так далее // объ€вл€ть p второй раз не нужно
								// только создать новый объект через new
	p->nameLine = "Tigr";
	p->image = NULL;
	p->descLines.push_back("First mass production human space engine");
	p->lvl = 1;
	p->rare = 1;
	p->powerUsage = 5;
	eff.type = ModuleStat; // do not change
	eff.subType = StatEvasion;
	eff.f1 = 10; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	eff.subType = StatMobility;
	eff.f1 = 2; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	p->slot = slot_Engine;
	p->type = moduleTypeSys;
	setModule(p, 5);

	w = new WeaponModuleItem(); // и так далее // объ€вл€ть p второй раз не нужно
								// только создать новый объект через new
	w->nameLine = "Gauss-weapon";
	w->image = NULL;
	w->descLines.push_back("First mass production human kinetic space weapon");
	w->lvl = 1;
	w->rare = 1;
	w->powerUsage = 3;
	w->ActivationCost = 1;
	w->baseDamage = 10;
	w->baseAccuracy = 70;
	w->damageLosePerCell = 1;
	w->damageMaxCells = 5;
	w->accuracyLosePerCell = 20;
	w->accuracyMaxCells = 3;
	w->damageType = physical;
	w->armorPierce[0] = 10;
	w->armorPierce[1] = 5;
	w->critChanceHull = 5;
	w->critDamageHull = 20;
	w->critChanceShield = 0;
	w->critDamageShield = 20;
	w->slot = slot_MainWeapon;
	w->type = moduleTypeWeapon;
	setModule(w, 0);

	w = new WeaponModuleItem(); // и так далее // объ€вл€ть p второй раз не нужно
								// только создать новый объект через new
	w->nameLine = "Plasma-weapon prototype";
	w->image = NULL;
	w->descLines.push_back("First prototype of human plasma space weapon");
	w->lvl = 1;
	w->rare = 1;
	w->powerUsage = 3;
	w->ActivationCost = 2;
	w->baseDamage = 30;
	w->baseAccuracy = 100;
	w->damageLosePerCell = 10;
	w->damageMaxCells = 3;
	w->accuracyLosePerCell = 10;
	w->accuracyMaxCells = 3;
	w->damageType = energy;
	w->armorPierce[0] = 5;
	w->armorPierce[1] = 15;
	w->critChanceHull = 1;
	w->critDamageHull = 60;
	w->critChanceShield = 20;
	w->critDamageShield = 80;
	w->slot = slot_MainWeapon;
	w->type = moduleTypeWeapon;
	setModule(w, 1);
}
