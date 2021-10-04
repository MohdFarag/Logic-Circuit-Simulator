#ifndef _GATE_H
#define _GATE_H

#include <fstream>

/*
  Class
/*
  Class Gate
  -----------
  - Base class for all types of gates
  - Each gate has n inputs pins and one output pin
*/


#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"

class Gates :public Component
{
protected:
	int m_Inputs;		//No. of input pins of that Gate.
	InputPin *m_InputPins;	//Array of input pins of the Gate
	OutputPin m_OutputPin;	//The Gate output pin
public:
	Gates(int r_Inputs, int r_FanOut);
	~Gates();

	//Get
	InputPin* getInputPins();
	InputPin getInputPinByN(int);
	OutputPin getOutputPin();
	int getNumInputs();
	
};

#endif
