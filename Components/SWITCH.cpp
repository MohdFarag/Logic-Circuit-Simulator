#include "SWITCH.h"

SWITCH::SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gates(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;

	GraphicsInfo GInfo;
	GInfo = this->m_GfxInfo;
	//Associate all input pins to this gate
	for (int i = 0; i < m_Inputs; i++) {
		m_InputPins[i].setComponent(this);
		m_InputPins[i].setConnected(false);
		GInfo.y1 = this->m_GfxInfo.y1 + 1 / 2 * UI.GATE_Height;
		m_InputPins[i].SetGfxInfo(GInfo);
	}

	setInputPinStatus(1, LOW);
}


void SWITCH::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
	//m_OutputPin.setStatus(m_OutputPin.getStatus() == HIGH ? LOW : HIGH ); // when you click on switch the output changes 1 <-> 0
	for (int i = 0; i < m_Inputs; i++)
	{
		m_OutputPin.setStatus(m_InputPins[i].getStatus());
	}
}


// Function Draw
// Draws 1-input SWITCH gate
void SWITCH::Draw(Output* pOut)
{
	Operate();
	//Call output class and pass gate drawing info to it.
	pOut->DrawSWTCH(m_GfxInfo, select, m_OutputPin.getStatus());
	

	pOut->reDrawLabel(m_GfxInfo, GetLabel());
}

void SWITCH::save(ofstream *outputFile) {
	int idNum = id;
	string label = GetLabel();
	int x1 = m_GfxInfo.x1;
	int x2 = m_GfxInfo.x2;
	int y1 = m_GfxInfo.y1;
	int y2 = m_GfxInfo.y2;

	*outputFile << "SWITCH" << "\t" << idNum << "\t" << label << "\t" << x1 << "\t" << y1 << "\t" << x2 << "\t" << y2 << endl;
} // save file

//returns status of outputpin
int SWITCH::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int SWITCH::GetInputPinStatus(int n)
{
	return -1;	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void SWITCH::setInputPinStatus(int n,STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
