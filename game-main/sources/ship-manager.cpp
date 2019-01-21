#include "ship-manager.h"

void ShipManager::clearStats()
{
	/* mod stats */

	 ship->PowerSupply[1] = 0; // ����������� �������
	 ship->PowerUse[1] = 0; // ��������� �������
	 ship->ActionPoints[1] = 0; // ���� �������� (� ���)
	 ship->Evasion[1] = 0; // ������� ��������� (����� ���� ������������� (?))
	 ship->Mobility[1] = 0; // ������� ������������� (������� ��������� ��������)
	 ship->Stealth[1] = 0; // ���������� �������
	 ship->StealthTier[1] = 0; // ���������� ����������� ������� �������� ��� ��������� ������ � ���� (��, ���, ������ � �.�.)
	 ship->SensorPower[1] = 0; // �������� ��������
	 ship->SensorTier[1] = 0; // ������� ��������
	 ship->HyperDriveSpeed[1] = 0; // ���. �������� �������� ������� (�� ����� �� ���� �� ������, �� ���-�� ����� ���� ������. �������� ������������ ������� �� ����)
	 ship->HyperDriveTier[1] = 0; // ����� �������������� (���������� ����������� ����������� � ��������� ����
	 ship->HyperDriveFuelCost[1] = 0; // ��������� ������ / ��� ����������� ��������� ������ (������ ����� ������)
	 ship->Hull[1] = 0; // ��������� �������
	 
	 ship->HullReg[1] = 0; // ���� ����� ������� ����� ���������� ������, ��������� ����� ������ ����� ������������ ���
	 ship->Shield[1] = 0; // ������� ����
	 for (int i(0); i < ArmorTypesCount; i++)
	 {
		 ship->HullResist[i][1] = 0; // ������ �������
		 ship->ShieldResist[i][1] = 0; // ������ ���� 
	 }
	 ship->ShieldReg[1] = 0; // ����������� ����

	 ship->MissileDefense[1] = 0; // ������� ������� ���
	 ship->MissileDefenseTier[1] = 0; // ������� ������� ���
	 ship->HullStructureStability[1] = 0; // ���������������� ������������ �����(�����, � �� ����� �����)
	 ship->ShieldStructureStability[1] = 0; // ���� �����, �� ��� ����

	 /* mod % */

	 ship->PowerSupply[2] = 1; // ����������� �������
	 ship->PowerUse[2] = 1; // ��������� �������
	 ship->ActionPoints[2] = 1; // ���� �������� (� ���)
	 ship->Evasion[2] = 1; // ������� ��������� (����� ���� ������������� (?))
	 ship->Mobility[2] = 1; // ������� ������������� (������� ��������� ��������)
	 ship->Stealth[2] = 1; // ���������� �������
	 ship->StealthTier[2] = 1; // ���������� ����������� ������� �������� ��� ��������� ������ � ���� (��, ���, ������ � �.�.)
	 ship->SensorPower[2] = 1; // �������� ��������
	 ship->SensorTier[2] = 1; // ������� ��������
	 ship->HyperDriveSpeed[2] = 1; // ���. �������� �������� ������� (�� ����� �� ���� �� ������, �� ���-�� ����� ���� ������. �������� ������������ ������� �� ����)
	 ship->HyperDriveTier[2] = 1; // ����� �������������� (���������� ����������� ����������� � ��������� ����
	 ship->HyperDriveFuelCost[2] = 1; // ��������� ������ / ��� ����������� ��������� ������ (������ ����� ������)
	 ship->Hull[2] = 1; // ��������� �������

	 ship->HullReg[2] = 1; // ���� ����� ������� ����� ���������� ������, ��������� ����� ������ ����� ������������ ���
	 ship->Shield[2] = 1; // ������� ����
	 for (int i(0); i < ArmorTypesCount; i++)
	 {
		 ship->HullResist[i][2] = 1; // ������ �������
		 ship->ShieldResist[i][2] = 1; // ������ ���� 
	 }
	 ship->ShieldReg[2] = 1; // ����������� ����

	 ship->MissileDefense[2] = 1; // ������� ������� ���
	 ship->MissileDefenseTier[2] = 1; // ������� ������� ���
	 ship->HullStructureStability[2] = 1; // ���������������� ������������ �����(�����, � �� ����� �����)
	 ship->ShieldStructureStability[2] = 1; // ���� �����, �� ��� ����

	 /* battle stats */

	 ship->PowerSupply[3] = 0; // ����������� �������
	 ship->PowerUse[3] = 0; // ��������� �������
	 ship->ActionPoints[3] = 0; // ���� �������� (� ���)
	 ship->Evasion[3] = 0; // ������� ��������� (����� ���� ������������� (?))
	 ship->Mobility[3] = 0; // ������� ������������� (������� ��������� ��������)
	 ship->Stealth[3] = 0; // ���������� �������
	 ship->StealthTier[3] = 0; // ���������� ����������� ������� �������� ��� ��������� ������ � ���� (��, ���, ������ � �.�.)
	 ship->SensorPower[3] = 0; // �������� ��������
	 ship->SensorTier[3] = 0; // ������� ��������
	 ship->HyperDriveSpeed[3] = 0; // ���. �������� �������� ������� (�� ����� �� ���� �� ������, �� ���-�� ����� ���� ������. �������� ������������ ������� �� ����)
	 ship->HyperDriveTier[3] = 0; // ����� �������������� (���������� ����������� ����������� � ��������� ����
	 ship->HyperDriveFuelCost[3] = 0; // ��������� ������ / ��� ����������� ��������� ������ (������ ����� ������)
	 ship->Hull[3] = 0; // ��������� �������

	 ship->HullReg[3] = 0; // ���� ����� ������� ����� ���������� ������, ��������� ����� ������ ����� ������������ ���
	 ship->Shield[3] = 0; // ������� ����
	 for (int i(0); i < ArmorTypesCount; i++)
	 {
		 ship->HullResist[i][3] = 0; // ������ �������
		 ship->ShieldResist[i][3] = 0; // ������ ���� 
	 }
	 ship->ShieldReg[3] = 0; // ����������� ����

	 ship->MissileDefense[3] = 0; // ������� ������� ���
	 ship->MissileDefenseTier[3] = 0; // ������� ������� ���
	 ship->HullStructureStability[3] = 0; // ���������������� ������������ �����(�����, � �� ����� �����)
	 ship->ShieldStructureStability[3] = 0; // ���� �����, �� ��� ����

}

void ShipManager::updateStats()
{
	Log("Updating ship values... ");
	/* Nullify all stats */
	clearStats();

	for (int i(0); i < scheme->slots.size(); i++)
	{
		if (scheme->slots[i].m != NULL)
		{
			auto mType = scheme->slots[i].m->type;
			if (mType == moduleTypeSys)
			{
				SystemModuleItem *m = (SystemModuleItem*)(scheme->slots[i].m);
				for (int j(0); j < m->effects.size(); j++)
				{
					applyEffect(&m->effects[j]);
				}
			}
		}
	}

	ship->PowerSupply[3] = (ship->PowerSupply[0] + ship->PowerSupply[1]) * ship->PowerSupply[2]; 
	ship->PowerUse[3] = (ship->PowerUse[0] + ship->PowerUse[1]) * ship->PowerUse[2]; 
	ship->ActionPoints[3] = (ship->ActionPoints[0] + ship->ActionPoints[1]) * ship->ActionPoints[2]; 
	ship->Evasion[3] = (ship->Evasion[0] + ship->Evasion[1]) * ship->Evasion[2];
	ship->Mobility[3] = (ship->Mobility[0] + ship->Mobility[1]) * ship->Mobility[2]; 
	ship->Stealth[3] = (ship->Stealth[0] + ship->Stealth[1]) * ship->Stealth[2]; 
	ship->StealthTier[3] = (ship->StealthTier[0] + ship->StealthTier[1]) * ship->StealthTier[2]; 
	ship->SensorPower[3] = (ship->SensorPower[0] + ship->SensorPower[1]) * ship->SensorPower[2]; 
	ship->SensorTier[3] = (ship->SensorTier[0] + ship->SensorTier[1]) * ship->SensorTier[2]; 
	ship->HyperDriveSpeed[3] = (ship->HyperDriveSpeed[0] + ship->HyperDriveSpeed[1]) * ship->HyperDriveSpeed[2]; 
	ship->HyperDriveTier[3] = (ship->HyperDriveTier[0] + ship->HyperDriveTier[1]) * ship->HyperDriveTier[2]; 
	ship->HyperDriveFuelCost[3] = (ship->HyperDriveFuelCost[0] + ship->HyperDriveFuelCost[1]) * ship->HyperDriveFuelCost[2]; 
	ship->Hull[3] = (ship->Hull[0] + ship->Hull[1]) * ship->Hull[2]; // ��������� �������
	for (int i(0); i < ArmorTypesCount; i++)
	{
		ship->HullResist[i][3] = (ship->HullResist[i][0] + ship->HullResist[i][1]) * ship->HullResist[i][2]; // ������ �������
		ship->ShieldResist[i][3] = (ship->ShieldResist[i][0] + ship->ShieldResist[i][1]) * ship->ShieldResist[i][2]; // ������ ���� 
	}
	ship->HullReg[3] = (ship->HullReg[0] + ship->HullReg[1]) * ship->HullReg[2]; 
	ship->Shield[3] = (ship->Shield[0] + ship->Shield[1]) * ship->Shield[2]; // ������� ����
	ship->ShieldReg[3] = (ship->ShieldReg[0] + ship->ShieldReg[1]) * ship->ShieldReg[2]; // ����������� ����
	ship->MissileDefense[3] = (ship->MissileDefense[0] + ship->MissileDefense[1]) 
		* ship->MissileDefense[2]; // ������� ������� ���
	ship->MissileDefenseTier[3] = (ship->MissileDefenseTier[0] + ship->MissileDefenseTier[1]) 
		* ship->MissileDefenseTier[2]; // ������� ������� ���
	ship->HullStructureStability[3] = (ship->HullStructureStability[0] + ship->HullStructureStability[1]) 
		* ship->HullStructureStability[2]; // ���������������� ������������ �����(�����, � �� ����� �����)
	ship->ShieldStructureStability[3] = (ship->ShieldStructureStability[0] + ship->ShieldStructureStability[1]) 
		* ship->ShieldStructureStability[2]; // ���� �����, �� ��� ����

}

void ShipManager::applyEffect(LocalEffect * effect)
{
	auto type = effect->type;
	switch (type)
	{
	case EffectTypeNull:
		Log("Error! Effect was EffectTypeNULL!");
		break;
	case ModuleStat:
		applyModuleStatEffect(effect);
		break;
	default:
		Log("Error. Cant apply effect");
		break;
	}
}

void ShipManager::applyModuleStatEffect(LocalEffect * effect)
{
	if (effect->type != ModuleStat)
	{
		Log("Error. Wrong effect type");
		return;
	}
	ModuleStatSubType type = static_cast<ModuleStatSubType>(effect->subType);

	switch (type)
	{
	case StatPowerSupply:
		ship->PowerSupply[QMod] += effect->f1;
		ship->PowerSupply[QModPercent] += effect->f2;
		break;
	case StatPowerUse:
		ship->PowerUse[QMod] += effect->f1;
		ship->PowerUse[QModPercent] += effect->f2;
		break;
	case StatActionPoints:
		ship->ActionPoints[QMod] += effect->f1;
		ship->ActionPoints[QModPercent] += effect->f2;
		break;
	case StatEvasion:
		ship->Evasion[QMod] += effect->f1;
		ship->Evasion[QModPercent] += effect->f2;
		break;
	case StatMobility:
		ship->Mobility[QMod] += effect->f1;
		ship->Mobility[QModPercent] += effect->f2;
		break;
	case StatStealth:
		ship->Stealth[QMod] += effect->f1;
		ship->Stealth[QModPercent] += effect->f2;
		break;
	case StatStealthTier:
		ship->StealthTier[QMod] += effect->f1;
		ship->StealthTier[QModPercent] += effect->f2;
		break;
	case StatSensorPower:
		ship->SensorPower[QMod] += effect->f1;
		ship->SensorPower[QModPercent] += effect->f2;
		break;
	case StatSensorTier:
		ship->SensorTier[QMod] += effect->f1;
		ship->SensorTier[QModPercent] += effect->f2;
		break;
	case StatHyperDriveSpeed:
		ship->HyperDriveSpeed[QMod] += effect->f1;
		ship->HyperDriveSpeed[QModPercent] += effect->f2;
		break;
	case StatHyperDriveTier:
		ship->HyperDriveTier[QMod] += effect->f1;
		ship->HyperDriveTier[QModPercent] += effect->f2;
		break;
	case StatHyperDriveFuelCost:
		ship->HyperDriveFuelCost[QMod] += effect->f1;
		ship->HyperDriveFuelCost[QModPercent] += effect->f2;
		break;
	case StatHull:
		ship->Hull[QMod] += effect->f1;
		ship->Hull[QModPercent] += effect->f2;
		break;
	case StatHullResist:
		ship->HullResist[effect->i1][QMod] += effect->f1;
		ship->HullResist[effect->i1][QModPercent] += effect->f2;
		break;
	case StatHullReg:
		ship->HullReg[QMod] += effect->f1;
		ship->HullReg[QModPercent] += effect->f2;
		break;
	case StatShield:
		ship->Shield[QMod] += effect->f1;
		ship->Shield[QModPercent] += effect->f2;
		break;
	case StatShieldResist:
		ship->ShieldResist[effect->i1][QMod] += effect->f1;
		ship->ShieldResist[effect->i1][QModPercent] += effect->f2;
		break;
	case StatShieldReg:
		ship->ShieldReg[QMod] += effect->f1;
		ship->ShieldReg[QModPercent] += effect->f2;
		break;
	case StatMissileDefense:
		ship->MissileDefense[QMod] += effect->f1;
		ship->MissileDefense[QModPercent] += effect->f2;
		break;
	case StatMissileDefenseTier:
		ship->MissileDefenseTier[QMod] += effect->f1;
		ship->MissileDefenseTier[QModPercent] += effect->f2;
		break;
	case StatHullStructureStability:
		ship->HullStructureStability[QMod] += effect->f1;
		ship->HullStructureStability[QModPercent] += effect->f2;
		break;
	case StatShieldStructureStability:
		ship->ShieldStructureStability[QMod] += effect->f1;
		ship->ShieldStructureStability[QModPercent] += effect->f2;
		break;
	default: 
		Log("Error! Wrong type of module stat.");
		break;
	}
}

void ShipManager::init(ShipScheme * qScheme)
{
	scheme = qScheme;

	ship->PowerSupply[0] = 0; // ����������� �������
	ship->PowerUse[0] = 0; // ��������� �������
	ship->ActionPoints[0] = scheme->ActionPoints; // ���� �������� (� ���)
	ship->Evasion[0] = scheme->Evasion; // ������� ��������� (����� ���� ������������� (?))
	ship->Mobility[0] = scheme->Mobility; // ������� ������������� (������� ��������� ��������)
	ship->Stealth[0] = scheme->Stealth; // ���������� �������
	ship->StealthTier[0] = scheme->StealthTier; // ���������� ����������� ������� �������� ��� ��������� ������ � ���� (��, ���, ������ � �.�.)
	ship->SensorPower[0] = scheme->SensorPower; // �������� ��������
	ship->SensorTier[0] = scheme->SensorTier; // ������� ��������
	ship->HyperDriveSpeed[0] = scheme->HyperDriveSpeed; // ���. �������� �������� ������� (�� ����� �� ���� �� ������, �� ���-�� ����� ���� ������. �������� ������������ ������� �� ����)
	ship->HyperDriveTier[0] = scheme->HyperDriveTier; // ����� �������������� (���������� ����������� ����������� � ��������� ����
	ship->HyperDriveFuelCost[0] = scheme->HyperDriveFuelCost; // ��������� ������ / ��� ����������� ��������� ������ (������ ����� ������)
	ship->Hull[0] = scheme->Hull; // ��������� �������
	for (int i(0); i < ArmorTypesCount; i++)
	{
		ship->HullResist[i][0] = scheme->HullResist[i]; // ������ �������
		ship->ShieldResist[i][0] = scheme->ShieldResist[i]; // ������ ���� 
	} 
	ship->HullReg[0] = scheme->HullReg; // ���� ����� ������� ����� ���������� ������, ��������� ����� ������ ����� ������������ ���
	ship->Shield[0] = scheme->Shield; // ������� ����
	ship->ShieldReg[0] = scheme->ShieldReg; // ����������� ����
	ship->MissileDefense[0] = scheme->MissileDefense; // ������� ������� ���
	ship->MissileDefenseTier[0] = scheme->MissileDefenseTier; // ������� ������� ���
	ship->HullStructureStability[0] = scheme->HullStructureStability; // ���������������� ������������ �����(�����, � �� ����� �����)
	ship->ShieldStructureStability[0] = scheme->ShieldStructureStability; // ���� �����, �� ��� ����
}

void ShipManager::debug()
{
	
}

