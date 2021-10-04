#ifndef _Save_C
#define _Save_C

#include <string>
#include <iostream>
using namespace std;

#include "Action.h"
class Save : public Action
{
private:
	string str;
	ofstream* outF;
	
public:
	Save(ApplicationManager* pApp);
	virtual ~Save(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif