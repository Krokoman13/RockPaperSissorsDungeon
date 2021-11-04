#include "HealthBar.hpp"
#include "../KrokEngine/KrokEngine.hpp"

HealthBar::HealthBar(int x, int y, int maxHealth) : GameObject(x, y)
{
	this->_bar = new UIElement("RedBar", "Assets/UI/HealthBar", x, y);
	this->_counter = new UIElement("EmptyBar", "Assets/UI/HealthBar", x, y);
	this->_counter->SetText(std::to_string(maxHealth) + '/' + std::to_string(maxHealth));

	this->_currentHealth = _maxHealth = maxHealth;

	this->getCurrentScene()->ui.AddElement(this->_bar);
	this->getCurrentScene()->ui.AddElement(this->_counter);
}

void HealthBar::SetHealth(int amount)
{
	if (amount > _maxHealth) amount = _maxHealth;
	else if (amount < 0) amount = 0;

	this->_currentHealth = amount;
}

void HealthBar::Update()
{
	Vec2 pos = this->GetGlobaPosition();

	_bar->x = _counter->x = pos.x;
	_bar->y = _counter->y = pos.y;
}
