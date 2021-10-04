//Include FILES From Action

#include "ApplicationManager.h"
#include "AppMangerInclude.h"
#include <fstream>

ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
	CoORPa = false;
}

////////////////////////////////////////////////////////////////////

// Add new Componant to Component list
void ApplicationManager::AddComponent(Component* pComp)
{
	if (pComp->GetGfxInfo().y1 > UI.ToolBarHeight && pComp->GetGfxInfo().y2 < UI.height - UI.StatusBarHeight)
	{
		CompList[CompCount++] = pComp;
	}
}

// Delete componant from component list
void ApplicationManager::DelComponent(){
	int Count = CompCount;
	for (int i = 0; i < Count; i++)
	{
		// If Component is Gate Delete its Connection
		if (dynamic_cast<Gates*>(CompList[i]))
		{
			dynamic_cast<Gates*>(CompList[i])->getOutputPin().DeleteConnections();
			for (int k = 0; k < dynamic_cast<Gates*>(CompList[i])->getNumInputs(); k++)
			{
				if (&dynamic_cast<Gates*>(CompList[i])->getInputPinByN(k) != NULL)
				{
					// Delete Connections
					dynamic_cast<Gates*>(CompList[i])->getInputPins()[k].DeleteConnection();
				}
			}
		}
		// If Component is Connection or Gate Delete it.
		if (CompList[i])
		{
			if (CompList[i]->GetSelect() == true)
			{
				delete CompList[i];
				CompList[i] = NULL;
				for (int j = i; j < CompCount; j++) {
					// Shifting All Component After deleted (Null) Component 
					CompList[j] = CompList[j + 1];
				}
				i--;
				// Decrease Component Count
				CompCount--;
			}
		}
	}
}

// Delete componant from component list
void ApplicationManager::DelComponent(Component* pComp) {
	int Count = CompCount;
	for (int i = 0; i < Count; i++)
	{
		if (CompList[i] == pComp){
				delete CompList[i];
				CompList[i] = NULL;
				for (int j = i; j < CompCount; j++) {
					CompList[j] = CompList[j + 1];
				}
				i--;
				CompCount--;
		}
	}
}

//Check ckick is Inside Area of Component or not.
bool ApplicationManager::checkInsideArea(int x,int y, Component* Comp) {
	GraphicsInfo C_GfxInfo;
	if (Comp != NULL) {
		if (dynamic_cast<Gates*>(Comp))
		{
			// Check click inside Gate or not
			C_GfxInfo = Comp->GetGfxInfo();
			if (C_GfxInfo.x1 <= x && x <= C_GfxInfo.x2 && C_GfxInfo.y1 <= y && y <= C_GfxInfo.y2) {
				return true;
			}
		}
		if (dynamic_cast<Connection*>(Comp))
		{
			// Check click inside Connection or not
			C_GfxInfo = Comp->GetGfxInfo();
			if (C_GfxInfo.x1 < x && C_GfxInfo.x2 - (C_GfxInfo.x2 - C_GfxInfo.x1) / 2 > x  && C_GfxInfo.y1-5 < y && C_GfxInfo.y1+5 > y
				||
				C_GfxInfo.x2 > x && C_GfxInfo.x1 + (C_GfxInfo.x2 - C_GfxInfo.x1) / 2 < x && C_GfxInfo.y2-5 < y && C_GfxInfo.y2+5 > y
				||
				C_GfxInfo.y2 > y && C_GfxInfo.y1 < y && (C_GfxInfo.x2 + C_GfxInfo.x1 )/ 2 + 5 > x && (C_GfxInfo.x2 + C_GfxInfo.x1) / 2 - 5 < x) 
			{
				return true;
			}
		}
	}
	return false; // if not
}

// Label a Component
Component * ApplicationManager::findSelectedComponent()
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i] != NULL)
		{
			// find the selected Gates
			if (CompList[i]->GetSelect() == true)
			{
				// Return a Selected gate
				return CompList[i];
			}
		}
	}
	return NULL;
}
////////////////////////////////////////////////////////////////////

// To make a component Selected.
Component * ApplicationManager::SelectComponent(int x, int y) {
	for (int i = 0; i < CompCount; i++) {
		// Check Inside Area
		if (checkInsideArea(x, y, CompList[i])) {
			return CompList[i];
		}
	}
	return NULL;
}

// Take a click from a user, then returtn the gate that the click is inside a area of it. 
Gates* ApplicationManager::ChooseGate(int x, int y) {
	for (int i = 0; i < CompCount; i++)
	{
		if (checkInsideArea(x, y, CompList[i]))
		{
			if (dynamic_cast <Gates*> (CompList[i])) {
				Gates* gate = dynamic_cast <Gates*> (CompList[i]);
				return gate;
			}
		}
	}
	return NULL;
}

// Take a click from a user, then returtn the gate that the click is inside a area of it. 
Connection* ApplicationManager::ChooseConnection(int x, int y) {
	for (int i = 0; i < CompCount; i++)
	{
		if (checkInsideArea(x, y, CompList[i]))
		{
			if (dynamic_cast <Connection*> (CompList[i])) {
				Connection* Conn = dynamic_cast <Connection*> (CompList[i]);
				return Conn;
			}
		}
	}
	return NULL;
}
//////////////////////////////////////////////////////////////////

// return array that have all Switches in the circuit
SWITCH** ApplicationManager::GetSwitchs(int& n) {
	SWITCH* arr[20]; //max
	n = 0;
	for (int i = 0; i < CompCount; i++) {
		SWITCH* ptr = dynamic_cast<SWITCH*>(CompList[i]);
		if (ptr) {
			arr[n] = ptr;
			n++;
		}
	}
	return arr;
}

/* Returns a array of all switchs */
SWITCH * ApplicationManager::changeSwitch(int x,int y) {
	for (int i = 0; i < CompCount; i++)
	{
		if (checkInsideArea(x, y, dynamic_cast <SWITCH*> (CompList[i])))
		{
			return dynamic_cast <SWITCH*> (CompList[i]);
		}
	}
	return NULL;
}

// Cascade gates
void ApplicationManager::Cascade() {
	bool c = true;
	while (c && CompCount != 0)
	{
		for (int i = 0; i < CompCount; i++)
		{
			if (dynamic_cast<Gates*>(CompList[i]))
			{
				Gates* G = dynamic_cast<Gates*>(CompList[i]);
				for (int j = 0; j < G->getNumInputs(); j++)
				{
					bool t = true;

					if (CompList[i]->GetInputPinStatus(j) == UNSIGNED) {
						t = false;
					}

					if (t)
					{
						CompList[i]->Operate();
						CompList[i]->setStimulate(true);
					}
				}
			}

			if (dynamic_cast<Connection*>(CompList[i]))
			{
				if (dynamic_cast<Connection*>(CompList[i])->getSourcePin()->getStatus() != UNSIGNED)
				{
					CompList[i]->Operate();
					CompList[i]->setStimulate(true);
				}
			}
		}

		for (int i = 0; i < CompCount; i++) {
			if (CompList[i]->getStimulate() == false)
			{
				c = true;
				break;
			}
			else {
				c = false;
			}
		}
	}
}

////////////////////////////////////////////////////////////////////
//  Get Component by ID
Gates* ApplicationManager::getById(int id) {
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->GetID() == id) {
			return dynamic_cast <Gates*> (CompList[i]);
		}
	}
}

////////////////////////////////////////////////////////////////////

//set and get for clipboard
void ApplicationManager::setClipboard(Component* Clipboard){
	this->Clipboard = Clipboard;
}

Component* ApplicationManager::getClipboard() {
	return Clipboard;
}

/////////////////////////////////////////////////////////////////////

// Save File
void ApplicationManager::save(ofstream* outF) {
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i] != NULL) {
			if (dynamic_cast <Gates*> (CompList[i]))
			{
				// Save Gate
				CompList[i]->save(outF);
			}
		}
	}
	// Print Connections
	*outF << endl << "Connections" << endl;
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i] != NULL) {
			if (dynamic_cast <Connection*> (CompList[i]))
			{
				// Save Connection
				CompList[i]->save(outF);
			}
		}
	}
	// Print -1 in the end
	*outF << "-1";
}

bool ApplicationManager::load(ifstream* inF) {

	Action* pAct;

	string ComponentName;

	// Gates variables
	GraphicsInfo loadGfx;
	string label;
	int idNum;

	// Connections variables
	int SourceId;
	int DestId;
	int PinId = 0;


	int i = 0;

	// If Component
	while (*inF >> ComponentName && ComponentName != "-1" && ComponentName != "Connections") {
		if (inF->eof()) {
			break;
		}
		*inF >> idNum;
		*inF >> label;
		*inF >> loadGfx.x1 >> loadGfx.y1 >> loadGfx.x2 >> loadGfx.y2;

		if (ComponentName == "And2")
			pAct = new AddANDgate2(this, true);
		else if (ComponentName == "OR2")
			pAct = new AddORgate2(this, true);
		else if (ComponentName == "NOT")
			pAct = new AddINVgate(this, true);
		else if (ComponentName == "NAND2")
			pAct = new AddNANDgate2(this, true);
		else if (ComponentName == "NOR2")
			pAct = new AddNORgate2(this, true);
		else if (ComponentName == "XOR2")
			pAct = new AddXORgate2(this, true);
		else if (ComponentName == "XNOR2")
			pAct = new AddXNORgate2(this, true);
		else if (ComponentName == "And3")
			pAct = new AddANDgate3(this, true);
		else if (ComponentName == "NOR3")
			pAct = new AddNORgate3(this, true);
		else if (ComponentName == "XOR3")
			pAct = new AddXORgate3(this, true);
		else if (ComponentName == "BUFFER")
			pAct = new AddBuffgate(this, true);
		else if (ComponentName == "SWITCH")
			pAct = new AddSwitchgate(this, true);
		else if (ComponentName == "LED")
			pAct = new AddLEDgate(this, true);

		pAct->Execute();
		delete pAct;
		CompList[i]->load(idNum, label, loadGfx);
		i++;
	}

	// If Connections
	while (*inF >> SourceId, SourceId != -1) {
		*inF >> DestId;
		*inF >> PinId;

		Gates* DestG = getById(DestId);
		Gates* SourceG = getById(SourceId);

		pAct = new AddConnection(this, true, SourceG, DestG, PinId);
		pAct->Execute();
		delete pAct;
	}
	return true;
}

////////////////////////////////////////////////////////////////////
ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

/* Releases all the memory used by the components */
void ApplicationManager::deleteAll() {
	for (int i = 0; i < CompCount; i++) {
		delete CompList[i];
	}

	CompCount = 0;
	for (int i = 0; i < MaxCompCount; i++) {
		CompList[i] = NULL; 
	}
}

/* Make all components selected */
void ApplicationManager::selectAll() {
	for (int i = 0; i < CompCount; i++) {
		CompList[i]->SetSelect(true);
	}
}


/* Make all components selected */
void ApplicationManager::unselectAll() {
	for (int i = 0; i < CompCount; i++) {
		CompList[i]->SetSelect(true);
	}
}

////////////////////////////////////////////////////////////////////
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
		case ADD_Gate_Menu:
			pAct = new AddGateMenu(this);
			break;

		case ADD_AND_GATE_2:
			pAct = new AddANDgate2(this,false);
			break;

		case ADD_OR_GATE_2:
			pAct = new AddORgate2(this, false);
			break;

		case ADD_NAND_GATE_2:
			pAct = new AddNANDgate2(this, false);
			break;

		case ADD_NOR_GATE_2:
			pAct = new AddNORgate2(this, false);
			break;

		case ADD_XOR_GATE_2:
			pAct = new AddXORgate2(this, false);
			break;

		case ADD_XNOR_GATE_2:
			pAct = new AddXNORgate2(this, false);
			break;

		case ADD_AND_GATE_3:
			pAct = new AddANDgate3(this, false);

			break;

		case ADD_XOR_GATE_3:
			pAct = new AddXORgate3(this, false);
			break;

		case ADD_NOR_GATE_3:
			pAct = new AddNORgate3(this, false);
			break;

		case ADD_Buff:
			pAct = new AddBuffgate(this, false);
			break;

		case ADD_INV:
			pAct = new AddINVgate(this, false);
			break;

		case ADD_LED:
			pAct = new AddLEDgate(this, false);
			break;

		case ADD_Switch:
			pAct = new AddSwitchgate(this, false);
			break;

		case ADD_Label:
			pAct = new Label(this);
			break;

		case EDIT:
			pAct = new Edit(this);
			break;

		case ADD_CONNECTION:
			pAct = new AddConnection(this,false);
			break;

		case Change_Switch:
			pAct = new ChangeSwitch(this);
			break;

		case SELECT:
			pAct = new SelectG(this);
			break;

		case DEL:
			pAct = new Del(this);
			break;

		case MOVE:
			pAct = new Move(this);
			break;

		case SAVE:
			pAct = new Save(this);
			break;

		case LOAD:
			pAct = new Load(this);
			break;

		case COPY:
			pAct = new copyItem(this);
			CoORPa = false;
			break;

		case CUT:
			pAct = new cutItem(this);
			CoORPa = true;
			break;

		case PASTE:
			pAct = new paste(this,CoORPa);
			break;

		case SIM_MODE:
			pAct = new SIMMODE(this);
			break;

		case DSN_MODE:
			pAct = new DSNMODE(this);
			break;

		case EXIT:
			break;
	}

	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	Output* pOut = GetOutput();
	pOut->ClearDrawingArea();
	for (int i = 0; i < CompCount; i++){
		if (CompList[i] != NULL) {
			CompList[i]->Draw(OutputInterface);
		}
	}
		
}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i])
		{
			delete CompList[i];
		}
	}
	delete OutputInterface;
	delete InputInterface;
	
}