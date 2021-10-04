//#include "Input.h"
#include "Output.h"

#define esc 27
#define backspace '\b'
#define enter '\r'


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pOut)
{

	bool CON = true;
	char chr;
	string Item_Name;

	do {
		pWind->WaitKeyPress(chr);

		switch (chr)
		{
		//Read a complete string from the user until the user presses "ENTER".
		case enter:
			CON = false;
			pOut->ClearStatusBar();	
			break;

		//If the user presses "ESCAPE". This function should return an empty string.
		case esc:
			Item_Name = " ";
			CON = false;
			break;

		//"BACKSPACE" should be also supported
		case backspace:
			if (Item_Name.length() == 0) {
				//User should see what he is typing at the status bar
				pOut->PrintMsg(Item_Name);
				break;
			}
			else {
				Item_Name.pop_back();
				//User should see what he is typing at the status bar
				pOut->PrintMsg(Item_Name);
				break;
			}
		default:
			Item_Name.push_back(chr);
			//User should see what he is typing at the status bar
			pOut->PrintMsg(Item_Name);
			break;
		}
	} while (CON);

	return Item_Name;
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItemOrder) {
			case ITM_AddGates: return ADD_Gate_Menu;
			case ITM_Connect: return ADD_CONNECTION;
			case ITM_Label: return ADD_Label;
			case ITM_Edit: return EDIT;
			case ITM_Select: return SELECT;
			case ITM_Delete: return DEL;
			case ITM_Move: return MOVE;
			case ITM_Save: return SAVE;
			case ITM_Load: return LOAD;
			case ITM_Copy: return COPY;
			case ITM_Cut: return CUT;
			case ITM_Paste: return PASTE;
			case ITM_Stimulate: return SIM_MODE;

			case ITM_EXIT: return EXIT;
			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else if (UI.AppMode == Gate) { 
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight){
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItemOrder) {
			case ITM_AND2: return ADD_AND_GATE_2;
			case ITM_OR2: return ADD_OR_GATE_2;
			case ITM_NAND2: return ADD_NAND_GATE_2;
			case ITM_NOR2: return ADD_NOR_GATE_2;
			case ITM_XOR2: return ADD_XOR_GATE_2;
			case ITM_XNOR2: return ADD_XNOR_GATE_2;

			case ITM_AND3: return ADD_AND_GATE_3;
			case ITM_NOR3: return ADD_NOR_GATE_3;
			case ITM_XOR3: return ADD_XOR_GATE_3;

			case ITM_BUFF: return ADD_Buff;
			case ITM_INV: return ADD_INV;

			case ITM_SWITCH: return ADD_Switch;
			case ITM_LED: return ADD_LED;
			
			case ITM_DSN_MODE: return DSN_MODE;

			case ITM_EXIT_Gate: return EXIT;

			default: return DSN_TOOL;
			}
		}
		else if(y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}
	}
	else	//Application is in Simulation mode
	{
		
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItemOrder) {
			case ITM_SwitchToMenu: return DSN_MODE;
			case ITM_EXIT_SIM: return EXIT;

			default: return DSN_TOOL;
			}
		}else if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return Change_Switch;
		}
	}
}

Input::~Input(){
}
