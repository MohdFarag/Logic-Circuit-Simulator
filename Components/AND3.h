#ifndef _AND3_H
#define _AND3_H

/*
  Class AND3
  -----------
  represent the 3-input AND gate
*/

#include "Gate.h"

class AND3:public Gates
{
public:
	AND3(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate

	virtual void save(ofstream *outputFile); // save file

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int nn);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int nn, STATUS s);	//set status of Inputpin # n, to be used by connection class.
};

#endif