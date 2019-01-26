#pragma once

enum EffectType
{
	// note that not all effects can be applied to all objects
	EffectTypeNull, // if empty
	ModuleStat
};

enum ModuleStatSubType
{
	StatPowerSupply, // произведено энергии
	StatPowerUse, // потрачено энергии
	StatActionPoints, // очки действия (в бою)
	StatEvasion, // рейтинг уклонения (может быть отрицательным (?))
	StatMobility, // рейтинг маневренности (снижает стоимость движения)
	StatStealth, // скрытность корабля
	StatStealthTier, // определяет необходимый уровень сенсоров для получения данных о цели (хп, щит, защита и т.д.)
	StatSensorPower, // мощность сенсоров
	StatSensorTier, // уровень сенсоров
	StatHyperDriveSpeed, // мод. скорости движения корабля (хз особо на игру не влияет, но где-то может быть важным. Ускоряет передвижение корабля по миру)
	StatHyperDriveTier, // класс гипердвигателя (определяет возможность путешествия в некоторые узлы
	StatHyperDriveFuelEfficiency, // стоимость прыжка / или модификатор стоимости прыжка (скорее всего второе)
	StatHull, // прочность корпуса
	StatHullResist, // защита корпуса
	StatHullReg, // хотя реген корпуса может показаться бредом, некоторые враги вполне могут использовать это
	StatShield, // емкость щита
	StatShieldResist, // защита щита 
	StatShieldReg, // регенерация щита
	StatMissileDefense, // рейтинг системы ПРО
	StatMissileDefenseTier, // уровень системы ПРО
	StatHullStructureStability, // сопротивляемость критическому урону(УРОНУ, а не шансу крита)
	StatShieldStructureStability // тоже самое, но для щита
};

struct LocalEffect
{
	EffectType type;
	int effectID;
	int subType;

	int scr_id; // 0 if not need
	int trg_id; // 0 if not need

	int i1;
	float f1;
	float f2;
	void * v0; // pointer to extended structure
			   // v0 should be deleted after this structure exceed time of executing

			   // Initializates LocalEffect structure with zero values
	LocalEffect()
	{
		type = EffectTypeNull;
		effectID = 0;
		subType = 0;

		scr_id = 0;
		trg_id = 0;

		i1 = 0;
		f1 = 0;
		f2 = 0;
		v0 = 0;
	};
};