#pragma once

#include "custom-types.h"
#include "modules.h"

#define ArmorTypesCount 2
class ModuleItem;


struct QShipSlotCell
{
	ModuleItem* m;
	ModuleSlot s;
	int x;
	int y;
	QShipSlotCell()
	{
		m = NULL;
		s = slot_Universal;
		x = 0;
		y = 0;
	}
};

class ShipScheme
{
public:
	std::vector<QShipSlotCell> slots;
	// графическая отрисовка слотов и модулей
	// будет реализована потом
	
	float powerProduced;
	float powerUsed;
	float powerFree;

	/* Base stats for ship type */

	//float PowerSupply; // произведено энергии !dublicate
	//float PowerUse; // потрачено энергии !dublicate
	float ActionPoints; // очки действия (в бою)
	float Evasion; // рейтинг уклонения (может быть отрицательным (?))
	float Mobility; // рейтинг маневренности (снижает стоимость движения)
	float Stealth; // скрытность корабля
	float StealthTier; // определяет необходимый уровень сенсоров для получения данных о цели (хп, щит, защита и т.д.)
	float SensorPower; // мощность сенсоров
	float SensorTier; // уровень сенсоров
	float HyperDriveSpeed; // мод. скорости движения корабля (хз особо на игру не влияет, но где-то может быть важным. Ускоряет передвижение корабля по миру)
	float HyperDriveTier; // класс гипердвигателя (определяет возможность путешествия в некоторые узлы
	float HyperDriveFuelEfficiency; // стоимость прыжка / или модификатор стоимости прыжка (скорее всего второе)
	float Hull; // прочность корпуса
	float HullResist[ArmorTypesCount]; // защита корпуса
	float HullReg; // хотя реген корпуса может показаться бредом, некоторые враги вполне могут использовать это
	float Shield; // емкость щита
	float ShieldResist[ArmorTypesCount]; // защита щита 
	float ShieldReg; // регенерация щита

	float Fuel; // топливо
	float MissileDefense; // рейтинг системы ПРО
	float MissileDefenseTier; // уровень системы ПРО
	float HullStructureStability; // сопротивляемость критическому урону(УРОНУ, а не шансу крита)
	float ShieldStructureStability; // тоже самое, но для щита

	void create(int scremeID);
	bool checkSlotComp(ModuleItem * module, int slot_id);
	void setModule(ModuleItem * module, int slot_id);

private:
	void schemeDebug();
private:

};