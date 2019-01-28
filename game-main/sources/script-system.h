#pragma once

#include <map>

#include "base-script.h"
#include "action-script.h"
#include "debug.h"

enum ScriptSystemState
{
	scriptSystemState_Idle,
	scriptSystemState_processQueue,
	scriptSystemState_blocked,
	scriptSystemState_external_event,
};


class ScriptSystem
{
public:
	
	std::map<int, std::vector<BaseScript*>> s;

	void execute(int list);
	void execute(int list, int element);
	void externalEvent();
	void update();

	int addLine(BaseScript * element);
	int addElement(int line, BaseScript * element);

	ScriptSystemState getState();
	BaseScript * getCurrentElement();
	void * getContext();

private:
	void process();
	void runScript(int x, int y);

	std::queue<std::pair<int, int>> p_q;

	int p_l;
	int p_x;
	int p_next;


	int b_l;
	int b_x;

	bool p_blocked = false;
	bool p_final = false;
	int p_size = 0;
	ScriptSystemState p_state;
	void * p_context;
	BaseScript * p_c; // current command

	void setupBlock();
	/* script handlers */

	void textScriptHandler();
	void textScriptUpdater();

	void actionScriptHandler();
};