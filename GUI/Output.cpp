#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;
	
	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);	
	ChangeTitle("Programming Techniques Project - Circuit Gates");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(UI.MsgColor); 
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight + 5, UI.width, UI.height - UI.StatusBarHeight - 5);
	
}

void Output::ClearMenu()const
{
	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, 80);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	ClearMenu();
	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_AddGates] = "Images\\Menu\\Menu_GATES.jpg";
	MenuItemImages[ITM_Connect] = "Images\\Menu\\Menu_CONNECT.jpg";
	MenuItemImages[ITM_Label] = "Images\\Menu\\Menu_LABEL.jpg";
	MenuItemImages[ITM_Edit] = "Images\\Menu\\Menu_EDIT.jpg";
	MenuItemImages[ITM_Select] = "Images\\Menu\\Menu_SELECT.jpg";
	MenuItemImages[ITM_Delete] = "Images\\Menu\\Menu_DELETE.jpg";
	MenuItemImages[ITM_Move] = "Images\\Menu\\Menu_MOVE.jpg";
	MenuItemImages[ITM_Save] = "Images\\Menu\\Menu_SAVE.jpg";
	MenuItemImages[ITM_Load] = "Images\\Menu\\Menu_LOAD.jpg";
	MenuItemImages[ITM_Copy] = "Images\\Menu\\Menu_COPY.jpg";
	MenuItemImages[ITM_Cut] = "Images\\Menu\\Menu_CUT.jpg";
	MenuItemImages[ITM_Paste] = "Images\\Menu\\Menu_PASTE.jpg";
	MenuItemImages[ITM_Stimulate] = "Images\\Menu\\Menu_SWITCHSIM.jpg";
	MenuItemImages[ITM_EXIT] = "Images\\Menu\\Menu_Exit.jpg";

	//Draw menu item one image at a time
	for(int i=0; i<ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i],i*UI.ToolItemWidth,0,UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	
}

void Output::CreateToolBarGates() const
{
	UI.AppMode = Gate;	//Design Mode
	ClearMenu();
	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string GateItemImages[ITM_Gate_CNT];
	GateItemImages[ITM_AND2] = "Images\\Menu\\Menu_AND2.jpg";
	GateItemImages[ITM_AND3] = "Images\\Menu\\Menu_AND3.jpg";
	GateItemImages[ITM_NAND2] = "Images\\Menu\\Menu_NAND2.jpg";
	GateItemImages[ITM_OR2] = "Images\\Menu\\Menu_OR2.jpg";
	GateItemImages[ITM_NOR2] = "Images\\Menu\\Menu_NOR2.jpg";
	GateItemImages[ITM_NOR3] = "Images\\Menu\\Menu_NOR3.jpg";
	GateItemImages[ITM_XOR2] = "Images\\Menu\\Menu_XOR2.jpg";
	GateItemImages[ITM_XOR3] = "Images\\Menu\\Menu_XOR3.jpg";
	GateItemImages[ITM_XNOR2] = "Images\\Menu\\Menu_XNOR2.jpg";
	GateItemImages[ITM_BUFF] = "Images\\Menu\\Menu_Buffer.jpg";
	GateItemImages[ITM_INV] = "Images\\Menu\\Menu_INV.jpg";
	GateItemImages[ITM_SWITCH] = "Images\\Menu\\Menu_SWITCH.jpg";
	GateItemImages[ITM_LED] = "Images\\Menu\\Menu_LED.jpg";
	GateItemImages[ITM_DSN_MODE] = "Images\\Menu\\Menu_DSN_MODE.jpg";
	GateItemImages[ITM_EXIT_Gate] = "Images\\Menu\\Menu_Exit.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_Gate_CNT; i++)
		pWind->DrawImage(GateItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
	

	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{	
	UI.AppMode = SIMULATION;	//Simulation Mode
	ClearMenu();
	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)
	string SIMItemImages[ITM_DSN_CNT];
	SIMItemImages[ITM_SwitchToMenu] = "images\\SIM\\SIM_SwitchToMenu.jpg";
	SIMItemImages[ITM_EXIT_SIM] = "images\\SIM\\SIM_EXIT.jpg";
	//Gonna need to add diminseons to the images similar to the draw functions below and menu above? and add more stuff?

	//Draw SIM item one image at a time
	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(SIMItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(GREEN, 4);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//


string Output::DrawLabel(GraphicsInfo r_GfxInfo) {
	// DrawSrting fumction take one argument (GraphicsInfo) that determine place of gate that string belongs to it
	Input* pIn = CreateInput();
	PrintMsg("Enter the label of the gate:");
	string msg = pIn->GetSrting(this);

	// Set the Message offset from the Status Bar
	int MsgX = r_GfxInfo.x1;
	int MsgY = r_GfxInfo.y2 + 50;

	// Print the Message
	pWind->SetFont(15, ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(RED);
	pWind->DrawString(MsgX, MsgY, msg);

	return msg;
}

void Output::reDrawLabel(GraphicsInfo r_GfxInfo, string msg) const {
	if (msg == "No_label") {
		msg = "";
	}
	// Set the Message offset from the Status Bar
	int MsgX = r_GfxInfo.x1;
	int MsgY = r_GfxInfo.y2 + 10;

	// Print the Message
	pWind->SetFont(15, ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(RED);
	pWind->DrawString(MsgX, MsgY, msg);
}


void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if(selected)	//use image in the highlighted case
		GateImage="Images\\Gates\\Gate_AND2_Hi.jpg";
	else  
		GateImage = "Images\\Gates\\Gate_AND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
	Output *x;
}



void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_AND3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_AND3.jpg";

	//Draw AND3 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND3 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
}

void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_OR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_OR2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
}

void Output::DrawSWTCH(GraphicsInfo r_GfxInfo, bool selected, bool isOn) const
{
	string GateImage;
	if (selected){	//use image in the highlighted case
		if (isOn) {
			GateImage = "Images\\Gates\\Gate_SWITCHON_Hi.jpg";
		}
		else {
			GateImage = "Images\\Gates\\Gate_SWITCHOFF_Hi.jpg";
		}
	}
	else {
		if (isOn) {
			GateImage = "Images\\Gates\\Gate_SWITCHON.jpg";
		}
		else {
			GateImage = "Images\\Gates\\Gate_SWITCHOFF.jpg";
		}
	}

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
}

void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOR2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
}

void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOR3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOR3.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
}

void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XNOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XNOR2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
}

void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XOR2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
}

void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XOR3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XOR3.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
}

void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NAND2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NAND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
}


void Output::DrawBuffer(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_Buffer_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_Buffer.jpg";

	//Draw Buffer Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by Buffer Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
}

void Output::DrawInverter(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_INV_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_INV.jpg";

	//Draw Inverter Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by Inverter Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
}

void Output::DrawLED(GraphicsInfo r_GfxInfo, bool selected, bool isHigh) const
{
	string GateImage;
	if (selected && !isHigh)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_LEDOFF_Hi.jpg";
	else if (selected && isHigh)	//use image in the High highlighted case
		GateImage = "Images\\Gates\\Gate_LEDON_Hi.jpg";
	else if (!selected && isHigh)	//use image in the High case
		GateImage = "Images\\Gates\\Gate_LEDON.jpg";
	else
		GateImage = "Images\\Gates\\Gate_LEDOFF.jpg";

	//Draw LED Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GATE_Width, UI.GATE_Height);
}


void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{
	//TODO: Add code to draw connection
	
	pWind->SetPen(BLACK, 4);

	if (r_GfxInfo.y1 != r_GfxInfo.y2) 
	{
		// First Line
		GraphicsInfo A_GfxInfo;
		A_GfxInfo.x1 = r_GfxInfo.x1;
		A_GfxInfo.y1 = r_GfxInfo.y1;
		A_GfxInfo.x2 = r_GfxInfo.x2 - (r_GfxInfo.x2 - r_GfxInfo.x1) / 2;
		A_GfxInfo.y2 = r_GfxInfo.y1;
		
		if (selected) {
			pWind->SetPen(RED, 10);
			pWind->DrawLine(A_GfxInfo.x1, A_GfxInfo.y1, A_GfxInfo.x2, A_GfxInfo.y2, FRAME);
		}
		else {
			pWind->DrawLine(A_GfxInfo.x1, A_GfxInfo.y1, A_GfxInfo.x2, A_GfxInfo.y2, FRAME);
		}
		///////////////////////////////////////////////////////////////////////////////////

		// Seconed Line
		GraphicsInfo B_GfxInfo;
		B_GfxInfo.x1 = A_GfxInfo.x2;
		B_GfxInfo.y1 = A_GfxInfo.y2;
		B_GfxInfo.x2 = A_GfxInfo.x2;
		B_GfxInfo.y2 = r_GfxInfo.y2;

		if (selected) {
			pWind->SetPen(RED, 10);
			pWind->DrawLine(B_GfxInfo.x1, B_GfxInfo.y1, B_GfxInfo.x2, B_GfxInfo.y2, FRAME);
		}
		else {
			pWind->DrawLine(B_GfxInfo.x1, B_GfxInfo.y1, B_GfxInfo.x2, B_GfxInfo.y2, FRAME);
		}

		r_GfxInfo.x1 = B_GfxInfo.x2;
		r_GfxInfo.y1 = B_GfxInfo.y2;
	}	
	if (selected) {
		pWind->SetPen(RED, 10);
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2, FRAME);
	}
	else {
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2, FRAME);
	}
}

void Output::DelDraw(GraphicsInfo r_GfxInfo)
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);
}


Output::~Output()
{
	delete pWind;
}
