#ifndef _Buffer_H
#define _Buffer_H

#include <fstream>

/*
  Class Buffer
  -----------
  represent the 1-input Buffer gate
*/

#include "Gate.h"

class Buffer:public Gates
{
public:
	Buffer(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the Buffer gate
	virtual void Draw(Output* pOut);	//Draws 1-input gate

	virtual void save(ofstream *outputFile); // save file


	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int);	//returns status of Inputpin

	virtual void setInputPinStatus(int,STATUS s);	//set status of Inputpin # n, to be used by connection class.

};

#endif