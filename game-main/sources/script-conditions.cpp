#include "script-conditions.h"

ConditionRef::ConditionRef()
{
}

void ConditionRef::check()
{
	switch (type)
	{
	case condition_null:
		result = true;
		break;
	case condition_AND:
		checkAND();
		break;
	case condition_OR:
		checkOR();
		break;
	case condition_hull_percent:
		checkHullPercent();
		break;
	case condition_shield_percent:
		checkShieldPercent();
		break;
	case condition_hull:
		checkHull();
		break;
	case condition_shield:
		checkShield();
		break;
	case condition_fuel:
		checkFuel();
		break;
	case condition_fuel_percent:
		checkFuelPercent();
		break;
	case condition_power_supply:
		checkPowerSupply();
		break;
	case condition_power_use:
		checkPowerUse();
		break;
	case condition_action_points:
		checkActionPoints();
		break;
	case condition_evasion:
		checkEvasion();
		break;
	case condition_mobility:
		checkMobility();
		break;
	case condition_stealth:
		checkStealth();
		break;
	case condition_stealth_tier:
		checkStealthTier();
		break;
	case condition_sensor_power:
		checkSensorPower();
		break;
	case condition_sensor_tier:
		checkSensorTier();
		break;
	case condition_hyper_drive_speed:
		checkHyperDriveSpeed();
		break;
	case condition_hyper_drive_tier:
		checkHyperDriveTier();
		break;
	case condition_hyper_drive_fuel_efficiency:
		checkHyperDriveFuelEfficiency();
		break;
	case condition_hull_reg:
		checkHullReg();
		break;
	case condition_shield_reg:
		checkShieldReg();
		break;
	case condition_missile_def:
		checkMissileDef();
		break;
	case condition_missile_def_tier:
		checkMissileDefTier();
		break;
	case condition_hull_structure_stability:
		checkHullStructureStability();
		break;
	case condition_hull_resistance:
		checkHullResistance();
		break;
	case condition_shield_resistance:
		checkShieldResistance();
		break;
	default:
		break;
	}
}

bool ConditionRef::checkWithParamf1(float x)
{
	switch (param)
	{
	case condition_param_more:
		return x > f1;
		break;
	case condition_param_less:
		return x < f1;
		break;
	case condition_param_equal:
		return x == f1;
		break;
	default:
		break;
	}
}

void ConditionRef::checkAND()
{
	if (v0 == NULL)
	{
		Log("Error in [condition_AND]. v0 was NULL");
		result = true;
		return;
	}

	conditionListContext * c = static_cast <conditionListContext *> (v0);
	
	int n = c->l.size();

	result = true;

	for (int i(0); i < n; i++)
	{
		c->l[i].check();
		if (!c->l[i].result)
		{
			result = false;
			break;
		}
	}
}

void ConditionRef::checkOR()
{
	if (v0 == NULL)
	{
		Log("Error in [condition_OR]. v0 was NULL");
		result = true;
		return;
	}

	conditionListContext * c = static_cast <conditionListContext *> (v0);

	int n = c->l.size();

	result = false;

	for (int i(0); i < n; i++)
	{
		c->l[i].check();
		if (!c->l[i].result)
		{
			result = true;
			break;
		}
	}
}

void ConditionRef::checkHull()
{
	float x = gd->mainShip->CurrentHull; //
	result = checkWithParamf1(x);
}

void ConditionRef::checkShield()
{
	float x = gd->mainShip->CurrentShield; //
	result = checkWithParamf1(x);
}

void ConditionRef::checkFuel()
{
	float x = gd->mainShip->CurrentFuel; //
	result = checkWithParamf1(x);
}

void ConditionRef::checkHullPercent()
{
	float x = (gd->mainShip->CurrentHull) / (gd->mainShip->Hull[3]); //
	result = checkWithParamf1(x);
}

void ConditionRef::checkShieldPercent()
{
	float x = (gd->mainShip->CurrentShield) / (gd->mainShip->Shield[3]); //
	result = checkWithParamf1(x);
}

void ConditionRef::checkFuelPercent()
{
	float x = (gd->mainShip->CurrentFuel) / (gd->mainShip->Fuel[3]); //
	result = checkWithParamf1(x);
}

void ConditionRef::checkPowerSupply()
{
	float x = gd->mainShip->PowerSupply[3]; //
	result = checkWithParamf1(x);
}

void ConditionRef::checkPowerUse()
{
	float x = gd->mainShip->PowerUse[3]; //
	result = checkWithParamf1(x);
}

void ConditionRef::checkActionPoints()
{
	float x = gd->mainShip->ActionPoints[3]; //
	result = checkWithParamf1(x);
}

void ConditionRef::checkEvasion()
{
	float x = gd->mainShip->Evasion[3]; //
	result = checkWithParamf1(x);
}

void ConditionRef::checkMobility()
{
	float x = gd->mainShip->Mobility[3]; //
	result = checkWithParamf1(x);
}

void ConditionRef::checkStealth()
{
	float x = gd->mainShip->Stealth[3]; //
	result = checkWithParamf1(x);
}

void ConditionRef::checkStealthTier()
{
	float x = gd->mainShip->StealthTier[3]; //
	result = checkWithParamf1(x);
}

void ConditionRef::checkSensorPower()
{
	float x = gd->mainShip->SensorPower[3]; //
	result = checkWithParamf1(x);
}

void ConditionRef::checkSensorTier()
{
	float x = gd->mainShip->SensorTier[3]; //
	result = checkWithParamf1(x);
}

void ConditionRef::checkHyperDriveSpeed()
{
	float x = gd->mainShip->HyperDriveSpeed[3]; //
	result = checkWithParamf1(x);
}

void ConditionRef::checkHyperDriveTier()
{
	float x = gd->mainShip->HyperDriveTier[3]; //
	result = checkWithParamf1(x);
}

void ConditionRef::checkHyperDriveFuelEfficiency()
{
	float x = gd->mainShip->HyperDriveFuelEfficiency[3]; //
	result = checkWithParamf1(x);
}

void ConditionRef::checkHullReg()
{
	float x = gd->mainShip->HullReg[3]; //
	result = checkWithParamf1(x);
}

void ConditionRef::checkShieldReg()
{
	float x = gd->mainShip->ShieldReg[3]; //
	result = checkWithParamf1(x);
}

void ConditionRef::checkMissileDef()
{
	float x = gd->mainShip->MissileDefense[3]; //
	result = checkWithParamf1(x);
}

void ConditionRef::checkMissileDefTier()
{
	float x = gd->mainShip->MissileDefenseTier[3]; //
	result = checkWithParamf1(x);
}

void ConditionRef::checkHullStructureStability()
{
	float x = gd->mainShip->HullStructureStability[3]; //
	result = checkWithParamf1(x);
}

void ConditionRef::checkShieldStructureStability()
{
	float x = gd->mainShip->ShieldStructureStability[3]; //
	result = checkWithParamf1(x);
}

void ConditionRef::checkHullResistance()
{
	float x = gd->mainShip->HullResist[i1][3]; //
	result = checkWithParamf1(x);
}

void ConditionRef::checkShieldResistance()
{
	float x = gd->mainShip->ShieldResist[i1][3]; //
	result = checkWithParamf1(x);
}