#pragma once

#include "base-script.h"
#include "script-conditions.h"

struct ContextChooseScript
{
	std::vector<bool> selectAvailable;
	//std::vector<bool> selectVisible;
	// result section
	int choose;
};

class ChooseScript : public TextScript
{
public:
	ChooseScript() { type = script_choose; }
	std::vector<TextScript> options;
	std::vector<int> selectors;
	std::vector<ConditionRef> conditions;
};