#ifndef _AddConnection_C
#define _AddConnection_C

#include "Action.h"
#include "../Components/Connection.h"
#include "../Components/Gate.h"


class AddConnection : public Action
{
private:
	GraphicsInfo GInfo;
	OutputPin* SrcPin;
	InputPin* DstPin;
	Gates* SrcGate;
	Gates* DstGate;

	int x, y;
	int IpinNum;

public:
	AddConnection(ApplicationManager* pApp, bool isLoaded, Gates* SrcGate = NULL, Gates* DstGate = NULL, int IpinNum = 0);
	virtual ~AddConnection(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif