#include "paste.h"
#include "../AppMangerInclude.h"


paste::paste(ApplicationManager* pApp, bool CoORPa):Action(pApp)
{
	this->CoORPa = CoORPa;
}

paste::~paste(void)
{

}


void paste::ReadActionParameters() 
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Paste Gate : Click on the location you want to paste gate on it.");
	pIn->GetPointClicked(Cx, Cy);
}

void paste::Execute()
{
	ReadActionParameters();
	
	// Get Copy
	pAs = pManager->getClipboard();
	
	Gates *pA;
	if (pAs) // If not null
	{
		//Calculate the rectangle Corners
		int Wdth = UI.GATE_Width;
		int Len = UI.GATE_Height;

		GraphicsInfo GInfo = pAs->GetGfxInfo();

		GInfo.x1 = Cx - Wdth / 2;
		GInfo.x2 = Cx + Wdth / 2;

		GInfo.y1 = Cy - Len / 2;
		GInfo.y2 = Cy + Len / 2;


		// If copy
		if (CoORPa == false)
		{
			// Make New Item
			if (dynamic_cast<AND2*>(pAs)) pA = new AND2(GInfo, GATE_FANOUT);
			else if (dynamic_cast<AND3*>(pAs)) pA = new AND3(GInfo, GATE_FANOUT);
			else if (dynamic_cast<Buffer*>(pAs)) pA = new Buffer(GInfo, GATE_FANOUT);
			else if (dynamic_cast<Inverter*>(pAs)) pA = new Inverter(GInfo, GATE_FANOUT);
			else if (dynamic_cast<LED*>(pAs)) pA = new LED(GInfo, GATE_FANOUT);
			else if (dynamic_cast<NAND2*>(pAs)) pA = new NAND2(GInfo, GATE_FANOUT);
			else if (dynamic_cast<NOR2*>(pAs)) pA = new NOR2(GInfo, GATE_FANOUT);
			else if (dynamic_cast<NOR3*>(pAs)) pA = new NOR3(GInfo, GATE_FANOUT);
			else if (dynamic_cast<OR2*>(pAs)) pA = new OR2(GInfo, GATE_FANOUT);
			else if (dynamic_cast<SWITCH*>(pAs)) pA = new SWITCH(GInfo, GATE_FANOUT);
			else if (dynamic_cast<XNOR2*>(pAs)) pA = new XNOR2(GInfo, GATE_FANOUT);
			else if (dynamic_cast<XOR2*>(pAs)) pA = new XOR2(GInfo, GATE_FANOUT);
			else if (dynamic_cast<XOR3*>(pAs)) pA = new XOR3(GInfo, GATE_FANOUT);

			pManager->AddComponent(pA);
		}
		else
		{
			// If Paste
			pAs->SetGfxInfo(GInfo);
		}
	}
	else {
		pManager->GetOutput()->PrintMsg("No gate are copied or cutted");
		return;
	}
}

void paste::Undo(){
}

void paste::Redo(){
}

