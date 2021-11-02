#pragma once
#include "UIElement.hpp"

class Clickable : public UIElement
{
public:
	Clickable(std::string name, std::string path, float x, float y);
	Clickable(std::string name, float x, float y);

	virtual void OnClick();
	virtual const bool IsInside(const int x, const int y);
};

