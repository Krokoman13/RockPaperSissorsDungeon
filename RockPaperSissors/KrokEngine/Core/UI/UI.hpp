#pragma once
#include "Button.hpp"

class UI
{
public:
	std::vector<sf::Drawable*> GetDrawables();
	std::vector<Hoverable*> GetClickables();

	void SetDefaultFont(sf::Font font);
	void SetDefaultFont(std::string fontFile);

	void AddElement(UIElement& uiElement);
	void AddElement(UIElement* uiElement);

	void RemoveElement(UIElement& uiElement);
	void RemoveElement(UIElement* uiElement);

private:
	std::vector<UIElement*> _elements;
	std::vector<Hoverable*> _hoverables;
};

