#ifndef _cutItem_H
#define _cutItem_H

#include "action.h"
#include "../ApplicationManager.h"
#include "../Components/Gate.h"

#include "../Components\Component.h"
#include "..\Components\Connection.h"

class cutItem :	public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	Gates* Gate;

public:
	cutItem (ApplicationManager *pApp);
	virtual ~cutItem (void);

	//Reads parameters required for action to Execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

#endif