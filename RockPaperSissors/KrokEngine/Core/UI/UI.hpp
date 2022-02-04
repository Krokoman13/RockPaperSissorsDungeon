#pragma once
#include "Button.hpp"

class UI
{
public:
	~UI();
	void ClearUi();
	std::vector<sf::Drawable*> GetDrawables();
	std::vector<Hoverable*> GetHoverables();

	void SetDefaultFont(sf::Font font);
	void SetDefaultFont(std::string fontFile);

	void AddElement(UIElement* uiElement);

	void RemoveElement(UIElement* uiElement);

	const std::vector<UIElement*> GetElements();

private:
	std::vector<UIElement*> _elements = {};
};

