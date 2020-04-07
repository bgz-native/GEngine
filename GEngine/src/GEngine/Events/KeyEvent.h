#pragma once

#include "Event.h"

namespace GEngine
{

class GENGINE_API KeyEvent : public Event
{
public:
	inline int GetKeyCode() const { return m_keyCode; }

protected:
	KeyEvent(int keyCode) : m_keyCode(keyCode) {}

	int m_keyCode;

};

class GENGINE_API KeyPressedEvent : public KeyEvent
{
public:
	KeyPressedEvent(int keyCode, int repeatCount)
		: KeyEvent(keyCode), m_repeatCount(repeatCount) {}

	inline int GetRepeatCounbt() const { return m_repeatCount; }

private:
	int m_repeatCount;
};

//TODO implement interface functions via macro

}

