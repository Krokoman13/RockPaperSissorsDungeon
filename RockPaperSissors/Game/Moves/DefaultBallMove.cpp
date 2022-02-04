#include "DefaultBallMove.hpp"
#include "../Characters/Character.hpp"
#include "../Arena.hpp"

DefaultBallMove::DefaultBallMove(Element element, unsigned int power) : Move(element, Move::Type::Attack, power, ToString(element) + "BallAttack")
{
	this->explanation = "Attacks all enemies with a " + ToString(element) + " attack deals less damage per enemy hit.";
}

void DefaultBallMove::SetTargets(Arena* arena, bool NPC)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		Character* target = NPC ? arena->GetNPC(i) : arena->GetPC(i);

		if (target == nullptr) return;

		_targets.push_back(target);
	}
}

void DefaultBallMove::executeMove(Character& moveUser)
{
	for (unsigned int i = 0; i < _targets.size(); i++)
	{
		unsigned int damage = (power * moveUser.GetModifier(element)) / (i > 0 ? (i * 2) : 1);

		Character* target = _targets[i];

		if (target == nullptr || damage <= 0) return;

		target->RecieveDamage(damage, element, iconName + " from: " + moveUser.name);
	}
}
