#include "Button.hpp"
#include <iostream>

Button::Button(std::string name, std::string path, float x, float y, std::function<void()> action) : Clickable(name, path, x, y)
{
	SetText(name);

	std::string tempPath = _fullpath;

	tempPath.insert(tempPath.size() - 4, "-2");
	std::cout << tempPath << "\n";
	LoadAlterateSprite(tempPath);
}

Button::Button(std::string name, float x, float y, std::function<void()> action) : Button(name, UIElement::ASSET_PATH, x, y, action)
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

void Button::LoadAlterateSprite(std::string path)
{
	if (_alternateTexture.loadFromFile(path))
	{
		this->_alternateSprite.setTexture(_alternateTexture);
		this->_alternateSprite.setOrigin(0, 0);
		return;
	}
}

sf::Sprite* Button::getSprite()
{
	if (hovering)
	{
		return &_alternateSprite;
	}
	else
	{
		return UIElement::getSprite();
	}
}
