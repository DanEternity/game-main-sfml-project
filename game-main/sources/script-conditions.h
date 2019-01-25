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
	void checkHull();
};