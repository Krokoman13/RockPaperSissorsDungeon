#include "DefaultHealMove.hpp"
#include "../Characters/Character.hpp"
#include "../Arena.hpp"
#include <vector>

void DefaultHealMove::executeMove(Character& moveUser)
{
	unsigned int totalHealAmount = power * moveUser.GetModifier(element);

	for (Character* target : _targets)
	{
		if (target == nullptr) return;

		unsigned int healAmount = target->health->GetMaxHealth() - target->health->GetCurrentHealth();
		if (healAmount > totalHealAmount) healAmount = totalHealAmount;

		target->HealDamage(healAmount, iconName + " from: " + moveUser.name);

		totalHealAmount -= healAmount;
		if (totalHealAmount < 1) break;
	}
}

DefaultHealMove::DefaultHealMove(Element element, unsigned int power) : Move(element, Move::Type::Boost, power, ToString(element) + "Heal")
{
	this->explanation = "Heals the lowest health ally using " + ToString(element) + " (acces healing goes to other allies).";
}

void DefaultHealMove::SetTargets(Arena* arena, bool NPC)
{
	std::vector<Character*> damagedAllies;

	for (int i = 0; i < 4; i++)
	{
		Character* character = NPC ? arena->GetNPC(i) : arena->GetPC(i);
		if (character == nullptr || !character->IsDamaged()) continue;
		damagedAllies.push_back(character);
	}

	while (damagedAllies.size() > 0)
	{
		Character* lowestHealthAlly = nullptr;
			
		for (Character* ally : damagedAllies)
		{
			if (lowestHealthAlly == nullptr)
			{
				lowestHealthAlly = ally;
				continue;
			}

			if (ally->health->GetCurrentHealth() < lowestHealthAlly->health->GetCurrentHealth())
			{
				lowestHealthAlly = ally;
			}
		}

		for (unsigned int i = 0; i < damagedAllies.size(); i++)
		{
			if (damagedAllies[i] == lowestHealthAlly)
			{
				damagedAllies.erase(damagedAllies.begin() + i);
				continue;
			}
		}

		_targets.push_back(lowestHealthAlly);
	}

	return;
}

void DefaultHealMove::ExecuteMove(Character& moveUser)
{
	SetTargets(moveUser.arena, moveUser.NPC);

	executeMove(moveUser);

	_targets.clear();
}
