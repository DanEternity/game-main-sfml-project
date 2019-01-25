#include "action-script.h"

ActionScript::ActionScript()
{
	type = script_action;
}

void ActionScript::run()
{
	switch (acType)
	{
	case ACType_null:
		break;
	case ACType_debugText:
		static_cast<ActionScriptDebugText*>(this)->run();
		break;
	default:
		break;
	}
}

ActionScriptDebugText::ActionScriptDebugText()
{
	type = script_action;
	acType = ACType_debugText;
}

void ActionScriptDebugText::run()
{
	Log(str);
}
