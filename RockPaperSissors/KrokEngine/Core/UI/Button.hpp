#pragma once
#include <functional>
#include "UIElement.hpp"
#include "Clickable.hpp"

class Button : public Clickable
{
public:
	Button(std::string name, std::string path, float x, float y, std::function<void()> action = NULL);
	Button(std::string name, float x, float y, std::function<void()> action = NULL);

	void setButtonAction(std::function<void()> action);

	virtual void OnClick() override;

	void LoadAlterateSprite(std::string path);

protected:
	virtual sf::Sprite* getSprite() override;

private:
	sf::Sprite _alternateSprite;
	sf::Texture _alternateTexture;

	std::function<void()> _onClickAction;
};

