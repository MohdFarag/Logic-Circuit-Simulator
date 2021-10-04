#ifndef _SelectG_C
#define _SelectG_C

#include "Action.h"
#include "..\Defs.h"
#include "../Components/Component.h"

class SelectG : public Action
{
private:
	int X, Y;	//Center point from click
	Component* Comp;
	GraphicsInfo C_GfxInfo; //Place of the component that select.
public:
	SelectG(ApplicationManager* pApp);
	virtual ~SelectG(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif