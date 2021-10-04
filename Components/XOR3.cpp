#include "XOR3.h"

XOR3::XOR3(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gates(3, r_FanOut)
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

		GInfo.y1 = GInfo.y1 = this->m_GfxInfo.y1 + 8 * (i + 1);
		m_InputPins[i].SetGfxInfo(GInfo);
	}
}


void XOR3::Operate()
{
	//calculate the output status as the ANDing of the two input pins

	//Add you code here
	int c = 0;
	for (int j=0; j<3; j++)
	{
		if (m_InputPins[j].getStatus() == HIGH) c++;
	}
	if(c==1) m_OutputPin = HIGH; 
	else m_OutputPin = LOW;
}


// Function Draw
// Draws 3-input Xor gate
void XOR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if (select == false) {
		pOut->DrawXOR3(m_GfxInfo);
	}
	else {
		pOut->DrawXOR3(m_GfxInfo,true);
	}
	pOut->reDrawLabel(m_GfxInfo, GetLabel());
}
// save file
void XOR3::save(ofstream *outputFile) {
	int idNum = id;
	string label = GetLabel();
	int x1 = m_GfxInfo.x1;
	int x2 = m_GfxInfo.x2;
	int y1 = m_GfxInfo.y1;
	int y2 = m_GfxInfo.y2;

	*outputFile << "XOR3" << "\t" << idNum << "\t" << label << "\t" << x1 << "\t" << y1 << "\t" << x2 << "\t" << y2 << endl;
}

  //returns status of outputpin
int XOR3::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR3::GetInputPinStatus(int bb)	
{
	return m_InputPins[bb-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR3::setInputPinStatus(int kk, STATUS s)
{
	m_InputPins[kk-1].setStatus(s);
}
