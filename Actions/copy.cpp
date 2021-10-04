#include "copy.h"

copyItem::copyItem(ApplicationManager *pApp):Action(pApp){}

copyItem::~copyItem(void){}

void copyItem::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	//Print Action Message
	pOut->PrintMsg("Click on the Item to Copy it.");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	pComp = pManager->ChooseGate(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void copyItem::Execute()
{
	ReadActionParameters();
	
	if (!pComp)
	{
		pManager->GetOutput()->PrintMsg("You must click on Component");
		return;
	}
	
	// Store Item it in Clipboard
	pManager->setClipboard(pComp);
	pManager->GetOutput()->PrintMsg("Gate has copied");
}

void copyItem::Undo(){
}

void copyItem::Redo(){
}

