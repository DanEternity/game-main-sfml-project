#pragma once

enum UIElementType
{
	base,
	image,
	text,
	collection,
	button
};

enum BaseUIElemFormType
{
	circle,
	square
};

enum UIEventType
{
	onPress,
	onRelease,
	onHoverBegin,
	onHoverEnd
};

enum UIEventFuncResult
{

};

class BaseUIElem;

struct UIEventData
{
	UIEventType eventType;
	int mouse_x;
	int mouse_y;
	bool mouse_bt_l;
	bool mouse_bt_r;

	bool mouse_change_l;
	bool mouse_change_r;

	int objectID;
	BaseUIElem * ref;
};

typedef void(*func_pointer_void_void)(); // no return no parameters
typedef void(*func_pointer_void_data_uiHandler)(UIEventData * data); // no return but with data

class BaseUIElem;

struct UIEventState_private
{
	BaseUIElem * p = 0;
	bool flagReg[5];
	func_pointer_void_data_uiHandler funcPointer[5];
	bool p_inside = false;

};

enum buttonState
{
	normal,
	hover,
	pressed,
	disabled
};

enum gameMenuState
{
	main_menu,
	gamesetup,
	options,
	stats
	// � ������
};

enum gameMenuSubState
{
	subStateNull,
	optionsNormal,
	optionsWindowed,
	statscontext
	// � ������
};

enum QEventType
{
	initGame,
	initGameDebug
};

struct QGlobalEvent
{
	QEventType type;
	int QtypeValue;
	__int64 QValue;
	void * extendedData;
};

enum ModuleType
{
	moduleTypeNull,
	moduleTypeWeapon,
	moduleTypeSys,
	moduleTypeExtra
};

enum ModuleSlot
{
	slot_Core,
	slot_Engine,
	slot_HyperDrive,
	slot_System,
	slot_MainWeapon,
	slot_SubWeapon,
	slot_Universal
};

enum ModuleSysSubClass
{
	class_Null,
	class_ShieldGenerator,
	class_Sensor,
	class_ShieldEnhancer,
	class_SensorEnhacer,
	class_HullArmor
};

enum ModuleWepSubClass
{
	// main weapons
	class_WepNull,
	class_HeavyPlasmaCannon,
	class_MedGauss,
	// sub weapons 
	class_lightMissile,
	class_lightTorpedo
};

enum DamageType
{
	damage_null = -1,
	physical = 0,
	energy
};

struct LandModeGameData
{

};