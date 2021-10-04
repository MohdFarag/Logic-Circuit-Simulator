#include "DSN_MODE.h"
#include "../ApplicationManager.h"

DSNMODE::DSNMODE(ApplicationManager* pApp) :Action(pApp)
{
}

DSNMODE::~DSNMODE(void)
{
}

void DSNMODE::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Return to Design mode");

}

void DSNMODE::Execute()
{
	Output* pOut = pManager->GetOutput();
	// Create toolbar
	pOut->CreateDesignToolBar();
}

void DSNMODE::Undo() {

}

void DSNMODE::Redo() {
}

