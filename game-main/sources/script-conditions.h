#pragma once

#include "game-data-global.h"

enum ConditionType
{
	condition_null, // not for use
	condition_AND, // extended v0 = conditionListContext
	condition_OR, // extended v0 = conditionListContext
	condition_hull_percent, // f1 = hull%
	condition_shield_percent, // f1 = shield%
	condition_hull, // f1
	condition_shield, // f1
	condition_fuel, // f1
	condition_fuel_percent, // f1
	condition_power_supply, //f1
	condition_power_use, //f1
	condition_action_points, //f1
	condition_evasion, //f1
	condition_mobility, //f1
	condition_stealth, //f1
	condition_stealth_tier, //f1
	condition_sensor_power, //f1
	condition_sensor_tier, //f1
	condition_hyper_drive_speed, //f1
	condition_hyper_drive_tier, //f1
	condition_hyper_drive_fuel_efficiency, //f1
	condition_hull_reg, //f1
	condition_shield_reg, //f1
	condition_missile_def, //f1
	condition_missile_def_tier, //f1
	condition_hull_structure_stability, //f1
	condition_shield_structure_stability, //f1
};

enum ConditionParam
{
	condition_param_more,
	condition_param_less,
	condition_param_equal
	//condition_param_more_or_equal,
};

class ConditionRef;

struct conditionListContext
{
	std::vector<ConditionRef> l;
};

class ConditionRef
{
public:
	ConditionRef();

	ConditionType type;
	ConditionParam param;
	int i1;
	int i2;
	int f1;
	int f2;
	void * v0 = nullptr;

	bool result = false;
	void check();

	/* utility */
	bool checkWithParamf1(float x);

	/* sub functions */
	void checkAND();
	void checkOR();
	void checkHull();
	void checkShield();
	void checkFuel();
	void checkHullPercent();
	void checkShieldPercent();
	void checkFuelPercent();
	void checkPowerSupply();
	void checkPowerUse();
	void checkActionPoints();
	void checkEvasion();
	void checkMobility();
	void checkStealth();
	void checkStealthTier();
	void checkSensorPower();
	void checkSensorTier();
	void checkHyperDriveSpeed();
	void checkHyperDriveTier();
	void checkHyperDriveFuelEfficiency();
	void checkHullReg();
	void checkShieldReg();
	void checkMissileDef();
	void checkMissileDefTier();
	void checkHullStructureStability();
	void checkShieldStructureStability();
};