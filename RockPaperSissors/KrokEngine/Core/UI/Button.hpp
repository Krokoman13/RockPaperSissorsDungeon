#pragma once
#include <functional>
#include "UIElement.hpp"
#include "Clickable.hpp"

class Button : public Clickable
{
public:
	Button(std::string name, std::string path, float x, float y, std::function<void()> action = NULL);
	Button(std::string name, float x, float y, std::function<void()> action = NULL);

	void setButtonAction(std::function<void()> action);
	virtual void OnClick() override;

private:
	std::function<void()> _action;
};

