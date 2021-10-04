#include "AddConnection.h"
#include "../ApplicationManager.h"

AddConnection::AddConnection(ApplicationManager* pApp, bool isLoaded, Gates* SrcGate, Gates* DstGate, int IpinNum) :Action(pApp) {
	this->isLoaded = isLoaded;
	if (isLoaded) {
		this->SrcGate = SrcGate;
		this->DstGate = DstGate;
		this->IpinNum = IpinNum;
	}
}

AddConnection::~AddConnection(void)
{
}

void AddConnection::ReadActionParameters() {

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	/////////////////////////////////////////////

	// Print Massege
	pOut->PrintMsg("Connection: Choose the Source gate");

	// Wait click from user and get point location of it 
	pIn->GetPointClicked(x, y);

	// Return Gate that clicked
	SrcGate = pManager->ChooseGate(x, y);
	
	// If user didn't click on  Gate 
	if (SrcGate == NULL) {
		pOut->PrintMsg("You must click on the gate!"); 
		return;
	}

	/////////////////////////////////////////////

	// Print Massege
	pOut->PrintMsg("Connection: Choose the Destination gate");

	// Wait click from user and get point location of it 
	pIn->GetPointClicked(x, y);

	if (DstGate = pManager->ChooseGate(x, y)) { // Return Gate that clicked

		if (DstGate == SrcGate)
		{
			// If user click same Gate 
			pOut->PrintMsg("You can't connect same gate with itself.");
			return;
		}

		// if number of inputs of Component
		if (DstGate->getNumInputs() == 3) { // = 3 like And3 , Nor3 ,etc..
			pOut->PrintMsg("Connection: choose the Input Pin number ( 1 or 2 or 3)");
		}
		else if (DstGate->getNumInputs() == 2) // = 2 like And2 , Xor2 ,etc..
		{
			pOut->PrintMsg("Connection: choose the Input Pin number ( 1 or 2)");
		}

		if (DstGate->getNumInputs() != 1) { // if distination gate has more than 1 input
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

void AddConnection::Execute()
{
	// If load Connection
	if (isLoaded == false) {
		ReadActionParameters();
	}

	if (DstGate && SrcGate && DstGate != SrcGate){

		GraphicsInfo SrcGFX = SrcGate->GetGfxInfo();
		GInfo.x1 = SrcGFX.x2;
		GInfo.y1 = SrcGFX.y2 - UI.GATE_Height / 2;

		SrcPin = &SrcGate->getOutputPin();///////////
		SrcPin->setComponent(SrcGate);


		/////////////////////////////////////////

		DstPin = &DstGate->getInputPinByN(IpinNum);/////////
		GInfo.x2 = DstPin->GetGfxInfo().x1;

		switch (DstGate->getNumInputs()){
		case 3:
			GInfo.y2 = DstPin->GetGfxInfo().y1 + (8 * IpinNum);
			break;
		case 2:
			GInfo.y2 = DstPin->GetGfxInfo().y1 + (10 * IpinNum);
			break;
		case 1:			
			GInfo.y2 = DstPin->GetGfxInfo().y1;
			break;
		}

		Connection* con = new Connection(GInfo, SrcPin, DstPin, IpinNum, SrcGate, DstGate);
		con->setDistComp(DstGate);
		con->setSrcComp(SrcGate);
		
		if (SrcPin->ConnectTo(con) && DstPin->ConnectFrom(con))
		{
			// Add Connection
			pManager->AddComponent(con);
		}
	}
}

void AddConnection::Undo() {

}

void AddConnection::Redo() {

}

