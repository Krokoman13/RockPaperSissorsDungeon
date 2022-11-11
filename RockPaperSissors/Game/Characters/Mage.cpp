#include "Mage.hpp"
#include "../Moves/DefaultHealMove.hpp"
#include "../Moves/DefaultRangedAttack.hpp"

Mage::Mage(unsigned int rockPower, unsigned int paperPower, unsigned int scissorPower, unsigned int move1, unsigned int move2, bool NPC)
	: Character(NPC, rockPower, paperPower, scissorPower, GetMove(move1), GetMove(move2), "Mage", "Assets/Blank Mage - without arm.png")
{
	AddChild(new ImageGameObject("R - Arm", "Assets/Blank Mage - arm.png", 2));
}

Move* Mage::GetMove(unsigned int i)
{
	switch (i)
	{
	case 0:
		return new DefaultHealMove(Element::Paper, 3);

	case 1:
		return new DefaultRangedAttack(Element::Rock, 1);

	case 2:
		return new DefaultRangedAttack(Element::Paper, 1);

	case 3:
		return new DefaultRangedAttack(Element::Scissors, 3);

	default:
		return nullptr;
	}
}
