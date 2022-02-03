#include "Fighter.hpp"
#include "../Moves/Move.hpp"

Fighter::Fighter(unsigned int rockPower, unsigned int paperPower, unsigned int scissorPower, unsigned int move1, unsigned int  move2, bool NPC)
	: Character(NPC, rockPower, paperPower, scissorPower, SelectMove(move1), SelectMove(move2), "Fighter", "Assets/Blank Fighter - without arm.png")
{
}

Move* Fighter::SelectMove(unsigned int i)
{
	switch (i)
	{
	case 0:
		return new DefaultSwordMove(Element::Rock, 2);

	case 1:
		return new DefaultSwordMove(Element::Paper, 2);

	case 2:
		return new DefaultSwordMove(Element::Scissors, 2);

	default:
		return nullptr;
	}
}
