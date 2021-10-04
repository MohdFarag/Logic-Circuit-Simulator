#include "AddXNORgate2.h"
#include "..\ApplicationManager.h"

AddXNORgate2::AddXNORgate2(ApplicationManager *pApp,bool isLoaded):Action(pApp)
{
	this->isLoaded = isLoaded;
}

AddXNORgate2::~AddXNORgate2(void)
{
}

void AddXNORgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input XNOR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
	
}

void AddXNORgate2::Execute()
{
	//Get Center point of the Gate
	if (isLoaded == false) {
		ReadActionParameters();
	}
	else {
		Cx = 350; // Default value for Cx
		Cy = 350; // Default value for Cy
	}
	//Calculate the rectangle Corners
	int Wdth = UI.GATE_Width;
	int Len = UI.GATE_Height;
	
	GraphicsInfo GInfo; //Gfx info to be used to construct the XNOR2 gate
	
	GInfo.x1 = Cx - Wdth/2;
	GInfo.x2 = Cx + Wdth/2;

	GInfo.y1 = Cy - Len/2;
	GInfo.y2 = Cy + Len/2;
	XNOR2 *pA=new XNOR2(GInfo, GATE_FANOUT);
	pManager->AddComponent(pA);
}

void AddXNORgate2::Undo(){

}

void AddXNORgate2::Redo(){
}

