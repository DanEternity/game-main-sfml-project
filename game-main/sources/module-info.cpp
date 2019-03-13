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
	wpn_text->lines.clear();
	mod_eff_desc_text->lines.clear();

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
						s = floatToString(e.f1);
						if (e.f1 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Energy production +" + s);
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Energy production " + s);
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						s = floatToString((e.f2 - 0) * 100);
						if (e.f2 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Energy production +" + s + "%");
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Energy production " + s + "%");
					}
					break;
				case StatPowerUse:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						s = floatToString(e.f1);
						if (e.f1 > 0)
							mod_eff_desc_text->lines.push_back("@[color:red]Energy consumption +" + s);
						else
							mod_eff_desc_text->lines.push_back("@[color:green]Energy consumption " + s);
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						s = floatToString((e.f2 - 0) * 100);
						if (e.f2 > 0)
							mod_eff_desc_text->lines.push_back("@[color:red]Energy consumption +" + s + "%");
						else
							mod_eff_desc_text->lines.push_back("@[color:green]Energy consumption " + s + "%");
					}
					break;
				case StatActionPoints:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						s = floatToString(e.f1);
						if (e.f1 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Action points +" + s);
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Action points " + s);
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						s = floatToString((e.f2 - 0) * 100);
						if (e.f2 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Action points +" + s + "%");
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Action points " + s + "%");
					}
					break;
				case StatEvasion:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						s = floatToString(e.f1);
						if (e.f1 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Evasion +" + s);
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Evasion " + s);
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						s = floatToString((e.f2 - 0) * 100);
						if (e.f2 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Evasion +" + s + "%");
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Evasion " + s + "%");
					}
					break;
				case StatMobility:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						s = floatToString(e.f1);
						if (e.f1 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Mobility +" + s);
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Mobility " + s);
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						s = floatToString((e.f2 - 0) * 100);
						if (e.f2 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Mobility +" + s + "%");
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Mobility " + s + "%");
					}
					break;
				case StatStealth:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						s = floatToString(e.f1);
						if (e.f1 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Stealth +" + s);
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Stealth " + s);
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						s = floatToString((e.f2 - 0) * 100);
						if (e.f2 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Stealth +" + s + "%");
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Stealth " + s + "%");
					}
					break;
				case StatStealthTier:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						s = floatToString(e.f1);
						if (e.f1 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Stealth tier +" + s);
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Stealth tier " + s);
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						s = floatToString((e.f2 - 0) * 100);
						if (e.f2 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Stealth tier +" + s + "%");
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Stealth tier " + s + "%");
					}
					break;
				case StatSensorPower:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						s = floatToString(e.f1);
						if (e.f1 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Sensor power +" + s);
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Sensor power " + s);
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						s = floatToString((e.f2 - 0) * 100);
						if (e.f2 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Sensor power +" + s + "%");
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Sensor power " + s + "%");
					}
					break;
				case StatSensorTier:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						s = floatToString(e.f1);
						if (e.f1 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Sensor tier +" + s);
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Sensor tier " + s);
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						s = floatToString((e.f2 - 0) * 100);
						if (e.f2 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Sensor tier +" + s + "%");
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Sensor tier " + s + "%");
					}
					break;
				case StatHyperDriveSpeed:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						s = floatToString(e.f1);
						if (e.f1 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Hyperdrive speed +" + s);
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Hyperdrive speed " + s);
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						s = floatToString((e.f2 - 0) * 100);
						if (e.f2 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Hyperdrive speed +" + s + "%");
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Hyperdrive speed " + s + "%");
					}
					break;
				case StatHyperDriveTier:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						s = floatToString(e.f1);
						if (e.f1 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Hyperdrive tier +" + s);
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Hyperdrive tier " + s);
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						s = floatToString((e.f2 - 0) * 100);
						if (e.f2 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Hyperdrive tier +" + s + "%");
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Hyperdrive tier " + s + "%");
					}
					break;
				case StatHyperDriveFuelEfficiency:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						s = floatToString(e.f1);
						if (e.f1 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]HD Efficiency +" + s);
						else
							mod_eff_desc_text->lines.push_back("@[color:red]HD Efficiency " + s);
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						s = floatToString((e.f2 - 0) * 100);
						if (e.f2 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]HD Efficiency +" + s + "%");
						else
							mod_eff_desc_text->lines.push_back("@[color:red]HD Efficiency " + s + "%");
					}
					break;
				case StatHull:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						s = floatToString(e.f1);
						if (e.f1 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Hull +" + s);
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Hull " + s);
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						s = floatToString((e.f2 - 0) * 100);
						if (e.f2 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Hull +" + s + "%");
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Hull " + s + "%");
					}
					break;
				case StatHullResist:
				{
					std::string armType = "";
					switch (e.i1)
					{
					case physical:
						armType = "physical";
						break;
					case energy:
						armType = "energy";
						break;
					default:
						break;
					}
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						s = floatToString(e.f1);
						if (e.f1 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Hull " + armType + " resistance +" + s);
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Hull " + armType + " resistance " + s);
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						s = floatToString((e.f2 - 0) * 100);
						if (e.f2 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Hull " + armType + " resistance +" + s + "%");
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Hull " + armType + " resistance " + s + "%");
					}
					break;
				}
				case StatHullReg:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						s = floatToString(e.f1);
						if (e.f1 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Hull Reg +" + s);
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Hull Reg " + s);
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						s = floatToString((e.f2 - 0) * 100);
						if (e.f2 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Hull Reg +" + s + "%");
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Hull Reg " + s + "%");
					}
					break;
				case StatShield:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						s = floatToString(e.f1);
						if (e.f1 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Shield +" + s);
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Shield " + s);
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						s = floatToString((e.f2 - 0) * 100);
						if (e.f2 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Shield +" + s + "%");
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Shield " + s + "%");
					}
					break;
				case StatShieldResist:
				{
					std::string armType = "";
					switch (e.i1)
					{
					case physical:
						armType = "physical";
						break;
					case energy:
						armType = "energy";
						break;
					default:
						break;
					}
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						s = floatToString(e.f1);
						if (e.f1 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Shield " + armType + " resistance +" + s);
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Shield " + armType + " resistance " + s);
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						s = floatToString((e.f2 - 0) * 100);
						if (e.f2 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Shield " + armType + " resistance +" + s + "%");
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Shield " + armType + " resistance " + s + "%");
					}
					break;
				}
				case StatShieldReg:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						s = floatToString(e.f1);
						if (e.f1 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Shield Reg +" + s);
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Shield Reg " + s);
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						s = floatToString((e.f2 - 0) * 100);
						if (e.f2 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Shield Reg +" + s + "%");
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Shield Reg " + s + "%");
					}
					break;
				case StatMissileDefense:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						s = floatToString(e.f1);
						if (e.f1 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Missile Defence +" + s);
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Missile Defence " + s);
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						s = floatToString((e.f2 - 0) * 100);
						if (e.f2 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Missile Defence +" + s + "%");
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Missile Defence " + s + "%");
					}
					break;
				case StatMissileDefenseTier:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						s = floatToString(e.f1);
						if (e.f1 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Missile Defence Tier +" + s);
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Missile Defence Tier " + s);
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						s = floatToString((e.f2 - 0) * 100);
						if (e.f2 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Missile Defence Tier +" + s + "%");
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Missile Defence Tier " + s + "%");
					}
					break;
				case StatHullStructureStability:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						s = floatToString(e.f1);
						if (e.f1 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Hull Crit Resistance +" + s);
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Hull Crit Resistance " + s);
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						s = floatToString((e.f2 - 0) * 100);
						if (e.f2 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Hull Crit Resistance +" + s + "%");
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Hull Crit Resistance " + s + "%");
					}
					break;
				case StatShieldStructureStability:
					if (abs(e.f1) > 0.00001f)
					{
						s.clear();
						s = floatToString(e.f1);
						if (e.f1 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Shield Crit Resistance +" + s);
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Shield Crit Resistance " + s);
					}
					if (abs(e.f2) > 0.00001f)
					{
						s.clear();
						s = floatToString((e.f2 - 0) * 100);
						if (e.f2 > 0)
							mod_eff_desc_text->lines.push_back("@[color:green]Shield Crit Resistance +" + s + "%");
						else
							mod_eff_desc_text->lines.push_back("@[color:red]Shield Crit Resistance " + s + "%");
					}
					break;
				default:
					break;
				}
			}
		}

		mod_eff_desc_text->setPosition(x + 25, y + 174);
		mod_eff_desc_text->update();
		mod_eff_desc_text->draw();
		
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

