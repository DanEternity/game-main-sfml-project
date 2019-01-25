#pragma once

#include <string>
#include <vector>

enum ScriptType
{
	script_base,
	script_text,
	script_choose,
	script_action
};

class BaseScript
{
public:
	BaseScript() { type = script_base; }
	int id;
	ScriptType type;
	bool final;
	int next;
};

class TextScript : BaseScript
{
public:
	TextScript() { type = script_text; }
	std::vector<std::string> text;
};


