#pragma once

enum EffectType
{
	// note that not all effects can be applied to all objects
	EffectTypeNull, // if empty
	ModuleStat
};

enum ModuleStatSubType
{
	StatPowerSupply, // ����������� �������
	StatPowerUse, // ��������� �������
	StatActionPoints, // ���� �������� (� ���)
	StatEvasion, // ������� ��������� (����� ���� ������������� (?))
	StatMobility, // ������� ������������� (������� ��������� ��������)
	StatStealth, // ���������� �������
	StatStealthTier, // ���������� ����������� ������� �������� ��� ��������� ������ � ���� (��, ���, ������ � �.�.)
	StatSensorPower, // �������� ��������
	StatSensorTier, // ������� ��������
	StatHyperDriveSpeed, // ���. �������� �������� ������� (�� ����� �� ���� �� ������, �� ���-�� ����� ���� ������. �������� ������������ ������� �� ����)
	StatHyperDriveTier, // ����� �������������� (���������� ����������� ����������� � ��������� ����
	StatHyperDriveFuelEfficiency, // ��������� ������ / ��� ����������� ��������� ������ (������ ����� ������)
	StatHull, // ��������� �������
	StatHullResist, // ������ �������
	StatHullReg, // ���� ����� ������� ����� ���������� ������, ��������� ����� ������ ����� ������������ ���
	StatShield, // ������� ����
	StatShieldResist, // ������ ���� 
	StatShieldReg, // ����������� ����
	StatMissileDefense, // ������� ������� ���
	StatMissileDefenseTier, // ������� ������� ���
	StatHullStructureStability, // ���������������� ������������ �����(�����, � �� ����� �����)
	StatShieldStructureStability // ���� �����, �� ��� ����
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