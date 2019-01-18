#pragma once

#ifndef CHARACTERS
#define CHARACTERS

#include <vector>
#include <string>
#include <map>
#include "custom-types.h"

enum CharRace;
enum CharClass;
enum CharRole;
enum CharAspect;
class UI_ObjectCharacter;
class CharSkill;
class CharAction;
enum CharState;
enum CharOpinion
{
	charOpinionNull
};

class Character
{
public:
	Character();

	std::string name; // имя
	std::string description; // описание
	int id;
	__int64 hashKey;
	UI_ObjectCharacter * model; // character model
	CharRace race; // base skill graph
	CharClass charClass; // advanced skill graph
	CharRole role; // role in ship (can be null)
	CharAspect aspect; // high level skill graph
	std::vector<CharSkill*> skills;
	std::vector<CharAction*> actions;
	int level;
	float exp;
	float expRequired;

	float baseHP;
	float baseMP;
	float baseSD;

	float baseStr;
	float baseAgi;
	float baseInt;

	CharState charState; // состояние персонажа (жив, мертв, ранен и тд…)
	float charPenalty; // персонаж заблокирован на charPenalty циклов (из-за ранения)
					   
	// social part

	std::map<int, float> relations; // отношение this к characters[key];
									// примечание: отношения строятся на расе, классу, сюжетных квестов, случайных событиях,
									// выборах игрока, происшествиях во время высадки, полученному урону и тд.

	std::map<CharOpinion, float> opinions; 	// взгляды персонажа
											// прмечание: Игроку неизвестны и могут быть установлены только по косвенным признакам. 
											// заполняются исходя из предыстории персонажа, определяют реакцию на то или иное событие
											// влияют на ответы, события и диалоги, которые будет генерировать персонаж.
											// условно это характер персонажа; его взгляды на мир
											// примечание2: генерируется эта таблица процедурно на основе шаблона с небольшими
											// отклонениями с учетом зерна, но так чтобы не возникало противоречий между существующими
											// уже строками характера.

	float roleProgress; // 0 ... 100 (in percents)
	float globalRelation; // relation to player (and to team)

	// battle part

	float baseAttack; // for physical based attacks
	float baseWeaponAttack; // for weapon based attacks
	float basePowerAttack; // for power based attacks 
						   // имеется в виду энергетических атак (условно магия)
						   // an ability can use one or more base scales (or not use at all)
	int actionPointsLimit; // limit for this character;
	int currentActionPoints;
	int maxActionPoints; // this round (+1 each round)
	float armor[2];
	float hpRegen;
	float mpRegen;
	float sdRegen;
	float baseCritChance;
	float baseCritDamage;
	float baseAccuracy;
	float baseEvasion;
	std::vector<LocalEffect*> staticEffects; // не боевые (в смысле вне боя тоже работают)
	std::vector<LocalEffect*> effects; // боевые (после боя эта таблица уничтожается)

};

#endif
