#ifndef _Inverter_H
#define _Inverter_H

#include <fstream>

/*
  Class Inverter
  -----------
  represent the 1-input Inverter gate
*/

#include "Gate.h"

class Inverter:public Gates
{
public:
	Inverter(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 1-input gate

	virtual void save(ofstream *outputFile); // save file


	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.


};

#endif