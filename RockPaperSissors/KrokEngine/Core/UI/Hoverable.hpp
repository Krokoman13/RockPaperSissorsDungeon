#pragma once
#include <string>
#include "UIElement.hpp"

class Hoverable :
    public UIElement
{
public:
	Hoverable(std::string name, std::string path, float x, float y);
	Hoverable(std::string name, float x, float y);
	//virtual void ClearUI() override;
	//virtual ~Hoverable() override;

	virtual const bool IsInside(const float x, const float y);
	bool hovering = false;
};

