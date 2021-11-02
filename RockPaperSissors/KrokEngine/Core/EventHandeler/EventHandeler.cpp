#include "EventHandeler.hpp"
#include "../UI/Clickable.hpp"

EventHandeler::EventHandeler(sf::RenderWindow& renderWindow)
{
	_renderWindow = &renderWindow;
}

void EventHandeler::HandleEvent(sf::Event& event)
{
	if (!_focus)
	{
		if (event.type == sf::Event::GainedFocus)
		{
			_focus = true;
			_mouseInScreen = true;
			return;
		}

		return;
	}

	switch (event.type)
	{
	case sf::Event::Closed:
		this->_renderWindow->close();
		break;

	case sf::Event::LostFocus:
		_focus = false;
		break;

	case sf::Event::MouseLeft:
		_mouseInScreen = false;
		break;
	case sf::Event::MouseEntered:
		_mouseInScreen = true;
		break;
	case sf::Event::MouseMoved:
		if (_mouseInScreen)
		{
			sf::Vector2i mousePosition = sf::Mouse::getPosition(*_renderWindow);
			_mousePosition.SetXY(mousePosition.x, mousePosition.y);
		}
		break;
	case sf::Event::MouseButtonPressed:
		if (_mouseInScreen)
		{
			_mouseButtons[event.mouseButton.button] = true;
		}
		break;
	case sf::Event::MouseButtonReleased:
		if (_mouseInScreen)
		{
			_mouseButtons[event.mouseButton.button] = false;
		}
		break;

	case sf::Event::KeyPressed:
		if (_mouseInScreen)
		{
			_key[event.key.code] = true;
		}
		break;
	case sf::Event::KeyReleased:
		if (_mouseInScreen)
		{
			_key[event.key.code] = false;
		}
		break;
	}
}

const Vec2 EventHandeler::MousePosition()
{
	return _mousePosition;
}

const bool EventHandeler::IsPressed(sf::Keyboard::Key key)
{
	return _key[key];
}

const bool EventHandeler::IsPressed(sf::Mouse::Button mouseButton)
{
	return _mouseButtons[mouseButton];
}

const bool EventHandeler::Focus()
{
	return _focus;
}

void EventHandeler::HandleClicks(std::vector<Clickable*> clikcables, sf::Mouse::Button button)
{
	if (!IsPressed(button)) return;

	for (Clickable* clickable : clikcables)
	{
		if (clickable->IsInside(_mousePosition.x, _mousePosition.y))
		{
			clickable->OnClick();
		}
	}
}
