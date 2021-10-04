#ifndef _Label_C
#define _Label_C

#include "Action.h"
#include "../Components/Component.h"

class Label : public Action
{
private:
	Component* Comp;
public:
	Label(ApplicationManager* pApp);
	virtual ~Label(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif