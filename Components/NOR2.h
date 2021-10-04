#ifndef _NOR2_H
#define _NOR2_H


#include <fstream>

/*
  Class
/*
  Class NOR2
  -----------
  represent the 2-input NOR gate
*/

#include "Gate.h"

class NOR2:public Gates
{
public:
	NOR2(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate

	virtual void save(ofstream *outputFile); // save file


	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int Nz);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int Nz, STATUS s);	//set status of Inputpin # n, to be used by connection class.


};

#endif