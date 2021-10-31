#pragma once
#include "UIElement.hpp"

class UI
{
public:
	std::vector<sf::Drawable*> GetDrawables();

	void SetDefaultFont(sf::Font font);
	void SetDefaultFont(std::string fontFile);

	void AddElement(UIElement& uiElement);
	void AddElement(UIElement* uiElement);
	void RemoveElement(UIElement& uiElement);

private:
	std::vector<UIElement*> _elements;
};

