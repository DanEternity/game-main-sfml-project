#pragma once

#include "base-script.h"
#include "game-data-global.h"
#include "debug.h"

enum ActionScriptType
{
	ACType_null,
	ACType_debugText
};

class ActionScript : public BaseScript
{
public:
	ActionScript();
	ActionScriptType acType;
	virtual void run();
};

class ActionScriptDebugText : public ActionScript
{
public:
	ActionScriptDebugText();
	std::string str;
	virtual void run() override;
};
