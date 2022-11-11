#include "HealthBar.hpp"

HealthBar::HealthBar(float x, float y, int maxHealth)
	: GameObject(x, y, "HealthBar") 
{
	_bar = nullptr;
	_counter = nullptr;
	_currentHealth = _maxHealth = maxHealth;
}

HealthBar::~HealthBar()
{
	delete _bar;
	delete _counter;
}

void HealthBar::SetHealth(const int pAmount)
{
	int amount = pAmount;
	if (amount > _maxHealth) amount = _maxHealth;
	else if (amount < 0) amount = 0;

	this->_currentHealth = amount;
	this->_counter->SetText(std::to_string(_currentHealth) + '/' + std::to_string(_maxHealth));
}

int HealthBar::GetHealth()
{
	return _currentHealth;
}

void HealthBar::AddHealth(unsigned int amount)
{	
	SetHealth(_currentHealth + amount);
}

void HealthBar::SubstractHealth(unsigned int amount)
{
	SetHealth(_currentHealth - amount);
}

const unsigned int HealthBar::GetCurrentHealth() const
{
	return _currentHealth;
}

const unsigned int HealthBar::GetMaxHealth() const
{
	return _maxHealth;
}

void HealthBar::Update()
{
	Vec2 pos = globalPosition;

	_bar->x = _counter->x = pos.x;
	_bar->y = _counter->y = pos.y;

	Vec2 scale = globalScale;

	_bar->SetScale((float)_currentHealth / (float)_maxHealth * scale.x, scale.y);
	_counter->SetScale(scale.x, scale.y);
}

void HealthBar::OnLoad()
{
	_bar = new UIElement("RedBar", "Assets/UI/HealthBar/", globalPosition.x, globalPosition.y);
	_counter = new UIElement("BorderBar", "Assets/UI/HealthBar/", globalPosition.x, globalPosition.y);

	this->_counter->SetText(std::to_string(_maxHealth) + '/' + std::to_string(_maxHealth));

	_scene->ui->AddElement(_counter);
	_scene->ui->AddElement(_bar);
}
