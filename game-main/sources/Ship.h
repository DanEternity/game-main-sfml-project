#pragma once

#include "game-enviroment.h"
#include "Consts.h"

#define QBase 0
#define QMod 1
#define QModPercent 2
#define QBattle 3

#define ArmorTypesCount 2

class Ship
{
public:
	Ship();

	float PowerSupply[4]; // произведено энергии
	float PowerUse[4]; // потрачено энергии
	float ActionPoints[4]; // очки действия (в бою)
	float Evasion[4]; // рейтинг уклонения (может быть отрицательным (?))
	float Mobility[4]; // рейтинг маневренности (снижает стоимость движения)
	float Stealth[4]; // скрытность корабля
	float StealthTier[4]; // определяет необходимый уровень сенсоров для получения данных о цели (хп, щит, защита и т.д.)
	float SensorPower[4]; // мощность сенсоров
	float SensorTier[4]; // уровень сенсоров
	float HyperDriveSpeed[4]; // мод. скорости движения корабля (хз особо на игру не влияет, но где-то может быть важным. Ускоряет передвижение корабля по миру)
	float HyperDriveTier[4]; // класс гипердвигателя (определяет возможность путешествия в некоторые узлы
	float HyperDriveFuelEfficiency[4]; // стоимость прыжка / или модификатор стоимости прыжка (скорее всего второе)
	float Hull[4]; // прочность корпуса
	float HullResist[HullResistN][4]; // защита корпуса
	float HullReg[4]; // хотя реген корпуса может показаться бредом, некоторые враги вполне могут использовать это
	float Shield[4]; // емкость щита
	float ShieldResist[ShieldResistN][4]; // защита щита 
	float ShieldReg[4]; // регенерация щита

	float MissileDefense[4]; // рейтинг системы ПРО
	float MissileDefenseTier[4]; // уровень системы ПРО
	float HullStructureStability[4]; // сопротивляемость критическому урону(УРОНУ, а не шансу крита)
	float ShieldStructureStability[4]; // тоже самое, но для щита
	float Fuel[4]; // запас топлива

	float CurrentHull;
	float CurrentShield;
	float CurrentFuel;
	
	float HullPercent;
};