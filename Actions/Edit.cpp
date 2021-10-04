#include "Edit.h"
#include "../ApplicationManager.h"

Edit::Edit(ApplicationManager* pApp) :Action(pApp)
{
}

Edit::~Edit(void)
{
}

void Edit::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click on the connection to edit it.");

	// Wait click from user and get point location of it 
	pIn->GetPointClicked(Cx, Cy);

	// Return Gate that clicked
	Conn = pManager->ChooseConnection(Cx, Cy);
	
	//Print Action Message
	pOut->PrintMsg("Connection: Choose the Source gate");

	// Wait click from user and get point location of it 
	pIn->GetPointClicked(Cx, Cy);

	// Return Gate that clicked
	Src = pManager->ChooseGate(Cx, Cy);

	// If user didn't click on  Gate 
	if (Src == NULL) {
		pOut->PrintMsg("You must click on the gate!");
		return;
	}

	/////////////////////////////////////////////

	// Print Massege
	pOut->PrintMsg("Connection: Choose the Destination gate");

	// Wait click from user and get point location of it 
	pIn->GetPointClicked(Cx, Cy);

	if (Dst = pManager->ChooseGate(Cx, Cy)) { // Return Gate that clicked

		if (Dst == Src)
		{
			// If user click same Gate 
			pOut->PrintMsg("You can't connect same gate with itself.");
			return;
		}

		// if number of inputs of Component
		if (Dst->getNumInputs() == 3) { // = 3 like And3 , Nor3 ,etc..
			pOut->PrintMsg("Connection: choose the Input Pin number ( 1 or 2 or 3)");
		}
		else if (Dst->getNumInputs() == 2) // = 2 like And2 , Xor2 ,etc..
		{
			pOut->PrintMsg("Connection: choose the Input Pin number ( 1 or 2)");
		}

		if (Dst->getNumInputs() != 1) { // if distination gate has more than 1 input
			string str;
			// Read string from the user = number of input that user want to connect it
			IpinNum = stoi(pIn->GetSrting(pOut)) - 1;
		}
		else {
			// the number of input that user want to connect it if the gate has 1 input = 0
			IpinNum = 0;
		}
	}
	else {
		// If user didn't click on  Gate 
		pOut->PrintMsg("You must click on the gate!");
		return;
	}

	
	// Clear
	pOut->ClearStatusBar();
}

void Edit::Execute()
{
	ReadActionParameters();
	
	// Add New Connection
	AddConnection* connect = new AddConnection(pManager, true, Src, Dst, IpinNum);
	// Execute Action
	connect->Execute();
	// Delete Old Connections
	pManager->DelComponent(Conn);
}

void Edit::Undo() {

}

void Edit::Redo() {
}

