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

	// put to queue

	p_q.push({list, element});

}

void ScriptSystem::externalEvent()
{
	if (p_state != scriptSystemState_blocked)
		return;

	p_blocked = false;
	p_state = scriptSystemState_external_event;

	p_x = b_x;
	p_l = b_l;

	p_final = false;

	process();
}

void ScriptSystem::update()
{
	if (p_blocked)
		return;
	while (!p_q.empty() && (p_state == scriptSystemState_processQueue || p_state == scriptSystemState_Idle))
	{
		auto e = p_q.front();
		p_q.pop();

		// construct Enviroment

		p_l = e.first;
		p_x = e.second;
		p_final = false;

		// start script chain execution

		process();
	}
	if (p_state != scriptSystemState_blocked)
		p_state = scriptSystemState_Idle;
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

ScriptSystemState ScriptSystem::getState()
{
	return p_state;
}

BaseScript * ScriptSystem::getCurrentElement()
{
	return p_c;
}

void * ScriptSystem::getContext()
{
	return p_context;
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
	p_next = p_c->next; // сразу ставим поинтер на некст
					 // команда может поменять его сама

	p_final = p_c->final;

	switch (type)
	{
	case script_base:
		break;
	case script_text:
		if (p_state != scriptSystemState_external_event)
			textScriptHandler();
		else
			textScriptUpdater();
		break;
	case script_choose:
		break;
	case script_action:
		actionScriptHandler();
		break;
	default:
		break;
	}

	p_x = p_next;

}

void ScriptSystem::setupBlock()
{
	p_blocked = true;
	if (p_context != nullptr)
		delete(p_context);
	b_l = p_l;
	b_x = p_x;
}

void ScriptSystem::textScriptHandler()
{
	setupBlock();
	//p_context = new // text scriot dont need special context
	p_state = scriptSystemState_blocked;
}

void ScriptSystem::textScriptUpdater()
{
	// 
	Log("Info: External event succesfully handled (TEXT) ");
	p_state = scriptSystemState_processQueue;
}

void ScriptSystem::actionScriptHandler()
{
	ActionScript * q = static_cast<ActionScript*>(p_c);
	q->run(); // do you really think that this will work? // no
}


