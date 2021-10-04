#ifndef _SWITCH_H
#define _SWITCH_H

#include <fstream>

/*
  Class
/*
  Class SWITCH
  -----------
  represent the 1-input SWITCH
*/

#include "Gate.h"

class SWITCH:public Gates
{

public:
	SWITCH(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 1-input gate

	virtual void save(ofstream *outputFile); // save file


	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int);	//returns status of Inputpin

	bool getOn(); // Get for On
	void setIsOn(bool); // Set for On
	

	virtual void setInputPinStatus(int n,STATUS s);	//set status of Inputpin # n, to be used by connection class.


};

#endif