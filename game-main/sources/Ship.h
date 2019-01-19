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

	float PowerSupply[3]; // ����������� �������
	float PowerUse[3]; // ��������� �������
	float ActionPoints[3]; // ���� �������� (� ���)
	float Evasion[3]; // ������� ��������� (����� ���� ������������� (?))
	float Mobility[3]; // ������� ������������� (������� ��������� ��������)
	float Stealth[3]; // ���������� �������
	float StealthTier[3]; // ���������� ����������� ������� �������� ��� ��������� ������ � ���� (��, ���, ������ � �.�.)
	float SensorPower[3]; // �������� ��������
	float SensorTier[3]; // ������� ��������
	float HyperDriveSpeed[3]; // ���. �������� �������� ������� (�� ����� �� ���� �� ������, �� ���-�� ����� ���� ������. �������� ������������ ������� �� ����)
	float HyperDriveTier[3]; // ����� �������������� (���������� ����������� ����������� � ��������� ����
	float HyperDriveFuelCost[3]; // ��������� ������ / ��� ����������� ��������� ������ (������ ����� ������)
	float Hull[3]; // ��������� �������
	float HullResist[HullResistN][3]; // ������ �������
	float HullReg[3]; // ���� ����� ������� ����� ���������� ������, ��������� ����� ������ ����� ������������ ���
	float Shield[3]; // ������� ����
	float ShieldResist[ShieldResistN][3]; // ������ ���� 
	float ShieldReg[3]; // ����������� ����

					// ����� �� ��������� =)
	float MissileDefense[3]; // ������� ������� ���
	float MissileDefenseTier[3]; // ������� ������� ���
	float HullStructureStability[3]; // ���������������� ������������ �����(�����, � �� ����� �����)
	float ShieldStructureStability[3]; // ���� �����, �� ��� ����

};