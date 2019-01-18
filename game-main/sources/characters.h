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

	std::string name; // ���
	std::string description; // ��������
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

	CharState charState; // ��������� ��������� (���, �����, ����� � ��)
	float charPenalty; // �������� ������������ �� charPenalty ������ (��-�� �������)
					   
	// social part

	std::map<int, float> relations; // ��������� this � characters[key];
									// ����������: ��������� �������� �� ����, ������, �������� �������, ��������� ��������,
									// ������� ������, ������������� �� ����� �������, ����������� ����� � ��.

	std::map<CharOpinion, float> opinions; 	// ������� ���������
											// ���������: ������ ���������� � ����� ���� ����������� ������ �� ��������� ���������. 
											// ����������� ������ �� ����������� ���������, ���������� ������� �� �� ��� ���� �������
											// ������ �� ������, ������� � �������, ������� ����� ������������ ��������.
											// ������� ��� �������� ���������; ��� ������� �� ���
											// ����������2: ������������ ��� ������� ���������� �� ������ ������� � ����������
											// ������������ � ������ �����, �� ��� ����� �� ��������� ������������ ����� �������������
											// ��� �������� ���������.

	float roleProgress; // 0 ... 100 (in percents)
	float globalRelation; // relation to player (and to team)

	// battle part

	float baseAttack; // for physical based attacks
	float baseWeaponAttack; // for weapon based attacks
	float basePowerAttack; // for power based attacks 
						   // ������� � ���� �������������� ���� (������� �����)
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
	std::vector<LocalEffect*> staticEffects; // �� ������ (� ������ ��� ��� ���� ��������)
	std::vector<LocalEffect*> effects; // ������ (����� ��� ��� ������� ������������)

};

#endif
