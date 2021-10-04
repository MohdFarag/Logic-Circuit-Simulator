#ifndef _Edit_C
#define _Edit_C

#include "Action.h"
#include "../Components/Connection.h"
#include "../Components/Gate.h"
#include "AddConnection.h"

class Edit : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	// Center point of the gate
	Connection *Conn; // Choose the connection
	Gates* Src; // Choose the Source Gate
	Gates* Dst; // Choose the Distination Gate
	int IpinNum;

public:
	Edit(ApplicationManager* pApp);
	virtual ~Edit(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif