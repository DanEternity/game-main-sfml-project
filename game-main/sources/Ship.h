#pragma once

#include "game-enviroment.h"
#include "Consts.h"

class Ship
{
public:
	Ship();

	float PowerSupply; // ����������� �������
	float PowerUse; // ��������� �������
	float ActionPoints; // ���� �������� (� ���)
	float Evasion; // ������� ��������� (����� ���� ������������� (?))
	float Mobility; // ������� ������������� (������� ��������� ��������)
	float Stealth; // ���������� �������
	float StealthTier; // ���������� ����������� ������� �������� ��� ��������� ������ � ���� (��, ���, ������ � �.�.)
	float SensorPower; // �������� ��������
	float SensorTier; // ������� ��������
	float HyperDriveSpeed; // ���. �������� �������� ������� (�� ����� �� ���� �� ������, �� ���-�� ����� ���� ������. �������� ������������ ������� �� ����)
	float HyperDriveTier; // ����� �������������� (���������� ����������� ����������� � ��������� ����
	float HyperDriveFuelCost; // ��������� ������ / ��� ����������� ��������� ������ (������ ����� ������)
	float Hull; // ��������� �������
	float HullResist[HullResistN]; // ������ �������
	float HullReg; // ���� ����� ������� ����� ���������� ������, ��������� ����� ������ ����� ������������ ���
	float Shield; // ������� ����
	float ShieldResist[ShieldResistN]; // ������ ���� 
	float ShieldReg; // ����������� ����
					// ����� �� ��������� =)
	float MissileDefense; // ������� ������� ���
	float MissileDefenseTier; // ������� ������� ���
	float HullStructureStability; // ���������������� ������������ �����(�����, � �� ����� �����)
	float ShieldStructureStability; // ���� �����, �� ��� ����

};