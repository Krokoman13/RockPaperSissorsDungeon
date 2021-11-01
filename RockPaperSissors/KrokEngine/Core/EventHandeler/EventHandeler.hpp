#pragma once
#include <SFML/Graphics.hpp>
#include "../../Essentials/Vec2.hpp"

class UIElement;

class EventHandeler
{
public:
	EventHandeler(sf::RenderWindow& renderWindow);

	void HandleEvent(sf::Event& event);
	const Vec2 MousePosition();

	const bool IsPressed(sf::Keyboard::Key key);
	const bool IsPressed(sf::Mouse::Button mouseButton);

	const bool Focus();

private:
	sf::RenderWindow* _renderWindow;

	bool _focus = true;

	bool _mouseInScreen = true;
	Vec2 _mousePosition;
	bool _mouseButtons[sf::Mouse::Button::ButtonCount] = {false};

	bool _key[sf::Keyboard::Key::KeyCount] = { false };
};

