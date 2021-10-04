#ifndef CONST_H
#define CONST_H

//This header file contains some defenitions to be used all over the application

//All possible actions
enum ActionType 
{
	ADD_Buff,			//Add 1-input Buffer gate
	ADD_INV,			//Add 1-input Inverter gate
	ADD_AND_GATE_2,		//Add 2-input AND gate
	ADD_OR_GATE_2,		//Add 2-input OR gate
	ADD_NAND_GATE_2,	//Add 2-input NAND gate
	ADD_NOR_GATE_2,		//Add 2-input NOR gate
	ADD_XOR_GATE_2,		//Add 2-input XOR gate
	ADD_XNOR_GATE_2,	//Add 2-input XNOR gate
	ADD_AND_GATE_3,		//Add 3-input AND gate
	ADD_NOR_GATE_3,		//Add 3-input NOR gate
	ADD_XOR_GATE_3,		//Add 3-input XOR gate
	ADD_Switch,			//Add Switch
	ADD_LED,			//Add LED
	ADD_CONNECTION,		//Add Wire Connection
	ADD_Gates,
	ADD_Label,			//Add Label to a Component, a Connection
	ADD_Gate_Menu,			// Show menu of gates

	EDIT,			//Edit a Connection

	Create_TruthTable,	//Create Truth Table of the Circuit

	Change_Switch,		//Change Switch Status in Simulation Mode

	SELECT,		//Select a Component, a Connection
	DEL,		//Delete a Component, a Connection
	MOVE,		//Move a Component, a Connection

	SAVE,		//Save the whole Circuit to a file
	LOAD,		//Load a Circuit from a file

	COPY,		//Copy the item
	CUT,		//CUT the item
	PASTE,		//PASTE the item

	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to Simulatiom mode

	EXIT,		//Exit the application

	STATUS_BAR,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar

};

//Possible Status for the pin
enum STATUS
{
	LOW,
	HIGH,
	UNSIGNED
};

enum MODE	//Modes of operation
{
	DESIGN,
	Gate,
	SIMULATION

};

enum DsgnMenuGates {
	ITM_AND2,		//2 input AND gate item in menu
	ITM_OR2,		//2 input OR gate item in menu
	ITM_NAND2,		//2 input NAND gate item in menu
	ITM_NOR2,		//2 input NOR gate item in menu
	ITM_XOR2,		//2 input XOR gate item in menu
	ITM_XNOR2,		//2 input XNOR gate item in menu
	ITM_AND3,		//3 input AND gate item in menu
	ITM_NOR3,		//3 input NOR gate item in menu
	ITM_XOR3,		//3 input XOR gate item in menu

	ITM_BUFF,		//Buffer gate item in menu
	ITM_INV,		//Inverter input OR gate item in menu

	ITM_SWITCH,
	ITM_LED,
	ITM_DSN_MODE,
	ITM_EXIT_Gate,
	ITM_Gate_CNT
};

enum DsgnMenuItem //The items of the design menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_AddGates,       // Add Menu of Gates
	ITM_Connect,		//Connect in menu
	ITM_Label,		//Label item in menu
	ITM_Edit,		//Edit item in menu
	ITM_Select,		//Select item in menu
	ITM_Delete,		//Delete item in menu
	ITM_Move,		//Move item in menu
	ITM_Save,		//Save item in menu
	ITM_Load,		//Load item in menu
	ITM_Copy,		//Copy item in menu
	ITM_Cut,		//Cut item in menu
	ITM_Paste,		//Paste item in menu

	ITM_Stimulate,	//Stimulate item in menu

	ITM_EXIT,		//Exit item
	
	ITM_DSN_CNT		//no. of design menu items ==> This should be the last line in this enum
	
};


enum SimMenuItem //The items of the simulation menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	ITM_SwitchToMenu,
	//TODO:Add more items names here
	ITM_EXIT_SIM,
	
	ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum
};

//Maximum number of input pins that can be connected to any output pin
#define MAX_CONNS 20

//assume fan out is 5 for now it can be read from the user or can be predefined as const
enum FANOUT
{
	GATE_FANOUT = 5	//Default fan out of 2-input AND gate
};

//A structure to contain drawing parameters for each component
//Each component occupies a rectangluar area so it needs 2 points to represent that area
//this structure can be extended if desired
struct GraphicsInfo
{
	int x1,y1, x2, y2;
};

#ifndef NULL
#define NULL 0
#endif

#endif