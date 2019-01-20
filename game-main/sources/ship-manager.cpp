#include "ship-manager.h"

void ShipManager::clearStats()
{
	/* mod stats */

	 ship->PowerSupply[1] = 0; // произведено энергии
	 ship->PowerUse[1] = 0; // потрачено энергии
	 ship->ActionPoints[1] = 0; // очки действия (в бою)
	 ship->Evasion[1] = 0; // рейтинг уклонения (может быть отрицательным (?))
	 ship->Mobility[1] = 0; // рейтинг маневренности (снижает стоимость движения)
	 ship->Stealth[1] = 0; // скрытность корабля
	 ship->StealthTier[1] = 0; // определяет необходимый уровень сенсоров для получения данных о цели (хп, щит, защита и т.д.)
	 ship->SensorPower[1] = 0; // мощность сенсоров
	 ship->SensorTier[1] = 0; // уровень сенсоров
	 ship->HyperDriveSpeed[1] = 0; // мод. скорости движения корабля (хз особо на игру не влияет, но где-то может быть важным. Ускоряет передвижение корабля по миру)
	 ship->HyperDriveTier[1] = 0; // класс гипердвигателя (определяет возможность путешествия в некоторые узлы
	 ship->HyperDriveFuelCost[1] = 0; // стоимость прыжка / или модификатор стоимости прыжка (скорее всего второе)
	 ship->Hull[1] = 0; // прочность корпуса
	 
	 ship->HullReg[1] = 0; // хотя реген корпуса может показаться бредом, некоторые враги вполне могут использовать это
	 ship->Shield[1] = 0; // емкость щита
	 for (int i(0); i < 2; i++)
	 {
		 ship->HullResist[i][1] = 0; // защита корпуса
		 ship->ShieldResist[i][1] = 0; // защита щита 
	 }
	 ship->ShieldReg[1] = 0; // регенерация щита

	 ship->MissileDefense[1] = 0; // рейтинг системы ПРО
	 ship->MissileDefenseTier[1] = 0; // уровень системы ПРО
	 ship->HullStructureStability[1] = 0; // сопротивляемость критическому урону(УРОНУ, а не шансу крита)
	 ship->ShieldStructureStability[1] = 0; // тоже самое, но для щита

	 /* mod % */

	 ship->PowerSupply[2] = 0; // произведено энергии
	 ship->PowerUse[2] = 0; // потрачено энергии
	 ship->ActionPoints[2] = 0; // очки действия (в бою)
	 ship->Evasion[2] = 0; // рейтинг уклонения (может быть отрицательным (?))
	 ship->Mobility[2] = 0; // рейтинг маневренности (снижает стоимость движения)
	 ship->Stealth[2] = 0; // скрытность корабля
	 ship->StealthTier[2] = 0; // определяет необходимый уровень сенсоров для получения данных о цели (хп, щит, защита и т.д.)
	 ship->SensorPower[2] = 0; // мощность сенсоров
	 ship->SensorTier[2] = 0; // уровень сенсоров
	 ship->HyperDriveSpeed[2] = 0; // мод. скорости движения корабля (хз особо на игру не влияет, но где-то может быть важным. Ускоряет передвижение корабля по миру)
	 ship->HyperDriveTier[2] = 0; // класс гипердвигателя (определяет возможность путешествия в некоторые узлы
	 ship->HyperDriveFuelCost[2] = 0; // стоимость прыжка / или модификатор стоимости прыжка (скорее всего второе)
	 ship->Hull[2] = 0; // прочность корпуса

	 ship->HullReg[2] = 0; // хотя реген корпуса может показаться бредом, некоторые враги вполне могут использовать это
	 ship->Shield[2] = 0; // емкость щита
	 for (int i(0); i < 2; i++)
	 {
		 ship->HullResist[i][2] = 0; // защита корпуса
		 ship->ShieldResist[i][2] = 0; // защита щита 
	 }
	 ship->ShieldReg[2] = 0; // регенерация щита

	 ship->MissileDefense[2] = 0; // рейтинг системы ПРО
	 ship->MissileDefenseTier[2] = 0; // уровень системы ПРО
	 ship->HullStructureStability[2] = 0; // сопротивляемость критическому урону(УРОНУ, а не шансу крита)
	 ship->ShieldStructureStability[2] = 0; // тоже самое, но для щита

	 /* battle stats */

	 ship->PowerSupply[3] = 0; // произведено энергии
	 ship->PowerUse[3] = 0; // потрачено энергии
	 ship->ActionPoints[3] = 0; // очки действия (в бою)
	 ship->Evasion[3] = 0; // рейтинг уклонения (может быть отрицательным (?))
	 ship->Mobility[3] = 0; // рейтинг маневренности (снижает стоимость движения)
	 ship->Stealth[3] = 0; // скрытность корабля
	 ship->StealthTier[3] = 0; // определяет необходимый уровень сенсоров для получения данных о цели (хп, щит, защита и т.д.)
	 ship->SensorPower[3] = 0; // мощность сенсоров
	 ship->SensorTier[3] = 0; // уровень сенсоров
	 ship->HyperDriveSpeed[3] = 0; // мод. скорости движения корабля (хз особо на игру не влияет, но где-то может быть важным. Ускоряет передвижение корабля по миру)
	 ship->HyperDriveTier[3] = 0; // класс гипердвигателя (определяет возможность путешествия в некоторые узлы
	 ship->HyperDriveFuelCost[3] = 0; // стоимость прыжка / или модификатор стоимости прыжка (скорее всего второе)
	 ship->Hull[3] = 0; // прочность корпуса

	 ship->HullReg[3] = 0; // хотя реген корпуса может показаться бредом, некоторые враги вполне могут использовать это
	 ship->Shield[3] = 0; // емкость щита
	 for (int i(0); i < 2; i++)
	 {
		 ship->HullResist[i][3] = 0; // защита корпуса
		 ship->ShieldResist[i][3] = 0; // защита щита 
	 }
	 ship->ShieldReg[3] = 0; // регенерация щита

	 ship->MissileDefense[3] = 0; // рейтинг системы ПРО
	 ship->MissileDefenseTier[3] = 0; // уровень системы ПРО
	 ship->HullStructureStability[3] = 0; // сопротивляемость критическому урону(УРОНУ, а не шансу крита)
	 ship->ShieldStructureStability[3] = 0; // тоже самое, но для щита

}

void ShipManager::updateStats()
{
	/* Nullify all stats */
	clearStats();

	for (int i(0); i < scheme->slots.size(); i++)
	{
		if (scheme->slots[i].m != NULL)
		{
			auto mType = scheme->slots[i].m->type;
			if (mType == moduleTypeSys)
			{
				SystemModuleItem *m = (SystemModuleItem*)(scheme->slots[i].m);
				for (int j(0); m->effects.size(); j++)
				{
					applyEffect(&m->effects[j]);
				}
			}
		}
	}

	ship->PowerSupply[3] = (ship->PowerSupply[0] + ship->PowerSupply[1]) * ship->PowerSupply[2]; 
	ship->PowerUse[3] = (ship->PowerUse[0] + ship->PowerUse[1]) * ship->PowerUse[2]; 
	ship->ActionPoints[3] = (ship->ActionPoints[0] + ship->ActionPoints[1]) * ship->ActionPoints[2]; 
	ship->Evasion[3] = (ship->Evasion[0] + ship->Evasion[1]) * ship->Evasion[2];
	ship->Mobility[3] = (ship->Mobility[0] + ship->Mobility[1]) * ship->Mobility[2]; 
	ship->Stealth[3] = (ship->Stealth[0] + ship->Stealth[1]) * ship->Stealth[2]; 
	ship->StealthTier[3] = (ship->StealthTier[0] + ship->StealthTier[1]) * ship->StealthTier[2]; 
	ship->SensorPower[3] = (ship->SensorPower[0] + ship->SensorPower[1]) * ship->SensorPower[2]; 
	ship->SensorTier[3] = (ship->SensorTier[0] + ship->SensorTier[1]) * ship->SensorTier[2]; 
	ship->HyperDriveSpeed[3] = (ship->HyperDriveSpeed[0] + ship->HyperDriveSpeed[1]) * ship->HyperDriveSpeed[2]; 
	ship->HyperDriveTier[3] = (ship->HyperDriveTier[0] + ship->HyperDriveTier[1]) * ship->HyperDriveTier[2]; 
	ship->HyperDriveFuelCost[3] = (ship->HyperDriveFuelCost[0] + ship->HyperDriveFuelCost[1]) * ship->HyperDriveFuelCost[2]; 
	ship->Hull[3] = (ship->Hull[0] + ship->Hull[1]) * ship->Hull[2]; // прочность корпуса
	for (int i(0); i < 2; i++)
	{
		ship->HullResist[i][3] = (ship->HullResist[i][0] + ship->HullResist[i][1]) * ship->HullResist[i][2]; // защита корпуса
		ship->ShieldResist[i][3] = (ship->ShieldResist[i][0] + ship->ShieldResist[i][1]) * ship->ShieldResist[i][2]; // защита щита 
	}
	ship->HullReg[3] = (ship->HullReg[0] + ship->HullReg[1]) * ship->HullReg[2]; 
	ship->Shield[3] = (ship->Shield[0] + ship->Shield[1]) * ship->Shield[2]; // емкость щита
	ship->ShieldReg[3] = (ship->ShieldReg[0] + ship->ShieldReg[1]) * ship->ShieldReg[2]; // регенерация щита
	ship->MissileDefense[3] = (ship->MissileDefense[0] + ship->MissileDefense[1]) 
		* ship->MissileDefense[2]; // рейтинг системы ПРО
	ship->MissileDefenseTier[3] = (ship->MissileDefenseTier[0] + ship->MissileDefenseTier[1]) 
		* ship->MissileDefenseTier[2]; // уровень системы ПРО
	ship->HullStructureStability[3] = (ship->HullStructureStability[0] + ship->HullStructureStability[1]) 
		* ship->HullStructureStability[2]; // сопротивляемость критическому урону(УРОНУ, а не шансу крита)
	ship->ShieldStructureStability[3] = (ship->ShieldStructureStability[0] + ship->ShieldStructureStability[1]) 
		* ship->ShieldStructureStability[2]; // тоже самое, но для щита

}

void ShipManager::applyEffect(LocalEffect * effect)
{
	auto type = effect->type;
	switch (type)
	{
	case EffectTypeNull:
		break;
	case ModuleStat:
		applyModuleStatEffect(effect);
		break;
	default:
		Log("Error. Cant apply effect");
		break;
	}
}

void ShipManager::applyModuleStatEffect(LocalEffect * effect)
{
	if (effect->type != ModuleStat)
	{
		Log("Error. Wrong effect type");
		return;
	}
	ModuleStatSubType type = static_cast<ModuleStatSubType>(effect->subType);

	switch (type)
	{
	case StatPowerSupply:
		ship->PowerSupply[QMod] += effect->f1;
		ship->PowerSupply[QModPercent] += effect->f2;
		break;
	case StatPowerUse:
		ship->PowerUse[QMod] += effect->f1;
		ship->PowerUse[QModPercent] += effect->f2;
		break;
	case StatActionPoints:
		ship->ActionPoints[QMod] += effect->f1;
		ship->ActionPoints[QModPercent] += effect->f2;
		break;
	case StatEvasion:
		ship->Evasion[QMod] += effect->f1;
		ship->Evasion[QModPercent] += effect->f2;
		break;
	case StatMobility:
		ship->Mobility[QMod] += effect->f1;
		ship->Mobility[QModPercent] += effect->f2;
		break;
	case StatStealth:
		ship->Stealth[QMod] += effect->f1;
		ship->Stealth[QModPercent] += effect->f2;
		break;
	case StatStealthTier:
		ship->StealthTier[QMod] += effect->f1;
		ship->StealthTier[QModPercent] += effect->f2;
		break;
	case StatSensorPower:
		ship->SensorPower[QMod] += effect->f1;
		ship->SensorPower[QModPercent] += effect->f2;
		break;
	case StatSensorTier:
		ship->SensorTier[QMod] += effect->f1;
		ship->SensorTier[QModPercent] += effect->f2;
		break;
	case StatHyperDriveSpeed:
		ship->HyperDriveSpeed[QMod] += effect->f1;
		ship->HyperDriveSpeed[QModPercent] += effect->f2;
		break;
	case StatHyperDriveTier:
		ship->HyperDriveTier[QMod] += effect->f1;
		ship->HyperDriveTier[QModPercent] += effect->f2;
		break;
	case StatHyperDriveFuelCost:
		ship->HyperDriveFuelCost[QMod] += effect->f1;
		ship->HyperDriveFuelCost[QModPercent] += effect->f2;
		break;
	case StatHull:
		ship->Hull[QMod] += effect->f1;
		ship->Hull[QModPercent] += effect->f2;
		break;
	case StatHullResist:
		ship->HullResist[effect->i1][QMod] += effect->f1;
		ship->HullResist[effect->i1][QModPercent] += effect->f2;
		break;
	case StatHullReg:
		ship->HullReg[QMod] += effect->f1;
		ship->HullReg[QModPercent] += effect->f2;
		break;
	case StatShield:
		ship->Shield[QMod] += effect->f1;
		ship->Shield[QModPercent] += effect->f2;
		break;
	case StatShieldResist:
		ship->ShieldResist[effect->i1][QMod] += effect->f1;
		ship->ShieldResist[effect->i1][QModPercent] += effect->f2;
		break;
	case StatShieldReg:
		ship->ShieldReg[QMod] += effect->f1;
		ship->ShieldReg[QModPercent] += effect->f2;
		break;
	case StatMissileDefense:
		ship->MissileDefense[QMod] += effect->f1;
		ship->MissileDefense[QModPercent] += effect->f2;
		break;
	case StatMissileDefenseTier:
		ship->MissileDefenseTier[QMod] += effect->f1;
		ship->MissileDefenseTier[QModPercent] += effect->f2;
		break;
	case StatHullStructureStability:
		ship->HullStructureStability[QMod] += effect->f1;
		ship->HullStructureStability[QModPercent] += effect->f2;
		break;
	case StatShieldStructureStability:
		ship->ShieldStructureStability[QMod] += effect->f1;
		ship->ShieldStructureStability[QModPercent] += effect->f2;
		break;
	default: 
		Log("Error! Wrong type of module stat.");
		break;
	}
}

void ShipManager::init(ShipScheme * qScheme)
{
	scheme = qScheme;

	ship->PowerSupply[0] = 0; // произведено энергии
	ship->PowerUse[0] = 0; // потрачено энергии
	ship->ActionPoints[0] = scheme->ActionPoints; // очки действия (в бою)
	ship->Evasion[0] = scheme->Evasion; // рейтинг уклонения (может быть отрицательным (?))
	ship->Mobility[0] = scheme->Mobility; // рейтинг маневренности (снижает стоимость движения)
	ship->Stealth[0] = scheme->Stealth; // скрытность корабля
	ship->StealthTier[0] = scheme->StealthTier; // определяет необходимый уровень сенсоров для получения данных о цели (хп, щит, защита и т.д.)
	ship->SensorPower[0] = scheme->SensorPower; // мощность сенсоров
	ship->SensorTier[0] = scheme->SensorTier; // уровень сенсоров
	ship->HyperDriveSpeed[0] = scheme->HyperDriveSpeed; // мод. скорости движения корабля (хз особо на игру не влияет, но где-то может быть важным. Ускоряет передвижение корабля по миру)
	ship->HyperDriveTier[0] = scheme->HyperDriveTier; // класс гипердвигателя (определяет возможность путешествия в некоторые узлы
	ship->HyperDriveFuelCost[0] = scheme->HyperDriveFuelCost; // стоимость прыжка / или модификатор стоимости прыжка (скорее всего второе)
	ship->Hull[0] = scheme->Hull; // прочность корпуса
	for (int i(0); i < 2; i++)
	{
		ship->HullResist[i][0] = scheme->HullResist[i]; // защита корпуса
		ship->ShieldResist[i][0] = scheme->ShieldResist[i]; // защита щита 
	} 
	ship->HullReg[0] = scheme->HullReg; // хотя реген корпуса может показаться бредом, некоторые враги вполне могут использовать это
	ship->Shield[0] = scheme->Shield; // емкость щита
	ship->ShieldReg[0] = scheme->ShieldReg; // регенерация щита
	ship->MissileDefense[0] = scheme->MissileDefense; // рейтинг системы ПРО
	ship->MissileDefenseTier[0] = scheme->MissileDefenseTier; // уровень системы ПРО
	ship->HullStructureStability[0] = scheme->HullStructureStability; // сопротивляемость критическому урону(УРОНУ, а не шансу крита)
	ship->ShieldStructureStability[0] = scheme->ShieldStructureStability; // тоже самое, но для щита
}

void ShipManager::debug()
{
	SystemModuleItem * p = new SystemModuleItem();
	WeaponModuleItem * w = new WeaponModuleItem();

	p->nameLine = "Sample";
	p->image = NULL;
	p->descLines.push_back("Sample description");
	p->lvl = 1;
	p->rare = 1;
	p->powerUsage = 1;
	LocalEffect eff = LocalEffect();
	eff.effectID = ModuleStat; // do not change
	eff.subType = StatPowerSupply;
	eff.f1 = 10; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	eff.subType = StatHull;
	eff.f1 = 125; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	p->slot = slot_Universal;
	p->type = moduleTypeSys;
	

	// scheme->setModule(p);
	p = new SystemModuleItem(); // и так далее // объявлять p второй раз не нужно
	// только создать новый объект через new
	p->nameLine = "Click";
	p->image = NULL;
	p->descLines.push_back("Base sensor");
	p->lvl = 1;
	p->rare = 1;
	p->powerUsage = 1;
	eff.effectID = ModuleStat; // do not change
	eff.subType = StatSensorPower;
	eff.f1 = 50; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	eff.subType = StatSensorTier;
	eff.f1 = 1; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	p->slot = slot_Universal;
	p->type = moduleTypeSys;


	p = new SystemModuleItem(); // и так далее // объявлять p второй раз не нужно
	// только создать новый объект через new
	p->nameLine = "Prototype";
	p->image = NULL;
	p->descLines.push_back("Shield generator prototype");
	p->lvl = 1;
	p->rare = 1;
	p->powerUsage = 2;
	eff.effectID = ModuleStat; // do not change
	eff.subType = StatShield;
	eff.f1 = 100; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	eff.subType = StatShieldResist;
	eff.i1 = 0;
	eff.f1 = 1; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	eff.subType = StatShieldResist;
	eff.i1 = 1;
	eff.f1 = 1.5f; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	p->slot = slot_Universal;
	p->type = moduleTypeSys;


	p = new SystemModuleItem(); // и так далее // объявлять p второй раз не нужно
	// только создать новый объект через new
	p->nameLine = "Atom-300";
	p->image = NULL;
	p->descLines.push_back("First gen nuclear reactor");
	p->lvl = 1;
	p->rare = 1;
	p->powerUsage = 0;
	eff.effectID = ModuleStat; // do not change
	eff.subType = StatPowerSupply;
	eff.f1 = 30; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	eff.subType = StatActionPoints;
	eff.f1 = 10; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	p->slot = slot_Core;
	p->type = moduleTypeSys;


	p = new SystemModuleItem(); // и так далее // объявлять p второй раз не нужно
	// только создать новый объект через new
	p->nameLine = "Jump-prototype";
	p->image = NULL;
	p->descLines.push_back("Hyper drive core prototype");
	p->lvl = 1;
	p->rare = 1;
	p->powerUsage = 25;
	eff.effectID = ModuleStat; // do not change
	eff.subType = StatHyperDriveSpeed;
	eff.f1 = 10; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	eff.subType = StatHyperDriveTier;
	eff.f1 = 1; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	eff.subType = StatHyperDriveFuelCost;
	eff.f1 = 100; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	p->slot = slot_HyperDrive;
	p->type = moduleTypeSys;


	p = new SystemModuleItem(); // и так далее // объявлять p второй раз не нужно
	// только создать новый объект через new
	p->nameLine = "Alice";
	p->image = NULL;
	p->descLines.push_back("Space ship's system prototype");
	p->lvl = 1;
	p->rare = 1;
	p->powerUsage = 2;
	eff.effectID = ModuleStat; // do not change
	eff.subType = StatHyperDriveSpeed;
	eff.f1 = 0; // +X
	eff.f2 = 2; // +X%
	p->effects.push_back(eff);
	eff.subType = StatPowerSupply;
	eff.f1 = 0; // +X
	eff.f2 = 10; // +X%
	p->effects.push_back(eff);
	eff.subType = StatHyperDriveFuelCost;
	eff.f1 = 0; // +X
	eff.f2 = 10; // +X%
	p->effects.push_back(eff);
	eff.subType = StatSensorPower;
	eff.f1 = 0; // +X
	eff.f2 = 10; // +X%
	p->effects.push_back(eff);
	eff.subType = StatShield;
	eff.f1 = 0; // +X
	eff.f2 = 10; // +X%
	p->effects.push_back(eff);
	eff.subType = StatMissileDefense;
	eff.f1 = 20; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	eff.subType = StatMissileDefenseTier;
	eff.f1 = 1; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	p->slot = slot_System;
	p->type = moduleTypeSys;

	p = new SystemModuleItem(); // и так далее // объявлять p второй раз не нужно
	// только создать новый объект через new
	p->nameLine = "Tigr";
	p->image = NULL;
	p->descLines.push_back("First mass production human space engine");
	p->lvl = 1;
	p->rare = 1;
	p->powerUsage = 5;
	eff.effectID = ModuleStat; // do not change
	eff.subType = StatEvasion;
	eff.f1 = 10; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	eff.subType = StatMobility;
	eff.f1 = 2; // +X
	eff.f2 = 0; // +X%
	p->effects.push_back(eff);
	p->slot = slot_Engine;
	p->type = moduleTypeSys;
	

	w = new WeaponModuleItem(); // и так далее // объявлять p второй раз не нужно
	// только создать новый объект через new
	w->nameLine = "Gauss-weapon";
	w->image = NULL;
	w->descLines.push_back("First mass production human kinetic space weapon");
	w->lvl = 1;
	w->rare = 1;
	w->powerUsage = 3;
	w->ActivationCost = 1;
	w->baseDamage = 10;
	w->baseAccuracy = 70;
	w->damageLosePerCell = 1;
	w->damageMaxCells = 5;
	w->accuracyLosePerCell = 20;
	w->accuracyMaxCells = 3;
	w->damageType = physical;
	w->armorPierce[0] = 10;
	w->armorPierce[1] = 5;
	w->critChanceHull = 5;
	w->critDamageHull = 20;
	w->critChanceShield = 0;
	w->critDamageShield = 20;
	w->slot = slot_MainWeapon;
	w->type = moduleTypeWeapon;


	w = new WeaponModuleItem(); // и так далее // объявлять p второй раз не нужно
	// только создать новый объект через new
	w->nameLine = "Plasma-weapon prototype";
	w->image = NULL;
	w->descLines.push_back("First prototype of human plasma space weapon");
	w->lvl = 1;
	w->rare = 1;
	w->powerUsage = 3;
	w->ActivationCost = 2;
	w->baseDamage = 30;
	w->baseAccuracy = 100;
	w->damageLosePerCell = 10;
	w->damageMaxCells = 3;
	w->accuracyLosePerCell = 10;
	w->accuracyMaxCells = 3;
	w->damageType = energy;
	w->armorPierce[0] = 5;
	w->armorPierce[1] = 15;
	w->critChanceHull = 1;
	w->critDamageHull = 60;
	w->critChanceShield = 20;
	w->critDamageShield = 80;
	w->slot = slot_MainWeapon;
	w->type = moduleTypeWeapon;
}

