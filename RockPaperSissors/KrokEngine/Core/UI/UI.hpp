#pragma once
#include "Button.hpp"

class UI
{
public:
	~UI();
	std::vector<sf::Drawable*> GetDrawables();
	std::vector<Hoverable*> GetHoverables();

	void SetDefaultFont(sf::Font font);
	void SetDefaultFont(std::string fontFile);

	void AddElement(UIElement* uiElement);

	void RemoveElement(UIElement* uiElement);

	void RemoveUIElement(UIElement* uiElement);

	void RemoveHoverable(Hoverable* hoverable);

	std::vector<UIElement*> GetElements();

private:
	std::vector<UIElement*> _elements;
	std::vector<Hoverable*> _hoverables;
};

