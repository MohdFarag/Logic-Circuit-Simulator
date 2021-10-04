#include "Del.h"
#include "../ApplicationManager.h"

Del::Del(ApplicationManager* pApp) :Action(pApp)
{
}

Del::~Del(void)
{
}

void Del::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click on the gate that you want to delete it.");

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void Del::Execute()
{
	pManager->DelComponent();
}

void Del::Undo() {

}

void Del::Redo() {
}

