#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"

//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	string m_Label;
	bool isStimulate;
protected:
	static int nextID;
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	bool select;

public:
	int id;
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	
	virtual void save(ofstream *outputFile) = 0;		//save file
	void load(int ,string ,GraphicsInfo);	    //load file
	
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	
	//NOT VIRTUAL
	GraphicsInfo GetGfxInfo(); //return the place of the component (X and Y)
	void SetGfxInfo(GraphicsInfo); //set  the place of the component (X and Y), to be used by move, copy and paste action class etc..

	void SetLabel(string);
	string GetLabel();

	int GetID();
	
	bool GetSelect();
	void SetSelect(bool select);

	bool getStimulate();
	void setStimulate(bool set);
	
	//Delete draw of Gate
	void DelDraw(Output*);

	Component();	
	//Destructor must be virtual
	virtual ~Component();
};

#endif
