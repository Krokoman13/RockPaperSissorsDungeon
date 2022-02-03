#include "EventHandeler.hpp"
#include "../UI/Clickable.hpp"
#include "../UI/UI.hpp"

EventHandeler::EventHandeler(sf::RenderWindow& renderWindow)
{
	_renderWindow = &renderWindow;
}

void EventHandeler::HandleEvent(sf::Event& event, UI* ui)
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
			setHovering(ui->GetHoverables());
		}
		break;
	case sf::Event::MouseButtonPressed:
		if (_mouseInScreen)
		{
			_mouseButtons[event.mouseButton.button] = true;
			HandleClicks(event.mouseButton.button);
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
	default:
		return;
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

void EventHandeler::HandleClicks(sf::Mouse::Button button)
{
	for (size_t i = _hoveringOver.size(); i != 0; i--)
	{
		Clickable* clickable = dynamic_cast<Clickable*>(_hoveringOver[i-1]);

		if (clickable)
		{
			if (clickable->onClickButton == button)
			{
				clickable->OnClick();
				return;
			}
		}
	}
}

void EventHandeler::setHovering(const std::vector<Hoverable*>& hoverables)
{
	while (_hoveringOver.size() > 0)
	{
		_hoveringOver[_hoveringOver.size() - 1]->hovering = false;
		_hoveringOver.pop_back();
	}

	for (Hoverable* hoverable : hoverables)
	{
		if (hoverable == nullptr) continue;

		if (hoverable->IsInside(_mousePosition.x, _mousePosition.y))
		{
			hoverable->hovering = true;
			_hoveringOver.push_back(hoverable);
		}
	}
}
