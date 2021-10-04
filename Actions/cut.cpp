#include "cut.h"

cutItem::cutItem(ApplicationManager *pApp):Action(pApp){
}

cutItem::~cutItem(void)
{
}

void cutItem::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click on the Item to cut it.");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	Gate = pManager->ChooseGate(Cx, Cy);

	//Delete Gate
	Gate->DelDraw(pOut);

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void cutItem::Execute()
{
	ReadActionParameters();

	if (!Gate)
	{
		pManager->GetOutput()->PrintMsg("You must choose gate to cut it.");
		return;
	}

	// Store Item it in Clipboard
	pManager->setClipboard(Gate);
	pManager->GetOutput()->PrintMsg("Gate has cutted");
}

void cutItem::Undo()
{
}

void cutItem::Redo()
{
}

