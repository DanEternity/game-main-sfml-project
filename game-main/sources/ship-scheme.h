#pragma once

#include "custom-types.h"
#include "modules.h"

struct QShipSlotCell
{
	ModuleItem* m;
	ModuleSlot s;
	int x;
	int y;
	QShipSlotCell()
	{
		m = NULL;
		s = slot_Universal;
		x = 0;
		y = 0;
	}
};

class ShipScheme
{
public:
	std::vector<QShipSlotCell> slots;
	// ����������� ��������� ������ � �������
	// ����� ����������� �����
	
	float powerProduced;
	float powerUsed;
	float powerFree;

	/* Base stats for ship type */

	//float PowerSupply; // ����������� ������� !dublicate
	//float PowerUse; // ��������� ������� !dublicate
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

	float MissileDefense; // ������� ������� ���
	float MissileDefenseTier; // ������� ������� ���
	float HullStructureStability; // ���������������� ������������ �����(�����, � �� ����� �����)
	float ShieldStructureStability; // ���� �����, �� ��� ����

	void create(int scremeID);
	bool checkSlotComp(ModuleItem * module, int slot_id);
	void setModule(ModuleItem * module, int slot_id);

private:
	void schemeDebug();
private:

};