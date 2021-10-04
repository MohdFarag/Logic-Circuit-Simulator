#ifndef _Delete_Gate_H
#define _Delete_Gate_H

#include "action.h"

class Del : public Action
{

public:
	Del(ApplicationManager* pApp);
	virtual ~Del(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif