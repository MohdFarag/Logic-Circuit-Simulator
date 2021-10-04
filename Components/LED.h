#ifndef _LED_H
#define _LED_H

#include <fstream>

/*
  Class

/*
  Class LED
  -----------
  represent the 1-input LED
*/

#include "Gate.h"

class LED:public Gates
{
public:
	LED(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 1-input gate

	virtual void save(ofstream *outputFile); // save file


	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int);	//returns status of Inputpin

	virtual void setInputPinStatus(int, STATUS);	//set status of Inputpin # n, to be used by connection class.


};

#endif