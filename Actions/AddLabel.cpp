#include "AddLabel.h"
#include "../ApplicationManager.h"

Label::Label(ApplicationManager* pApp) :Action(pApp)
{
}

Label::~Label(void)
{
}

void Label::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click on the gate to label it");
}

void Label::Execute()
{
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();

	Comp = pManager->findSelectedComponent();
	if (Comp)
	{
		GraphicsInfo GfxInfo = Comp->GetGfxInfo();
		string STR = pOut->DrawLabel(GfxInfo);
		Comp->SetLabel(STR);
		Comp->SetSelect(false);
	}
	return;
}

void Label::Undo() {}

void Label::Redo() {}

