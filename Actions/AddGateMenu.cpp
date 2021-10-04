#include "AddGateMenu.h"
#include "..\ApplicationManager.h"

AddGateMenu::AddGateMenu(ApplicationManager *pApp):Action(pApp)
{
}

AddGateMenu::~AddGateMenu(void)
{
}

void AddGateMenu::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("click on the gate you want to put it.");
}

void AddGateMenu::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->CreateToolBarGates();
}

void AddGateMenu::Undo(){

}

void AddGateMenu::Redo(){
}



