#ifndef _PASTE_H
#define _PASTE_H

#include "action.h"
#include "../ApplicationManager.h"

#include "..\Components\Component.h"
#include "..\Components\Connection.h"

class paste :	public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	Component* pAs; // Component that ypu paste it
	bool CoORPa; // Copy or Paste ?
public:
	paste(ApplicationManager *pApp,bool CoORPa=false);
	virtual ~paste(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif