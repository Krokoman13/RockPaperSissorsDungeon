#include "Button.hpp"
#include <iostream>

Button::Button(std::string name, std::string path, float x, float y, std::function<void()> action) : Clickable(name, path, x, y)
{
	SetText(name);
}

Button::Button(std::string name, float x, float y, std::function<void()> action) : Clickable(name, x, y)
{
	SetText(name);
}

void Button::setButtonAction(std::function<void()> action)
{
	this->_onClickAction = action;
}

void Button::OnClick()
{
	this->_onClickAction();
}

void Button::StartHover()
{
	this->_sprite.setOrigin(_sprite.getTextureRect().width, _sprite.getTextureRect().height);
	this->_sprite.setRotation(180.0f);
}

void Button::StopHover()
{
	this->_sprite.setOrigin(0, 0);
	this->_sprite.setRotation(0.0f);
}
