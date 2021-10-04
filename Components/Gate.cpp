#include "Gate.h"

//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gates::Gates(int r_Inputs, int r_FanOut):m_OutputPin(r_FanOut)
{
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate
	select = false;
	setStimulate(false);

	//Associate all input pins to this gate
	for (int i = 0; i < m_Inputs; i++) {
		m_InputPins[i].setComponent(this);
		m_InputPins[i].setConnected(false);
	}

	//Associate all output pins to this gate
	m_OutputPin.setComponent(this);

	SetLabel("No_label");

	setStimulate(false);

}

// Destructor of Gates class
Gates::~Gates() {
	// Delete All Connections of Gate
	for (int i = 0; i < getOutputPin().getNumConn(); i++) {
		delete getOutputPin().getConnection()[i];
	}
}

// Get input pins
InputPin *Gates::getInputPins() {
	return m_InputPins;
}

// Get input pin by N
InputPin Gates::getInputPinByN(int n) {
	for (int i = 0; i < m_Inputs; i++) {
		if (i == n) {
			return m_InputPins[i];
		}
	}
}

// Get Output pin
OutputPin Gates::getOutputPin() {
	return m_OutputPin;
}

// Get number of inputs
int Gates::getNumInputs(){
	return m_Inputs;
}
