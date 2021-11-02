#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "../../Essentials/Vec2.hpp"

class UIElement;
class Clickable;
class UI;

class EventHandeler
{
public:
	EventHandeler(sf::RenderWindow& renderWindow);

	void HandleEvent(sf::Event& event, UI& ui);
	const Vec2 MousePosition();

	const bool IsPressed(sf::Keyboard::Key key);
	const bool IsPressed(sf::Mouse::Button mouseButton);

	const bool Focus();

	void HandleClicks(sf::Mouse::Button button = sf::Mouse::Button::Left);

private:
	sf::RenderWindow* _renderWindow;

	bool _focus = true;

	bool _mouseInScreen = true;
	Vec2 _mousePosition;
	bool _mouseButtons[sf::Mouse::Button::ButtonCount] = {false};

	bool _key[sf::Keyboard::Key::KeyCount] = { false };
	std::vector<Clickable*> _toClick;

	void setToClick(std::vector<Clickable*> clickables);
};

