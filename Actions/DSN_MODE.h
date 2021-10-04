#ifndef _DSNMODE_C
#define _DSNMODE_C

#include "Action.h"
class DSNMODE : public Action
{
public:
	DSNMODE(ApplicationManager* pApp);
	virtual ~DSNMODE(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif