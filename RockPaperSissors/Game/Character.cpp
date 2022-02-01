#include "Character.hpp"
#include "MoveSelector.hpp"

Character::Character(unsigned int rockPower, unsigned int paperPower, unsigned int scissorPower, Move* move1, Move* move2) 
	: ImageGameObject("Fighter", "Assets/Blank Fighter - without arm.png", 0, 0, 1)
{
	this->_rockModifier = rockPower;
	this->_paperModifier = paperPower;
	this->_scissorModifier = scissorPower;

	this->health = new HealthBar(-25, -35, rockPower * 10);
	this->health->SetScale(0.17f);

	AddChild(health);

	MoveSelector* selector = new MoveSelector(move1, move2, -10, -100);
	AddChild(selector);

	equipWeapon(_paper);
	AddChild(new ImageGameObject("R - Arm", "Assets/Blank Fighter - arm.png", 2));
}

Character::~Character()
{
	ImageGameObject::~ImageGameObject();
}

void Character::equipWeapon(const ImageGameObject& weapon)
{
	if (_currentWeapon != nullptr)
	{
		delete _currentWeapon;
	}

	AddChild(new ImageGameObject(weapon));
	_currentWeapon = new ImageGameObject(weapon);
}
