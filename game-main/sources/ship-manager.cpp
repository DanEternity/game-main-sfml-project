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
	 ship->HullResist[HullResistN][1] = 0; // защита корпуса
	 ship->HullReg[1] = 0; // хотя реген корпуса может показаться бредом, некоторые враги вполне могут использовать это
	 ship->Shield[1] = 0; // емкость щита
	 ship->ShieldResist[ShieldResistN][1] = 0; // защита щита 
	 ship->ShieldReg[1] = 0; // регенерация щита

	 ship->MissileDefense[1] = 0; // рейтинг системы ПРО
	 ship->MissileDefenseTier[1] = 0; // уровень системы ПРО
	 ship->HullStructureStability[1] = 0; // сопротивляемость критическому урону(УРОНУ, а не шансу крита)
	 ship->ShieldStructureStability[1] = 0; // тоже самое, но для щита

	 /* battle stats */

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
	 ship->HullResist[HullResistN][2] = 0; // защита корпуса
	 ship->HullReg[2] = 0; // хотя реген корпуса может показаться бредом, некоторые враги вполне могут использовать это
	 ship->Shield[2] = 0; // емкость щита
	 ship->ShieldResist[ShieldResistN][2] = 0; // защита щита 
	 ship->ShieldReg[2] = 0; // регенерация щита

	 ship->MissileDefense[2] = 0; // рейтинг системы ПРО
	 ship->MissileDefenseTier[2] = 0; // уровень системы ПРО
	 ship->HullStructureStability[2] = 0; // сопротивляемость критическому урону(УРОНУ, а не шансу крита)
	 ship->ShieldStructureStability[2] = 0; // тоже самое, но для щита
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

	ship->PowerSupply[2] = ship->PowerSupply[0] + ship->PowerSupply[1]; // произведено энергии
	ship->PowerUse[2] = ship->PowerUse[0] + ship->PowerUse[1]; // потрачено энергии
	ship->ActionPoints[2] = ship->ActionPoints[0] + ship->ActionPoints[1]; // очки действия (в бою)
	ship->Evasion[2] = ship->Evasion[0] + ship->Evasion[1]; // рейтинг уклонения (может быть отрицательным (?))
	ship->Mobility[2] = ship->Mobility[0] + ship->Mobility[1]; // рейтинг маневренности (снижает стоимость движения)
	ship->Stealth[2] = ship->Stealth[0] + ship->Stealth[1]; // скрытность корабля
	ship->StealthTier[2] = ship->StealthTier[0] + ship->StealthTier[1]; // определяет необходимый уровень сенсоров для получения данных о цели (хп, щит, защита и т.д.)
	ship->SensorPower[2] = ship->SensorPower[0] + ship->SensorPower[1]; // мощность сенсоров
	ship->SensorTier[2] = ship->SensorTier[0] + ship->SensorTier[1]; // уровень сенсоров
	ship->HyperDriveSpeed[2] = ship->HyperDriveSpeed[0] + ship->HyperDriveSpeed[1]; // мод. скорости движения корабля (хз особо на игру не влияет, но где-то может быть важным. Ускоряет передвижение корабля по миру)
	ship->HyperDriveTier[2] = ship->HyperDriveTier[0] + ship->HyperDriveTier[1]; // класс гипердвигателя (определяет возможность путешествия в некоторые узлы
	ship->HyperDriveFuelCost[2] = ship->HyperDriveFuelCost[0] + ship->HyperDriveFuelCost[1]; // стоимость прыжка / или модификатор стоимости прыжка (скорее всего второе)
	ship->Hull[2] = ship->Hull[0] + ship->Hull[1]; // прочность корпуса
	//ship->HullResist[HullResistN][2] = ship->[0] + ship->[1]; // защита корпуса
	ship->HullReg[2] = ship->HullReg[0] + ship->HullReg[1]; // хотя реген корпуса может показаться бредом, некоторые враги вполне могут использовать это
	ship->Shield[2] = ship->Shield[0] + ship->Shield[1]; // емкость щита
	//ship->ShieldResist[ShieldResistN][2] = ship->[0] + ship->[1]; // защита щита 
	ship->ShieldReg[2] = ship->ShieldReg[0] + ship->ShieldReg[1]; // регенерация щита

	ship->MissileDefense[2] = ship->MissileDefense[0] + ship->MissileDefense[1]; // рейтинг системы ПРО
	ship->MissileDefenseTier[2] = ship->MissileDefenseTier[0] + ship->MissileDefenseTier[1]; // уровень системы ПРО
	ship->HullStructureStability[2] = ship->HullStructureStability[0] + ship->HullStructureStability[1]; // сопротивляемость критическому урону(УРОНУ, а не шансу крита)
	ship->ShieldStructureStability[2] = ship->ShieldStructureStability[0] + ship->ShieldStructureStability[1]; // тоже самое, но для щита

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
		ship->PowerSupply[QMod] += ship->PowerSupply[QBase] * effect->f2;
		break;
	case StatPowerUse:
		ship->PowerUse[QMod] += effect->f1;
		ship->PowerUse[QMod] += ship->PowerUse[QBase] * effect->f2;
		break;
	case StatActionPoints:
		ship->ActionPoints[QMod] += effect->f1;
		ship->ActionPoints[QMod] += ship->ActionPoints[QBase] * effect->f2;
		break;
	case StatEvasion:
		ship->Evasion[QMod] += effect->f1;
		ship->Evasion[QMod] += ship->Evasion[QBase] * effect->f2;
		break;
	case StatMobility:
		ship->Mobility[QMod] += effect->f1;
		ship->Mobility[QMod] += ship->Mobility[QBase] * effect->f2;
		break;
	case StatStealth:
		ship->Stealth[QMod] += effect->f1;
		ship->Stealth[QMod] += ship->Stealth[QBase] * effect->f2;
		break;
	case StatStealthTier:
		ship->StealthTier[QMod] += effect->f1;
		ship->StealthTier[QMod] += ship->StealthTier[QBase] * effect->f2;
		break;
	case StatSensorPower:
		ship->SensorPower[QMod] += effect->f1;
		ship->SensorPower[QMod] += ship->SensorPower[QBase] * effect->f2;
		break;
	case StatSensorTier:
		ship->SensorTier[QMod] += effect->f1;
		ship->SensorTier[QMod] += ship->SensorTier[QBase] * effect->f2;
		break;
	case StatHyperDriveSpeed:
		ship->HyperDriveSpeed[QMod] += effect->f1;
		ship->HyperDriveSpeed[QMod] += ship->HyperDriveSpeed[QBase] * effect->f2;
		break;
	case StatHyperDriveTier:
		ship->HyperDriveTier[QMod] += effect->f1;
		ship->HyperDriveTier[QMod] += ship->HyperDriveTier[QBase] * effect->f2;
		break;
	case StatHyperDriveFuelCost:
		ship->HyperDriveFuelCost[QMod] += effect->f1;
		ship->HyperDriveFuelCost[QMod] += ship->HyperDriveFuelCost[QBase] * effect->f2;
		break;
	case StatHull:
		ship->Hull[QMod] += effect->f1;
		ship->Hull[QMod] += ship->Hull[QBase] * effect->f2;
		break;
	case StatHullResist:
		//ship->Mobility[QMod] += effect->f1;
		//ship->Mobility[QMod] += ship->Mobility[QBase] * effect->f2;
		break;
	case StatHullReg:
		ship->HullReg[QMod] += effect->f1;
		ship->HullReg[QMod] += ship->HullReg[QBase] * effect->f2;
		break;
	case StatShield:
		ship->Shield[QMod] += effect->f1;
		ship->Shield[QMod] += ship->Shield[QBase] * effect->f2;
		break;
	case StatShieldResist:
		//ship->Mobility[QMod] += effect->f1;
		//ship->Mobility[QMod] += ship->Mobility[QBase] * effect->f2;
		break;
	case StatShieldReg:
		ship->ShieldReg[QMod] += effect->f1;
		ship->ShieldReg[QMod] += ship->ShieldReg[QBase] * effect->f2;
		break;
	case StatMissileDefense:
		ship->MissileDefense[QMod] += effect->f1;
		ship->MissileDefense[QMod] += ship->MissileDefense[QBase] * effect->f2;
		break;
	case StatMissileDefenseTier:
		ship->MissileDefenseTier[QMod] += effect->f1;
		ship->MissileDefenseTier[QMod] += ship->MissileDefenseTier[QBase] * effect->f2;
		break;
	case StatHullStructureStability:
		ship->HullStructureStability[QMod] += effect->f1;
		ship->HullStructureStability[QMod] += ship->HullStructureStability[QBase] * effect->f2;
		break;
	case StatShieldStructureStability:
		ship->ShieldStructureStability[QMod] += effect->f1;
		ship->ShieldStructureStability[QMod] += ship->ShieldStructureStability[QBase] * effect->f2;
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

	// scheme->setModule(p);
	p = new SystemModuleItem(); // и так далее // объявлять p второй раз не нужно
	// только создать новый объект через new
}

