#pragma once

#ifndef GAME_DATA_GLOBAL
#define GAME_DATA_GLOBAL

#include "ship.h"
#include "character-manager.h"
#include "ship-manager.h"
#include "ship-scheme.h"
//#include "game-settings.h"
#include "adventure-logbook.h"
#include "script-system.h"
#include "star-map-navigator.h"
#include "space-battle-info.h"
#include "effects.h"

class ShipManager;
class Ship;
class ShipScheme;
class CharacterSystem;
class Character;
class AdventureLogbook;
class ScriptSystem;
class ShipStorage;

class GameData
{
public:
	ShipManager * shipManager;
	// ship assistant manager
	
	Ship * mainShip;

	ShipScheme * scheme;

	ShipStorage * storage;
	
	CharacterSystem * charSystem;
	// charSystem should use THIS vector instead of own
	
	std::vector<Character*> characters;
	
	AdventureLogbook * logbook;

	ScriptSystem * scriptSystem;
	// primary script engine

	std::vector<LocalEffect> globalEffects;
	// special effects // affect game

	__int64 mainSeed;
	// seed of global world generation

	//std::vector<ZoneObject *> zones;
	// space map

	StarMapNavigator * starMap;
	// cross sector navigation assistant

	SpaceBattleInfo * spaceBattleInfo;
	// buffer for space battle registration 

};

static GameData * gd;

#endif // !GAME_DATA_GLOBAL

