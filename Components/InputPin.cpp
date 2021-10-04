#include "InputPin.h"

InputPin::InputPin(){
	id = ++nextID; // Id increase
	isConnected = false; // Not Connected
}

int InputPin::nextID = 0;


// Set And Get Component
void InputPin::setComponent(Component *pCmp)
{
	this->pComp = pCmp;
}

Component* InputPin::getComponent()
{
	return pComp;
}

// Get And Set GfxInfo
GraphicsInfo InputPin::GetGfxInfo() {
	return Gfx;
}

void InputPin::SetGfxInfo(GraphicsInfo G) {
	Gfx = G;

}

// Get Connection
Connection* InputPin::getConnection() {
	return m_Connection;
}
// Set Connection
void InputPin::setConnection(Connection* con) {
	m_Connection = con;
}

// Delete Connection
void InputPin::DeleteConnection() {
}

// Store Connection of that pin
bool InputPin::ConnectFrom(Connection* r_Conn) {
	if (isConnected == false) 
	{
		m_Connection = r_Conn;
		// Make its Statue is Connected
		setConnected(true);
		return true;
	}
	return false;
}