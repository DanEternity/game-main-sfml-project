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
	// и другие
};

enum gameMenuSubState
{
	subStateNull,
	optionsNormal,
	optionsWindowed,
	statscontext
	// и другие
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

enum DamageType
{
	phisycal,
	energy
};

enum EffectType
{
	// note that not all effects can be applied to all objects
	EffectTypeNull // if empty
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