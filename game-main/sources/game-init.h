#pragma once

#include "game-data-global.h"
#include "game-enviroment.h"

class MainInitializer
{
public:
	static void createGame(GameData ** target, __int64 hashKey, int scheme);
};