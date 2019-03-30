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

	float PowerSupply[4]; // ����������� �������
	float PowerUse[4]; // ��������� �������
	float ActionPoints[4]; // ���� �������� (� ���)
	float Evasion[4]; // ������� ��������� (����� ���� ������������� (?))
	float Mobility[4]; // ������� ������������� (������� ��������� ��������)
	float Stealth[4]; // ���������� �������
	float StealthTier[4]; // ���������� ����������� ������� �������� ��� ��������� ������ � ���� (��, ���, ������ � �.�.)
	float SensorPower[4]; // �������� ��������
	float SensorTier[4]; // ������� ��������
	float HyperDriveSpeed[4]; // ���. �������� �������� ������� (�� ����� �� ���� �� ������, �� ���-�� ����� ���� ������. �������� ������������ ������� �� ����)
	float HyperDriveTier[4]; // ����� �������������� (���������� ����������� ����������� � ��������� ����
	float HyperDriveFuelEfficiency[4]; // ��������� ������ / ��� ����������� ��������� ������ (������ ����� ������)
	float Hull[4]; // ��������� �������
	float HullResist[HullResistN][4]; // ������ �������
	float HullReg[4]; // ���� ����� ������� ����� ���������� ������, ��������� ����� ������ ����� ������������ ���
	float Shield[4]; // ������� ����
	float ShieldResist[ShieldResistN][4]; // ������ ���� 
	float ShieldReg[4]; // ����������� ����

	float MissileDefense[4]; // ������� ������� ���
	float MissileDefenseTier[4]; // ������� ������� ���
	float HullStructureStability[4]; // ���������������� ������������ �����(�����, � �� ����� �����)
	float ShieldStructureStability[4]; // ���� �����, �� ��� ����
	float Fuel[4]; // ����� �������

	float CurrentHull;
	float CurrentShield;
	float CurrentFuel;
	
	float HullPercent;
};