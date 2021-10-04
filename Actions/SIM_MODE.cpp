#include "SIM_MODE.h"
#include "../ApplicationManager.h"

SIMMODE::SIMMODE(ApplicationManager* pApp) :Action(pApp)
{
}

SIMMODE::~SIMMODE(void)
{
}

void SIMMODE::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input*  pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Stimilation MODE");
}

void SIMMODE::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	// Make Stimulation Tool Bar
	pOut->CreateSimulationToolBar();

	// Unselect All Items
	pManager->unselectAll();
	
	// Stimulation the Gate
	pManager->Cascade();
}

void SIMMODE::Undo() {

}

void SIMMODE::Redo() {
}

