#include "module-info.h"

void DrawModuleInfoBox(ModuleItem * module, int x, int y)
{
	if (module == NULL)
	{
		Log("Error! Item was NULL");
		return;
	}

	itemInfoBoxBackground->setPosition(x, y);
	g_wnd->draw(*itemInfoBoxBackground);

	switch (module->type)
	{
	case moduleTypeSys:
	{

		SystemModuleItem * q = static_cast<SystemModuleItem*>(module);
		int captionSize = std::max(20, int(32.f / (float(q->nameLine.size()) / 80.f + 1.f)));
		//int captionSize = 32 / (40 / 40 + 1);
		s_text->setCharacterSize(captionSize);
		//s_text->setColor(sf::Color::Yellow);
		switch (q->rare)
		{
		case 0:
		case 1:
			s_text->setColor(sf::Color::White);
			break;
		case 2:
		case 3:
			s_text->setColor(sf::Color(32, 92, 255, 255));
			break;
		case 4:
		case 5:
			s_text->setColor(sf::Color(255, 215, 0, 255));
			break;
		case 6:
		case 7:
			s_text->setColor(sf::Color(32, 255, 32, 255));
			break;
		case 8:
		case 9:
			s_text->setColor(sf::Color(197, 0, 127, 255));
			break;
		case 10:
			s_text->setColor(sf::Color::Cyan);
			break;
		default:
			break;
		}
		s_text->outTextXY(x + 160, y + 10, q->nameLine);
		if (q->image != NULL)
		{
			q->image->setPosition(x + 10, y + 10);
			q->image->draw();
		}
		s_text->setCharacterSize(16);
		std::stringstream ss;

		s_text->setColor(sf::Color::White);

		s_text->outTextXY(x + 160, y + 56, "Level: " + std::to_string(q->lvl));
		s_text->outTextXY(x + 256, y + 56, "Rarity: " + std::to_string(q->rare));
		auto qq = q->slot;

		switch (qq)
		{
		case slot_Core:
			s_text->outTextXY(x + 160, y + 92, "Module type: Reactor");
			break;
		case slot_Engine:
			s_text->outTextXY(x + 160, y + 92, "Module type: Engine");
			break;
		case slot_HyperDrive:
			s_text->outTextXY(x + 160, y + 92, "Module type: Hyperdrive Core");
			break;
		case slot_System:
			s_text->outTextXY(x + 160, y + 92, "Module type: System Core");
			break;
		case slot_MainWeapon:
			s_text->outTextXY(x + 160, y + 92, "Module type: Primary Weapon");
			break;
		case slot_SubWeapon:
			s_text->outTextXY(x + 160, y + 92, "Module type: Secondary Weapon");
			break;
		case slot_Universal:
		{
			auto qq2 = q->subType;
			switch (qq2)
			{
			case class_Null:
				Log("Error! Subclass was NULL");
				return;
				break;
			case class_ShieldGenerator:
				s_text->outTextXY(x + 160, y + 92, "Module type: Shield Generator (Universal)");
				break;
			case class_Sensor:
				s_text->outTextXY(x + 160, y + 92, "Module type: Sensor (Universal)");
				break;
			case class_ShieldEnhancer:
				s_text->outTextXY(x + 160, y + 92, "Module type: Shield Enhancer (Universal)");
				break;
			case class_SensorEnhacer:
				s_text->outTextXY(x + 160, y + 92, "Module type: Sensor Enhancer (Universal)");
				break;
			case class_HullArmor:
				s_text->outTextXY(x + 160, y + 92, "Module type: Hull Armor Plating (Universal)");
				break;
			default:
				break;
			}

		}
		break;
		default:
			break;
		}

		ss << q->powerUsage;
		std::string s;
		ss >> s;
		s_text->outTextXY(x + 160, y + 128, "Power usage: " + s);
		//s_text->setColor(sf::Color(92,92,255,255));
		int count = 0;
		for (int i(0); i < q->effects.size(); i++)
		{
			auto e = q->effects[i];
			if (e.type == ModuleStat)
			{
				ModuleStatSubType et = static_cast<ModuleStatSubType>(e.subType);
				switch (et)
				{
				case StatPowerSupply:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << e.f1;
						ss >> s;
						if (e.f1 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Energy production +" + s);
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Energy production " + s);
						count++;
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << (e.f2 - 0) * 100;
						ss >> s;
						if (e.f2 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Energy production +" + s + "%");
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Energy production " + s + "%");
						count++;
					}
					break;
				case StatPowerUse:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << e.f1;
						ss >> s;
						if (e.f1 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Energy consumption +" + s);
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Energy consumption " + s);
						count++;
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << (e.f2 - 0) * 100;
						ss >> s;
						if (e.f2 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Energy consumptiom +" + s + "%");
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Energy consumption " + s + "%");
						count++;
					}
					break;
				case StatActionPoints:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << e.f1;
						ss >> s;
						if (e.f1 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Action points +" + s);
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Action points " + s);
						count++;
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << (e.f2 - 0) * 100;
						ss >> s;
						if (e.f2 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Action points +" + s + "%");
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Action points " + s + "%");
						count++;
					}
					break;
				case StatEvasion:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << e.f1;
						ss >> s;
						if (e.f1 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Evasion +" + s);
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Evasion " + s);
						count++;
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << (e.f2 - 0) * 100;
						ss >> s;
						if (e.f2 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Evasion +" + s + "%");
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Evasion " + s + "%");
						count++;
					}
					break;
				case StatMobility:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << e.f1;
						ss >> s;
						if (e.f1 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Mobility +" + s);
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Mobility " + s);
						count++;
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << (e.f2 - 0) * 100;
						ss >> s;
						if (e.f2 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Mobility +" + s + "%");
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Mobility " + s + "%");
						count++;
					}
					break;
				case StatStealth:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << e.f1;
						ss >> s;
						if (e.f1 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Stealth +" + s);
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Stealth " + s);
						count++;
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << (e.f2 - 0) * 100;
						ss >> s;
						if (e.f2 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Stealth +" + s + "%");
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Stealth " + s + "%");
						count++;
					}
					break;
				case StatStealthTier:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << e.f1;
						ss >> s;
						if (e.f1 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Stealth tier +" + s);
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Stealth tier " + s);
						count++;
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << (e.f2 - 0) * 100;
						ss >> s;
						if (e.f2 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Stealth tier +" + s + "%");
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Stealth tier " + s + "%");
						count++;
					}
					break;
				case StatSensorPower:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << e.f1;
						ss >> s;
						if (e.f1 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Sensor power +" + s);
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Stealth power " + s);
						count++;
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << (e.f2 - 0) * 100;
						ss >> s;
						if (e.f2 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Stealth power +" + s + "%");
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Stealth power " + s + "%");
						count++;
					}
					break;
				case StatSensorTier:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << e.f1;
						ss >> s;
						if (e.f1 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Sensor tier +" + s);
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Stealth tier " + s);
						count++;
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << (e.f2 - 0) * 100;
						ss >> s;
						if (e.f2 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Stealth tier +" + s + "%");
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Stealth tier " + s + "%");
						count++;
					}
					break;
				case StatHyperDriveSpeed:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << e.f1;
						ss >> s;
						if (e.f1 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hyperdrive speed +" + s);
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hyperdrive speed " + s);
						count++;
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << (e.f2 - 0) * 100;
						ss >> s;
						if (e.f2 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hyperdrive speed +" + s + "%");
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hyperdrive speed " + s + "%");
						count++;
					}
					break;
				case StatHyperDriveTier:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << e.f1;
						ss >> s;
						if (e.f1 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hyperdrive tier +" + s);
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hyperdrive tier " + s);
						count++;
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << (e.f2 - 0) * 100;
						ss >> s;
						if (e.f2 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hyperdrive tier +" + s + "%");
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hyperdrive tier " + s + "%");
						count++;
					}
					break;
				case StatHyperDriveFuelCost:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << e.f1;
						ss >> s;
						if (e.f1 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hyperdrive fuel cost +" + s);
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hyperdrive fuel cost " + s);
						count++;
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << (e.f2 - 0) * 100;
						ss >> s;
						if (e.f2 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hyperdrive fuel cost +" + s + "%");
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hyperdrive cost " + s + "%");
						count++;
					}
					break;
				case StatHull:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << e.f1;
						ss >> s;
						if (e.f1 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hull +" + s);
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hull " + s);
						count++;
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << (e.f2 - 0) * 100;
						ss >> s;
						if (e.f2 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hull +" + s + "%");
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hull " + s + "%");
						count++;
					}
					break;
				case StatHullResist:
				{
					std::string armType = "";
					switch (e.i1)
					{
					case physical:
						armType = "Physical";
						break;
					case energy:
						armType = "Energy";
						break;
					default:
						break;
					}
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << e.f1;
						ss >> s;
						if (e.f1 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hull " + armType + " Resist +" + s);
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hull " + armType + " Resist " + s);
						count++;
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << (e.f2 - 0) * 100;
						ss >> s;
						if (e.f2 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hull " + armType + " Resist +" + s + "%");
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hull " + armType + " Resist " + s + "%");
						count++;
					}
					break;
				}
				case StatHullReg:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << e.f1;
						ss >> s;
						if (e.f1 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hull Regeneration +" + s);
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hull Regeneration " + s);
						count++;
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << (e.f2 - 0) * 100;
						ss >> s;
						if (e.f2 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hull Regeneration +" + s + "%");
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hull Regeneration " + s + "%");
						count++;
					}
					break;
				case StatShield:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << e.f1;
						ss >> s;
						if (e.f1 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Shield +" + s);
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Shield " + s);
						count++;
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << (e.f2 - 0) * 100;
						ss >> s;
						if (e.f2 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Shield +" + s + "%");
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Shield " + s + "%");
						count++;
					}
					break;
				case StatShieldResist:
				{
					std::string armType = "";
					switch (e.i1)
					{
					case physical:
						armType = "Physical";
						break;
					case energy:
						armType = "Energy";
						break;
					default:
						break;
					}
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << e.f1;
						ss >> s;
						if (e.f1 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Shield " + armType + " Resist +" + s);
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Shield " + armType + " Resist " + s);
						count++;
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << (e.f2 - 0) * 100;
						ss >> s;
						if (e.f2 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Shield " + armType + " Resist +" + s + "%");
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Shield " + armType + " Resist " + s + "%");
						count++;
					}
					break;
				}
				case StatShieldReg:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << e.f1;
						ss >> s;
						if (e.f1 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Shield Regeneration +" + s);
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Shield Regeneration " + s);
						count++;
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << (e.f2 - 0) * 100;
						ss >> s;
						if (e.f2 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Shield Regeneration +" + s + "%");
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Shield Regeneration " + s + "%");
						count++;
					}
					break;
				case StatMissileDefense:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << e.f1;
						ss >> s;
						if (e.f1 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Missle Defence Power +" + s);
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Missle Defence Power " + s);
						count++;
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << (e.f2 - 0) * 100;
						ss >> s;
						if (e.f2 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Missle Defence Power +" + s + "%");
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Shield Defence Power " + s + "%");
						count++;
					}
					break;
				case StatMissileDefenseTier:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << e.f1;
						ss >> s;
						if (e.f1 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Missle Defence Tier +" + s);
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Missle Defence Tier " + s);
						count++;
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << (e.f2 - 0) * 100;
						ss >> s;
						if (e.f2 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Missle Defence Tier +" + s + "%");
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Shield Defence Tier " + s + "%");
						count++;
					}
					break;
				case StatHullStructureStability:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << e.f1;
						ss >> s;
						if (e.f1 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hull Critical Damage Resistance +" + s);
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hull Critical Damage Resistance " + s);
						count++;
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << (e.f2 - 0) * 100;
						ss >> s;
						if (e.f2 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hull Critical Damage Resistance +" + s + "%");
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Hull Critical Damage Resistance " + s + "%");
						count++;
					}
					break;
				case StatShieldStructureStability:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << e.f1;
						ss >> s;
						if (e.f1 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Shield Critical Damage Resistance +" + s);
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Shield Critical Damage Resistance " + s);
						count++;
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						ss.clear();
						ss << (e.f2 - 0) * 100;
						ss >> s;
						if (e.f2 > 0)
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Shield Critical Damage Resistance +" + s + "%");
						else
							s_text->outTextXY(x + 25, y + 174 + 36 * count, "Shield Critical Damage Resistance " + s + "%");
						count++;
					}
					break;
				default:
					break;
				}
			}
		}
	}
	break;
	case moduleTypeWeapon:
	{
		WeaponModuleItem * q = static_cast<WeaponModuleItem*>(module);
		int captionSize = std::max(20, int(32.f / (float(q->nameLine.size()) / 80.f + 1.f)));
		//int captionSize = 32 / (40 / 40 + 1);
		s_text->setCharacterSize(captionSize);
		//s_text->setColor(sf::Color::Yellow);
		switch (q->rare)
		{
		case 0:
		case 1:
			s_text->setColor(sf::Color::White);
			break;
		case 2:
		case 3:
			s_text->setColor(sf::Color(32, 92, 255, 255));
			break;
		case 4:
		case 5:
			s_text->setColor(sf::Color(255, 215, 0, 255));
			break;
		case 6:
		case 7:
			s_text->setColor(sf::Color(32, 255, 32, 255));
			break;
		case 8:
		case 9:
			s_text->setColor(sf::Color(197, 0, 127, 255));
			break;
		case 10:
			s_text->setColor(sf::Color::Cyan);
			break;
		default:
			break;
		}
		s_text->outTextXY(x + 160, y + 10, q->nameLine);
		if (q->image != NULL)
		{
			q->image->setPosition(x + 10, y + 10);
			q->image->draw();
		}
		s_text->setCharacterSize(16);
		std::stringstream ss;

		s_text->setColor(sf::Color::White);

		s_text->outTextXY(x + 160, y + 56, "Level: " + std::to_string(q->lvl));
		s_text->outTextXY(x + 256, y + 56, "Rarity: " + std::to_string(q->rare));

		auto weaponDamageType = q->damageType;
		switch (weaponDamageType)
		{
		case damage_null:
			Log("Error! Damage type was NULL");
			return;
			break;
		case physical:
			s_text->outTextXY(x + 352, y + 56, "Weapon Type: Kinetic");
			break;
		case energy:
			s_text->outTextXY(x + 352, y + 56, "Weapon Type: Energy");
			break;
		default:
			break;
		}

		auto weaponSlot = q->slot;

		switch (weaponSlot)
		{

		case slot_MainWeapon:
			{
				auto weaponSlotType = q->subType;
				switch (weaponSlotType)
				{
				case class_Null:
					Log("Error! Subclass was NULL");
					return;
					break;
				case class_HeavyPlasmaCannon:
					s_text->outTextXY(x + 160, y + 92, "Module type: Heavy Plasma Cannon (Primary)");
					break;
				case class_MedGauss:
					s_text->outTextXY(x + 160, y + 92, "Module type: Medium Gauss Cannon (Primary)");
					break;
				default:
					break;
				}

			}
			break;
		case slot_SubWeapon:
			{
				auto weaponSlotType = q->subType;
				switch (weaponSlotType)
				{
				case class_Null:
					Log("Error! Subclass was NULL");
					return;
					break;
				case class_lightMissile:
					s_text->outTextXY(x + 160, y + 92, "Module type: Light Missile (Secondary)");
					break;
				case class_lightTorpedo:
					s_text->outTextXY(x + 160, y + 92, "Module type: Light Torpedo (Secondary)");
					break;
				default:
					break;
				}

			}
			break;
		}

		std::string s;
		std::string damageStr = "Damage: ";
		std::string accuracyStr = "Accuracy: ";
		std::string pierceStr = "Pierce: ";
		std::string critHullStr = "Hull Crit: ";
		std::string critShieldStr = "Shield Crit: ";

		s = floatToString(q->powerUsage);
		s_text->outTextXY(x + 160, y + 128, "Power usage: " + s);
		s.clear();

		s = floatToString(q->ActivationCost);
		int count = 0;
		s_text->outTextXY(x + 320, y + 128, "Activation Cost: " + s);
		s.clear();

		s = floatToString(q->baseDamage);
		damageStr += s;
		s.clear();

		auto weaponTextDamageType = q->damageType;
		switch (weaponTextDamageType)
		{
		case physical:
			s = "physical (";
			damageStr += " " + s;
			break;
		case energy:
			s = "energy (";
			damageStr += " " + s;
			break;
		default:
			break;
		}
		s.clear();

		s = floatToString(q->damageMaxCells);
		damageStr += s + " cells, ";
		s.clear();
		s = floatToString((q->damageLosePerCell)*100);
		damageStr += "-" + s + "%)";
		s.clear();
		s_text->outTextXY(x + 25, y + 190 + 36 * count, damageStr);
		count++;

		s = floatToString(q->baseAccuracy);
		accuracyStr += s + " (";
		s.clear();
		s = floatToString(q->accuracyMaxCells);
		accuracyStr += s + " cells, ";
		s.clear();
		s = floatToString((q->accuracyLosePerCell)*100);
		accuracyStr += "-" + s + "%)";
		s.clear();
		s_text->outTextXY(x + 25, y + 190 + 36 * count, accuracyStr);
		count++;

		s = floatToString(q->armorPierce[0]);
		pierceStr += s + "/";
		s.clear();
		s = floatToString(q->armorPierce[1]);
		pierceStr += s + " (Hull/Shield)";
		s.clear();
		s_text->outTextXY(x + 25, y + 190 + 36 * count, pierceStr);
		count++;

		s = floatToString((q->critChanceHull)*100);
		critHullStr += s + "% (";
		s.clear();
		s = floatToString((q->critDamageHull)*100);
		critHullStr += s + "% damage) -> ";
		s.clear();
		s_text->outTextXY(x + 25, y + 190 + 36 * count, critHullStr);
		count++;

		s = floatToString((q->critChanceShield) * 100);
		critShieldStr += s + "% (";
		s.clear();
		s = floatToString((q->critDamageShield)*100);
		critShieldStr += s + "% damage) -> ";
		s.clear();
		s_text->outTextXY(x + 25, y + 190 + 36 * count, critShieldStr);
		count++;

	}
		break;
	default:
		Log("Error! Undefined module type.");
		break;
	}
}

