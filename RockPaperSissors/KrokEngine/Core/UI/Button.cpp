#include "Button.hpp"
#include <iostream>

Button::Button(std::string name, std::string path, float x, float y, std::function<void()> action) : Clickable(name, path, x, y)
{
}

Button::Button(std::string name, float x, float y, std::function<void()> action) : Clickable(name, x, y)
{
}

void Button::setButtonAction(std::function<void()> action)
{
	this->_action = action;
}

void Button::OnClick()
{
	this->_action();
}
