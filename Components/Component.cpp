#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo; 
	select = false; // not selected
	SetLabel("No_label"); // Default Label = " "
	setStimulate(false); // not stimulate yet
}

// Set Label
void Component::SetLabel(string s) {
	m_Label = s;
}

// Get Label
string Component::GetLabel() {
	return m_Label;
}

// Get Select
bool Component::GetSelect(){
	return select;
}

// Set Select
void Component::SetSelect(bool select){
	this->select = select;
}

// Get Gfx Info
GraphicsInfo Component::GetGfxInfo() {
	return m_GfxInfo;
}

// Set Gfx Info
void Component::SetGfxInfo(GraphicsInfo G){
	m_GfxInfo = G;

}

// Make Unique Id
int Component::GetID() {
	return id;
}

// Load File
void Component::load(int idNum, string label, GraphicsInfo Gfx) {

}

// Get Stimulate
bool Component::getStimulate() {
	return isStimulate;
}

// Set Stimulate 
void Component::setStimulate(bool set) {
	isStimulate = set;
}

void Component::DelDraw(Output* pOut) {
	pOut->DelDraw(m_GfxInfo);
}

// Start Count For ID
int Component::nextID = 0;

// Make Id decrease per Component
Component::Component(){
	id = ++nextID;
}

Component::~Component(){
	
}

