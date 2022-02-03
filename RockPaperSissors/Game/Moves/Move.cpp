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
	SetTargets(moveUser.arena);

	executeMove(moveUser);

	_targets.clear();
}

void DefaultSwordMove::executeMove(Character& moveUser)
{
	for (Character* target : _targets)
	{
		if (target == nullptr) return;

		target->RecieveDamage(power * moveUser.GetModifier(element), element, iconName + " from: " + moveUser.name);
	}
}

DefaultSwordMove::DefaultSwordMove(Element element, unsigned int power) : Move(element, Move::Type::Attack, power, ToString(element) + "SwordAttack")
{
	this->explanation = "Attacks the first two enemies with a decent " + ToString(element) + " attack (damage increased with rock modifier)";
}

void DefaultSwordMove::SetTargets(Arena* arena, bool NPC)
{
	if (NPC)
	{
		_targets.push_back(arena->GetNPC(0));
		_targets.push_back(arena->GetPC(1));
	}
}
