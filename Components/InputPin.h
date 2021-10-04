#ifndef _INPUTPIN_H
#define _INPUTPIN_H

#include "Pin.h"
class Connection;	//Forward class declartion
class Component; //Forward class declaration

class InputPin: public Pin	//inherited from class Pin
{
protected:
	Component* pComp; //Component at which this pin is associated
	static int nextID; //Id of the Pin
	GraphicsInfo Gfx;
	Connection* m_Connection;

public:
	int id;
	InputPin();
	void setComponent(Component* pCmp);	//sets the component of this input pin
	Component* getComponent();	//returns the component of this input pin

	GraphicsInfo GetGfxInfo(); //return the place of the input Pin (X and Y)
	void SetGfxInfo(GraphicsInfo); //set the place of the input Pin (X and Y).

	Connection* getConnection();
	void setConnection(Connection*);

	void DeleteConnection();

	bool ConnectFrom(Connection* r_Conn);	//connect to a new connection
};

#endif