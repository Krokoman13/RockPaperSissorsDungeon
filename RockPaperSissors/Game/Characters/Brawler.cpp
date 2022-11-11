#include "Brawler.hpp"
#include "../Moves/DefaultShieldMove.hpp"
#include "../Moves/DefaultBallMove.hpp"

Brawler::Brawler(unsigned int rockPower, unsigned int paperPower, unsigned int scissorPower, unsigned int move1, unsigned int move2, bool NPC)
	: Character(NPC, rockPower, paperPower, scissorPower, GetMove(move1), GetMove(move2 + 3), "Brawler", "Assets/Blank Tank - without arm.png")
{
	AddChild(new ImageGameObject("R - Arm", "Assets/Blank Tank - arm.png", 2));
}

Move* Brawler::GetMove(unsigned int i)
{
	switch (i)
	{
	case 0:
		return new DefaultBallMove(Element::Rock, 1);

	case 1:
		return new DefaultBallMove(Element::Paper, 1);

	case 2:
		return new DefaultBallMove(Element::Scissors, 2);

	case 3:
		return new DefaultShieldMove(Element::Rock);

	case 4:
		return new DefaultShieldMove(Element::Paper);

	case 5:
		return new DefaultShieldMove(Element::Scissors);

	default:
		return nullptr;
	}
}
