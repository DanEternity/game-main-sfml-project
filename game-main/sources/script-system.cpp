#include "script-system.h"

void ScriptSystem::execute(int list)
{
	execute(list, 0);
}

void ScriptSystem::execute(int list, int element)
{
	if (s.find(list) == s.end())
	{
		Log("Error! List handle not found");
		return;
	}

	if (element > s[list].size() - 1)
	{
		Log("Error! Element index out of list range");
		return;
	}

	// construct Enviroment

	p_l = list;
	p_x = element;
	p_final = false;
	// start script chain execution

	process();

}

int ScriptSystem::addLine(BaseScript * element)
{
	s[p_size++].push_back(element);
	return (p_size - 1);
}

int ScriptSystem::addElement(int line, BaseScript * element)
{
	s[line].push_back(element);
	return (s[line].size() - 1);
}

void ScriptSystem::process()
{

	while (!p_final && !p_blocked)
	{
		runScript(p_l, p_x);
	}

	// 

	if (p_final)
	{
		// delete
	}

}

void ScriptSystem::runScript(int x, int y)
{

	auto type = s[x][y]->type;

	p_c = s[x][y];
	p_x = p_c->next; // сразу ставим поинтер на некст
					 // команда может поменять его сама

	p_final = p_c->final;

	switch (type)
	{
	case script_base:
		break;
	case script_text:
		break;
	case script_choose:
		break;
	case script_action:
		actionScriptHandler();
		break;
	default:
		break;
	}

}

void ScriptSystem::actionScriptHandler()
{
	ActionScript * q = static_cast<ActionScript*>(p_c);
	q->run(); // do you really think that this will work? // no
}


