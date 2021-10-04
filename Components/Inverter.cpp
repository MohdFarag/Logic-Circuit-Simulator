#include "Inverter.h"

Inverter::Inverter(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gates(1, r_FanOut)
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

		GInfo.y1 = this->m_GfxInfo.y1 + 25;
		m_InputPins[i].SetGfxInfo(GInfo);
	}
}


void Inverter::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
	if (m_InputPins[0].getStatus() == HIGH) m_OutputPin = LOW;
	else m_OutputPin = HIGH;
}


// Function Draw
// Draws 1-input Buffer gate
void Inverter::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if (select == false) {
		pOut->DrawInverter(m_GfxInfo);
	}
	else {
		pOut->DrawInverter(m_GfxInfo, true);
	}
	pOut->reDrawLabel(m_GfxInfo, GetLabel());
}

void Inverter::save(ofstream *outputFile) {
	int idNum = id;
	string label = GetLabel();
	int x1 = m_GfxInfo.x1;
	int x2 = m_GfxInfo.x2;
	int y1 = m_GfxInfo.y1;
	int y2 = m_GfxInfo.y2;

	*outputFile << "NOT" << "\t" << idNum << "\t" << label << "\t" << x1 << "\t" << y1 << "\t" << x2 << "\t" << y2 << endl;
} // save file



//returns status of outputpin
int Inverter::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int Inverter::GetInputPinStatus(int n)
{
	return m_InputPins[0].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void Inverter::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[0].setStatus(s);
}