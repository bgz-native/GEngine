#pragma once

#include "GEngine/Core/Core.h"

namespace GEngine
{

enum class EventType
{
	None = 0,
	WindowsClose,
	AppTick, AppRender,
	MouseButtonReleased,
};

enum EventCategory
{
	None = 0,
	EventCategoryApplication = BIT(0),
	EventCategoryInput = BIT(1),
	EventCategoryKeyboard = BIT(2),
	EventCategoryeMouse = BIT(3),
};

class GENGINE_API Event
{

public:
	virtual EventType GetEventType() const = 0;
	virtual const char* GetName() const = 0;
	virtual int GetEventCategoryFlags() const = 0;

	inline bool IsInCategory(EventCategory category)
	{
		return GetEventCategoryFlags() & category;
	}

protected:
	bool m_handled = false;
};




}