#include "DefaultShieldMove.hpp"
#include "../Characters/Character.hpp"
#include "../Arena.hpp"

DefaultShieldMove::DefaultShieldMove(Element element) : Move(element, Move::Type::Attack, 0U, ToString(element) + "Shield")
{
	this->explanation = "Shields self with " + ToString(element) + " shield.";
}

void DefaultShieldMove::SetTargets(Arena* arena, bool NPC)
{
}

//for (unsigned int i = 0; i < 4; i++)
//{
//	Character* target = NPC ? arena->GetPC(i) : arena->GetNPC(i);
//
//	if (target == nullptr) return;
//
//	if (target->GetShield() != Element::NONE) continue;
//
//	_targets.push_back(target);
//}

void DefaultShieldMove::executeMove(Character& moveUser)
{
	moveUser.SetShield(element);
}
