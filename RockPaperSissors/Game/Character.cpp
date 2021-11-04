#include "Character.hpp"

Character::Character(unsigned int rockPower, unsigned int paperPower, unsigned int scissorPower) 
	: ImageGameObject("Fighter", "Assets/Blank Fighter - without arm.png", 0, 0, 1), _health(-25, -35, rockPower*10)
{
	this->_rockModifier = rockPower;
	this->_paperModifier = paperPower;
	this->_scissorModifier = scissorPower;

	this->_health.SetScale(0.17f);

	this->AddChild(_health);
	this->equipWeapon(_paper);
	this->AddChild(new ImageGameObject("R - Arm", "Assets/Blank Fighter - arm.png", 2));
}

void Character::equipWeapon(const ImageGameObject& weapon)
{
	if (_currentWeapon != nullptr)
	{
		delete _currentWeapon;
	}

	this->AddChild(new ImageGameObject(weapon));
	_currentWeapon = new ImageGameObject(weapon);
}
