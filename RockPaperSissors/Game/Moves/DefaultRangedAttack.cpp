#include "DefaultRangedAttack.hpp"
#include "../Arena.hpp"
#include "../Characters/Character.hpp"

DefaultRangedAttack::DefaultRangedAttack(Element element, unsigned int power) : Move(element, Move::Type::Attack, power, ToString(element) + "RangedAttack")
{
}

void DefaultRangedAttack::SetTargets(Arena* arena, bool NPC)
{
	for (int i = 3; i >= 0; i--)
	{
		Character* character = NPC ? arena->GetNPC(i) : arena->GetPC(i);
		if (character != nullptr)
		{
			_targets.push_back(character);
			return;
		}
	}
}

void DefaultRangedAttack::executeMove(Character& moveUser)
{
	for (Character* target : _targets)
	{
		if (target == nullptr) return;

		target->RecieveDamage(power + moveUser.GetModifier(element), element, iconName + " from: " + moveUser.name);
	}
}
