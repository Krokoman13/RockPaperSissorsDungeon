#include "Move.hpp"
#include "RockPaperSissorsElements.hpp"
#include "../Characters/Character.hpp"
#include "../Arena.hpp"

Move::Move(Element element, Type type, unsigned int strength, std::string iconName)
{
	this->element = element;
	this->type = type;
	this->power = strength;
	this->iconName = iconName;
}

void Move::ExecuteMove(Character& moveUser)
{
	SetTargets(moveUser.arena, !moveUser.NPC);

	executeMove(moveUser);

	_targets.clear();
}
