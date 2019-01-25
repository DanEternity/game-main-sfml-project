#pragma once

#include "base-script.h"
#include "script-conditions.h"


class ChooseScript : public TextScript
{
public:
	ChooseScript() { type = script_choose; }
	std::vector<TextScript> options;
	std::vector<int> selectors;
	std::vector<ConditionRef> conditions;
};