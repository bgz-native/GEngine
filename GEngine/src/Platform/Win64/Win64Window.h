#pragma once

#include "GEngine/Core/Window.h"

namespace GEngine
{

struct Win64WindowProperty
{
	std::string title;
	unsigned int width;
	unsigned int height;
};


class Win64Window : public Window
{
	Win64Window();
	virtual ~Win64Window();

	void Update() override;

	inline unsigned int GetWidth() const override { return m_property.width; }
	inline unsigned int GetHeight() const override { return m_property.height; }

private:
	virtual void Start();
	virtual void Destroy();


private:
	Win64WindowProperty m_property;

};


}


