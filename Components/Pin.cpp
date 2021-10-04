#include "Pin.h"

Pin::Pin()
{
	m_Status = UNSIGNED;	//Default Status is UNSIGNED
	isConnected = false; // Default Status is no Connected
}

// Set And Get for Status
void Pin::setStatus(STATUS r_Status)
{
	m_Status = r_Status;
}
STATUS Pin::getStatus()
{
	return m_Status;
}

// Set And Get for Connection
bool Pin::getisConnected() {
	return this->isConnected;
}
void Pin::setConnected(bool isConnected) {
	this->isConnected = isConnected;
}
