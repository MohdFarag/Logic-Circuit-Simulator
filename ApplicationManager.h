#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"

#include "Components\Gate.h"
#include "Components\LED.h"
#include "Components\SWITCH.h"

#include "Actions\Action.h"
#include "Components\Component.h"
#include <fstream>

//Main class that manages everything in the application.
class ApplicationManager
{
	enum {
		MaxCompCount = 200 
	};	//Max no of Components	

private:
	Component* Clipboard;  // temporary storage for Copy and cut, will be used later for paste
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)

	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface
	bool CoORPa;

public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	/* Releases all the memory used by the components */
	void ApplicationManager::deleteAll();

	/* Make all components selected */
	void ApplicationManager::selectAll();

	/* Make all components selected */
	void ApplicationManager::unselectAll();

	/////////////////////////////////////////////////////////////////////
	//Adds a new component to the list of components
	void AddComponent(Component* pComp);

	//Delete a component from the list of components
	void DelComponent();
	void DelComponent(Component*);
	/////////////////////////////////////////////////////////////////////

	// return array that have all Switches in the circuit
	SWITCH* changeSwitch(int x,int y);

	// Find a selected component from the list of components
	Component * findSelectedComponent();

	// Select a component from the list of components (make select = true)
	Component* SelectComponent(int x, int y);

	// Take x and y and return gate
	Gates* ChooseGate(int x,int y);

	// Take x and y and return connection
	Connection* ChooseConnection(int x, int y);

	// Get gate by ID
	Gates* getById(int id);

	// Check If Click inside area of Component
	bool checkInsideArea(int x, int y, Component* Comp);

	/// Copy, Cut and Paste
	/// Here the functions that will be used in Copy, Cut and Paste.

	// Set for clipboard
	void setClipboard(Component*);
	// Get for clipboard
	Component* getClipboard();


	/// Save and Load
	/// Here the functions that will be used in Save and Load.

	// Save Component
	void save(ofstream*);
	// Load Component
	bool load(ifstream*);

	/// Stimulation
	/// Here the functions that will be used in Stimulation.

	// Return array that have all Switches in the circuit
	SWITCH** GetSwitchs(int& n);

	// Cascade the gate that stimulate
	void Cascade();

	//Destructor for applicaton manager
	~ApplicationManager();
};


#endif