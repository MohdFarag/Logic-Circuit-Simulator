#include "NAND2.h"

NAND2::NAND2(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gates(2, r_FanOut)
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

		GInfo.y1 = GInfo.y1 = this->m_GfxInfo.y1 + 10 * (i + 1);
		m_InputPins[i].SetGfxInfo(GInfo);
	}
}


void NAND2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
	m_OutputPin = LOW;
	for (int Ni = 0; Ni < 2; Ni++)
	{
		if (m_InputPins[Ni+1].getStatus() == LOW)  m_OutputPin = HIGH;
	}
	
}


// Function Draw
// Draws 2-input NAND gate
void NAND2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if (select == false) {
		pOut->DrawNAND2(m_GfxInfo);
	}
	else {
		pOut->DrawNAND2(m_GfxInfo, true);
	}
	pOut->reDrawLabel(m_GfxInfo, GetLabel());
}

void NAND2::save(ofstream *outputFile) {
	int idNum = id;
	string label = GetLabel();
	int x1 = m_GfxInfo.x1;
	int x2 = m_GfxInfo.x2;
	int y1 = m_GfxInfo.y1;
	int y2 = m_GfxInfo.y2;

	*outputFile << "NAND2" << "\t" << idNum << "\t" << label << "\t" << x1 << "\t" << y1 << "\t" << x2 << "\t" << y2 << endl;
} // save file

//returns status of outputpin
int NAND2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NAND2::GetInputPinStatus(int Nn)	
{
	return m_InputPins[Nn-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NAND2::setInputPinStatus(int Nn, STATUS s)
{
	m_InputPins[Nn-1].setStatus(s);
}
