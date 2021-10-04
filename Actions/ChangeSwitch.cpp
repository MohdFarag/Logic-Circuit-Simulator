#include "ChangeSwitch.h"
#include "../ApplicationManager.h"

ChangeSwitch::ChangeSwitch(ApplicationManager* pApp) :Action(pApp)
{
}

ChangeSwitch::~ChangeSwitch(void)
{

}

void ChangeSwitch::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pIn->GetPointClicked(x, y);
}

void ChangeSwitch::Execute()
{
	ReadActionParameters();

	SWITCH* swArr = pManager->changeSwitch(x,y);
	
	if (swArr)
	{
		if (swArr->GetOutPinStatus()) swArr->setInputPinStatus(1, LOW);
		else swArr->setInputPinStatus(1, HIGH);
	}

	pManager->Cascade();
}

void ChangeSwitch::Undo() {

}

void ChangeSwitch::Redo() {

}


