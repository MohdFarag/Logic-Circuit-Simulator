#ifndef _NAND2_H
#define _AND2_H

#include <fstream>

/*
  Class
/*
  Class NAND2
  -----------
  represent the 2-input NAND gate
*/

#include "Gate.h"

class NAND2:public Gates
{
public:
	NAND2(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate

	virtual void save(ofstream *outputFile); // save file


	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int Nn);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int Nn, STATUS s);	//set status of Inputpin # n, to be used by connection class.


};

#endif