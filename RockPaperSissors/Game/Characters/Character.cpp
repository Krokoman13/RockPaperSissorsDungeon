#include "Character.hpp"
#include "../Moves/MoveSelector.hpp"
#include "../Arena.hpp"
#include "../Moves/RockPaperSissorsElements.hpp"

Character::Character(bool NPC, unsigned int rockPower, unsigned int paperPower, unsigned int scissorPower, Move* move1, Move* move2, std::string name, std::string path)
	: ImageGameObject(name, path, 0, 0, 1)
{
	_rockModifier = rockPower;
	_paperModifier = paperPower;
	_scissorModifier = scissorPower;

	health = new HealthBar(-25, -35, rockPower * 10);
	health->SetScale(0.17f);
	AddChild(health);

	SetShield(Element::NONE);

	MoveSelector* selector = new MoveSelector(move1, move2, -10, -100);
	AddChild(selector);

	AddChild(new ImageGameObject("R - Arm", "Assets/Blank Fighter - arm.png", 2));
}

Character::~Character()
{
	if (arena != nullptr)
	{
		arena->RemoveCharacter(this);
	}
}

void Character::RecieveDamage(unsigned int amount, Element type, std::string sourceName)
{
	if (_shield == CounterTo(type))
	{
		SetShield(Element::NONE);
		return;
	}

	health->SubstractHealth(amount);
}

void Character::SetShield(Element shieldElement)
{
	_shield = shieldElement;
}

unsigned int Character::GetModifier(Element element)
{
	switch (element)
	{
	case Rock:
		return _rockModifier;
	case Paper:
		return _paperModifier;
	case Scissors:
		return _scissorModifier;
	default:
		return 0;
	}
}
