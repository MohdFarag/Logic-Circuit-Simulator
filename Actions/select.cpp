#include "select.h"
#include "../ApplicationManager.h"

SelectG::SelectG(ApplicationManager* pApp) :Action(pApp)
{
}

SelectG::~SelectG(void)
{
	
}

void SelectG::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click to Select Gete the gate");

	//Wait for User Input
	pIn->GetPointClicked(X, Y);

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void SelectG::Execute()
{
	ReadActionParameters();
	Comp = pManager->SelectComponent(X, Y);
	// If component selected -> make unselected
	if (Comp->GetSelect() == false) {
		Comp->SetSelect(true);
	}
	else {
		// If component unselected -> make selected
		Comp->SetSelect(false);
	}
}

void SelectG::Undo() {

}

void SelectG::Redo() {

}

