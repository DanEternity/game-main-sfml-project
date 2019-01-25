#pragma once

#include <map>

#include "base-script.h"
#include "action-script.h"
#include "debug.h"

class ScriptSystem
{
public:
	
	std::map<int, std::vector<BaseScript*>> s;

	void execute(int list);
	void execute(int list, int element);

	int addLine(BaseScript * element);
	int addElement(int line, BaseScript * element);

private:
	void process();
	void runScript(int x, int y);

	int p_l;
	int p_x;

	bool p_blocked = false;
	bool p_final = false;
	int p_size = 0;

	BaseScript * p_c; // current command

	/* script handlers */

	void actionScriptHandler();
};