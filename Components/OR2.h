#ifndef _OR2_H
#define _OR2_H

#include <fstream>

/*
  Class
/*
  Class OR2
  -----------
  represent the 2-input OR gate
*/

#include "Gate.h"

class OR2:public Gates
{
public:
	OR2(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate

	virtual void save(ofstream *outputFile); // save file


	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int z);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int z, STATUS s);	//set status of Inputpin # n, to be used by connection class.


};

#endif