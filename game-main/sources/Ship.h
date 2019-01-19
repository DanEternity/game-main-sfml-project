#pragma once

#include "game-enviroment.h"
#include "Consts.h"

#define QBase 0
#define QMod 1
#define QBattle 2

class Ship
{
public:
	Ship();

	float PowerSupply[3]; // произведено энергии
	float PowerUse[3]; // потрачено энергии
	float ActionPoints[3]; // очки действия (в бою)
	float Evasion[3]; // рейтинг уклонения (может быть отрицательным (?))
	float Mobility[3]; // рейтинг маневренности (снижает стоимость движения)
	float Stealth[3]; // скрытность корабля
	float StealthTier[3]; // определяет необходимый уровень сенсоров для получения данных о цели (хп, щит, защита и т.д.)
	float SensorPower[3]; // мощность сенсоров
	float SensorTier[3]; // уровень сенсоров
	float HyperDriveSpeed[3]; // мод. скорости движения корабля (хз особо на игру не влияет, но где-то может быть важным. Ускоряет передвижение корабля по миру)
	float HyperDriveTier[3]; // класс гипердвигателя (определяет возможность путешествия в некоторые узлы
	float HyperDriveFuelCost[3]; // стоимость прыжка / или модификатор стоимости прыжка (скорее всего второе)
	float Hull[3]; // прочность корпуса
	float HullResist[HullResistN][3]; // защита корпуса
	float HullReg[3]; // хотя реген корпуса может показаться бредом, некоторые враги вполне могут использовать это
	float Shield[3]; // емкость щита
	float ShieldResist[ShieldResistN][3]; // защита щита 
	float ShieldReg[3]; // регенерация щита

					// статы на модерацию =)
	float MissileDefense[3]; // рейтинг системы ПРО
	float MissileDefenseTier[3]; // уровень системы ПРО
	float HullStructureStability[3]; // сопротивляемость критическому урону(УРОНУ, а не шансу крита)
	float ShieldStructureStability[3]; // тоже самое, но для щита

};