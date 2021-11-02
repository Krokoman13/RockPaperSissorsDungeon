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

sf::Sprite* Button::getSprite()
{
	if (hovering)
	{
		sf::Sprite* sprite = new sf::Sprite(*UIElement::getSprite());
		sprite->setOrigin(sprite->getTextureRect().width, sprite->getTextureRect().height);
		sprite->setRotation(180.0f);
		//sprite->setOrigin(0,0);
		return sprite;
	}
	else
	{
		return UIElement::getSprite();
	}
}
