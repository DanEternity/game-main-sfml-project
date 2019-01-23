#pragma once

#include "items.h"

//class BaseItem;


class ModuleItem : public BaseItem
{
public:
	ModuleType type;
	ModuleSlot slot;
	

	float powerUsage;
};

class WeaponModuleItem : public ModuleItem
{
public:
	WeaponModuleItem();
	float ActivationCost;
	ModuleWepSubClass subType = class_WepNull;
	float baseDamage;
	float baseAccuracy;
	float damageLosePerCell;
	float damageMaxCells;
	float accuracyLosePerCell;
	float accuracyMaxCells;
	DamageType damageType;
	float armorPierce[2];
	float critChanceHull;
	float critDamageHull;
	float critChanceShield;
	float critDamageShield;

	// effects
	std::vector<LocalEffect> effects;
};

class SystemModuleItem : public ModuleItem
{
public:
	SystemModuleItem();
	ModuleSysSubClass subType = class_Null;
	// effects
	// different from WeaponModuleItem
	std::vector<LocalEffect> effects;
};

class SpecialModuleItem : public ModuleItem
{
public:
	// required special event function
	// and other field
	// virtual ExecResult call();

};

