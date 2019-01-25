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
		break;
	case condition_hull_percent:
		break;
	case condition_shield_percent:
		break;
	case condition_hull:
		checkHull();
		break;
	case condition_shield:
		break;
	case condition_fuel:
		break;
	case condition_fuel_percent:
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

void ConditionRef::checkHull()
{
	float x = gd->mainShip->CurrentHull; //
	result = checkWithParamf1(x);
}
