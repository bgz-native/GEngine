#pragma once

#include "GEngine/Core/Core.h"

namespace GEngine
{

enum class EventType
{
	None = 0,
	WindowClose, WindowResize,
	//TODO WindowOnFocus, WindowOffFocus
	KeyPressed, KeyReleased,
	MouseButtonPressed, MouseButtonReleased, MouseMoved
};

enum EventCategory
{
	None = 0,
	EventCategoryApplication = BIT(0),
	EventCategoryInput = BIT(1),
	EventCategoryKeyboard = BIT(2),
	EventCategoryMouse = BIT(3),
};

// TODO Improve Macros
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetEventCategoryFlags() const override { return category; }


class GENGINE_API Event
{
public:
	virtual EventType GetEventType() const = 0;
	virtual const char* GetName() const = 0;

	//TODO Get specific logs for each events attributes
	virtual int GetEventCategoryFlags() const = 0;

	inline bool IsInCategory(EventCategory category)
	{
		return GetEventCategoryFlags() & category;
	}

	//inline bool getIsHandled() { return m_handled; }

//protected:
	bool handled = false;
};

class EventDispatcher
{
	template<typename T>
	using EventFn = std::function<bool(T&)>;

public:
	EventDispatcher(Event& event)
		: m_event(event) {}

	template<typename T>
	bool Dispatch(EventFn<T> func)
	{
		if (m_event.GetEventType() == T::GetStaticType())
		{
			m_event.handled = func(*(T*)&m_event);
			return true;
		}

		return false;
	}

private:
	Event& m_event;

};



}