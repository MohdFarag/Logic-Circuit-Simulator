#ifndef _Load_C
#define _Load_C

#include <string>
#include <iostream>
using namespace std;

#include "Action.h"
class Load : public Action
{
private:
	string str;
	ifstream* inF;
	bool isOpened;
	bool pre;
public:
	Load(ApplicationManager* pApp);
	virtual ~Load(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif