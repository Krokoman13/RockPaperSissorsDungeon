#include "HealthBar.hpp"

HealthBar::HealthBar(int x, int y, int maxHealth) : GameObject(x, y, "HealthBar"), _bar("RedBar", "Assets/UI/HealthBar/", x, y), _counter("BorderBar", "Assets/UI/HealthBar/", x, y)
{
	this->_counter.SetText(std::to_string(maxHealth) + '/' + std::to_string(maxHealth), 80);
	this->_currentHealth = _maxHealth = maxHealth;
}

HealthBar::HealthBar(const HealthBar& other) : _bar(other._bar), _counter(other._counter)
{
	operator=(other);
}


HealthBar& HealthBar::operator=(const HealthBar& other)
{
	GameObject::operator=(other);

	if (this != &other)
	{
		this->_maxHealth = other._maxHealth;
		this->_currentHealth = other._currentHealth;

		this->_bar = other._bar;
		this->_counter = other._counter;
	}

	return *this;
}

GameObject* HealthBar::Copy()
{
	return new HealthBar(*this);
}

HealthBar::~HealthBar()
{
	GameObject::~GameObject();
	_bar.~UIElement();
	_counter.~UIElement();
}

void HealthBar::SetHealth(int amount)
{
	if (amount > _maxHealth) amount = _maxHealth;
	else if (amount < 0) amount = 0;

	this->_currentHealth = amount;
	this->_counter.SetText(std::to_string(_currentHealth) + '/' + std::to_string(_maxHealth), 80);
}

void HealthBar::Update()
{
	Vec2 pos = this->GetGlobaPosition();

	_bar.x = _counter.x = pos.x;
	_bar.y = _counter.y = pos.y;

	Vec2 scale = this->GetScale();

	_bar.SetScale((float)_currentHealth / (float)_maxHealth * scale.x, scale.y);
	_counter.SetScale(scale.x, scale.y);
}

void HealthBar::OnLoad()
{
	this->_scene->ui.AddElement(this->_counter);
	this->_scene->ui.AddElement(this->_bar);
}
