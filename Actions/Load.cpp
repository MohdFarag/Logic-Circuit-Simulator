#include "Load.h"
#include "../ApplicationManager.h"

Load::Load(ApplicationManager* pApp) :Action(pApp)
{
	
}

Load::~Load(void)
{
}

void Load::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Enter the file name:");
	str = pIn->GetSrting(pOut);

	// Take premsiton to delete the current file and load new file
	pOut->PrintMsg("Any unsaved data will be deleted. Continue? (Y/F)");
	string isDelete = pIn->GetSrting(pOut);
	if (isDelete == "Y") {
		pre = true;
	}else
	{
		pre == false;
	}
}

void Load::Execute()
{
	Output* pOuT = pManager->GetOutput();
	ReadActionParameters();

	if (pre == false) {
		return;
	}
	
	// Make new File 
	str += ".txt";
	inF = new ifstream(str);
	
	if (!inF->is_open()) {
		// If not Downloaded
		pOuT->PrintMsg("Failed!");
		return;
	}
	else {
		// If Downloaded
		pOuT->PrintMsg("Done, the file is open ;)");
		pManager->deleteAll();
		pOuT->ClearDrawingArea();
	}

	pManager->load(inF);
}

void Load::Undo() {

}

void Load::Redo() {
}

