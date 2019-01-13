#pragma once

#include "game-enviroment.h"
#include "Consts.h"

class Ship
{
public:
	Ship();

	float PowerSupply; // произведено энергии
	float PowerUse; // потрачено энергии
	float ActionPoints; // очки действия (в бою)
	float Evasion; // рейтинг уклонения (может быть отрицательным (?))
	float Mobility; // рейтинг маневренности (снижает стоимость движения)
	float Stealth; // скрытность корабля
	float StealthTier; // определяет необходимый уровень сенсоров для получения данных о цели (хп, щит, защита и т.д.)
	float SensorPower; // мощность сенсоров
	float SensorTier; // уровень сенсоров
	float HyperDriveSpeed; // мод. скорости движения корабля (хз особо на игру не влияет, но где-то может быть важным. Ускоряет передвижение корабля по миру)
	float HyperDriveTier; // класс гипердвигателя (определяет возможность путешествия в некоторые узлы
	float HyperDriveFuelCost; // стоимость прыжка / или модификатор стоимости прыжка (скорее всего второе)
	float Hull; // прочность корпуса
	float HullResist[HullResistN]; // защита корпуса
	float HullReg; // хотя реген корпуса может показаться бредом, некоторые враги вполне могут использовать это
	float Shield; // емкость щита
	float ShieldResist[ShieldResistN]; // защита щита 
	float ShieldReg; // регенерация щита
					// статы на модерацию =)
	float MissileDefense; // рейтинг системы ПРО
	float MissileDefenseTier; // уровень системы ПРО
	float HullStructureStability; // сопротивляемость критическому урону(УРОНУ, а не шансу крита)
	float ShieldStructureStability; // тоже самое, но для щита

};