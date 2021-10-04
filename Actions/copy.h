#ifndef _copyItem_H
#define _copyItem_H

#include "action.h"
#include "../ApplicationManager.h"
#include "../Components/Gate.h"

#include "../Components/Component.h"
#include "../Components/Connection.h"


class copyItem :	public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	Component* pComp;
public:
	copyItem(ApplicationManager *pApp);
	virtual ~copyItem(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

#endif