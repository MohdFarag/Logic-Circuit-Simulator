#ifndef _SIMMODE_C
#define _SIMMODE_C

#include "Action.h"
#include "../Components/LED.h"

class SIMMODE : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	Component** VisitedComp;
public:
	SIMMODE(ApplicationManager* pApp);
	virtual ~SIMMODE(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif