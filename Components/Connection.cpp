#include "Connection.h"
#include "../Components/Gate.h"

Connection::Connection(const GraphicsInfo& r_GfxInfo, OutputPin* pSrcPin, InputPin* pDstPin, int IpinNum, Component* SrcCmpnt, Component* DstCmpnt):Component(r_GfxInfo)
{
	setSrcComp(SrcCmpnt);
	setDistComp(DstCmpnt);
	this->IpinNum = IpinNum;
	setStimulate(false);
	SrcPin = pSrcPin;
	DstPin = pDstPin;

	SrcPin->setConnected(true);
}

void Connection::setSourcePin(OutputPin *pSrcPin)
{
	if (pSrcPin->ConnectTo(this)) {
		SrcPin = pSrcPin;
	}
}

OutputPin* Connection::getSourcePin(){
	return SrcPin;	
}


void Connection::setDestPin(InputPin *pDstPin)
{	
	if (pDstPin->ConnectFrom(this))
	{
		DstPin = pDstPin;
	}
}

InputPin* Connection::getDestPin(){	
	return DstPin;	
}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	//getDestPin()->setStatus(getSourcePin()->getStatus());

	STATUS S = UNSIGNED;
	
	if (dynamic_cast <Gates*> (SrcCmpnt)->GetOutPinStatus() == 1) S = HIGH;
	else if(dynamic_cast <Gates*> (SrcCmpnt)->GetOutPinStatus() == 0) S = LOW;

	dynamic_cast <Gates*> (DstCmpnt)->setInputPinStatus(IpinNum,S);
}


void Connection::Draw(Output* pOut)
{
	if (select == true) {
		pOut->DrawConnection(m_GfxInfo,true);
	}
	else {
		pOut->DrawConnection(m_GfxInfo);
	}

	GraphicsInfo x_GfxInfo;
	x_GfxInfo = m_GfxInfo;
	x_GfxInfo.x1 = m_GfxInfo.x1 + 20;
	x_GfxInfo.x2 = m_GfxInfo.x2 + 20;

	pOut->reDrawLabel(x_GfxInfo, GetLabel());
}

void Connection::save(ofstream *outputFile){
	int DestId = DstCmpnt->GetID();
	int SourceId = SrcCmpnt->GetID();

	int NumPin = IpinNum;

	*outputFile << SourceId << "\t" << DestId << "\t" << NumPin <<endl;
}

//returns status of outputpin if LED, return -1
int Connection::GetOutPinStatus() 	
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}

///////////////////////////////////////////////////
/// set and get for source component

void Connection::setSrcComp(Component* Srcomp) {
	SrcCmpnt = Srcomp;
}

Component* Connection::getSrcComp() {
	return SrcCmpnt;
}

///////////////////////////////////////////////////

// set and get for distination component
void Connection::setDistComp(Component* Dstcomp) {
	DstCmpnt = Dstcomp;
}


Component* Connection::getDistComp() {
	return DstCmpnt;
}

