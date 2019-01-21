#include "game-init.h"

void MainInitializer::createGame(GameData ** tt, __int64 hashKey, int scheme)
{
	Log("Start GameData initialization...");

	GameData * t = new GameData();

	t->shipManager = new ShipManager();
	t->scheme = new ShipScheme();
	t->scheme->create(scheme);
	
	t->mainShip = new Ship();
	t->storage = new ShipStorage();
	t->charSystem = new CharacterSystem();
	t->logbook = new AdventureLogbook();
	t->scriptSystem = new ScriptSystem();
	t->mainSeed = hashKey;
	t->starMap = new StarMapNavigator();
	//t->spaceBattleInfo = new SpaceBattleInfo();

	t->shipManager->ship = t->mainShip;
	t->shipManager->scheme = t->scheme;
	t->shipManager->storage = t->storage;

	t->shipManager->init(t->scheme);
	t->shipManager->updateStats();

	*tt = t;
}
