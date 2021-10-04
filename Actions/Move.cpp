#include "Move.h"
#include "../ApplicationManager.h"

Move::Move(ApplicationManager* pApp) :Action(pApp)
{
}

Move::~Move(void)
{
}

void Move::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Choose gate to Move it.");

	//Wait for User Input
	pIn->GetPointClicked(x, y);

	//Choose Gate to move it
	Gate = pManager->ChooseGate(x,y);

	//Print Action Message
	pOut->PrintMsg("Choose the new location.");
	
	//Wait for User Input
	pIn->GetPointClicked(x, y);
	
	//Clear Status Bar
	pOut->ClearStatusBar();
}


void Move::Execute()
{
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Wdth = UI.GATE_Width;
	int Len = UI.GATE_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the Switch gate

	GInfo.x1 = x - Wdth / 2;
	GInfo.x2 = x + Wdth / 2;

	GInfo.y1 = y - Len / 2;
	GInfo.y2 = y + Len / 2;

	// Change Location of the Component
	Gate->SetGfxInfo(GInfo);
	for (int i = 0; i < Gate->getOutputPin().getNumConn(); i++)
	{
		GraphicsInfo G_conn = Gate->getOutputPin().getConnection()[i]->GetGfxInfo();
		G_conn.x1 = GInfo.x2;
		G_conn.y1 = GInfo.y2 - UI.GATE_Height / 2;
		Gate->getOutputPin().getConnection()[i]->SetGfxInfo(G_conn);
	}
}

void Move::Undo() {

}

void Move::Redo() {
}

