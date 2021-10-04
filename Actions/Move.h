#ifndef _Move_C
#define _Move_C

#include "Action.h"
#include "../Components/Gate.h"
#include "../Components/Connection.h"
class Move : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int x, y;	//Center point of the gate
	Gates* Gate; //Gate that user want to move
public:
	Move(ApplicationManager* pApp);
	virtual ~Move(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif