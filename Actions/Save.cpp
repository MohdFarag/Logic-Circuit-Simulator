#include "Save.h"
#include "../ApplicationManager.h"
#include <fstream>

Save::Save(ApplicationManager* pApp) :Action(pApp)
{
	
}

Save::~Save(void)
{
}

void Save::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Enter the file name:");
	str = pIn->GetSrting(pOut);
}

void Save::Execute()
{
	ReadActionParameters();
	str += ".txt";
	outF = new ofstream(str);
	pManager->save(outF);
	Output* pOuT = pManager->GetOutput();
	pOuT->PrintMsg("Done.");
}

void Save::Undo() {

}

void Save::Redo() {
}

