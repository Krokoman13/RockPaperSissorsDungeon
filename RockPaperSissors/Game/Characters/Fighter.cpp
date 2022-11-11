#include "Fighter.hpp"
#include "../Moves/DefaultSwordMove.hpp"

Fighter::Fighter(unsigned int rockPower, unsigned int paperPower, unsigned int scissorPower, unsigned int move1, unsigned int  move2, bool NPC)
	: Character(NPC, rockPower, paperPower, scissorPower, GetMove(move1), GetMove(move2), "Fighter", "Assets/Blank Fighter - without arm.png")
{
	AddChild(new ImageGameObject("R - Arm", "Assets/Blank Fighter - arm.png", 2));
}

Move* Fighter::GetMove(unsigned int i)
{
	switch (i)
	{
	case 0:
		return new DefaultSwordMove(Element::Rock, 2);

	case 1:
		return new DefaultSwordMove(Element::Paper, 1);

	case 2:
		return new DefaultSwordMove(Element::Scissors, 3);

	default:
		return nullptr;
	}
}
