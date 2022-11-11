#pragma once
#include <deque>
#include <vector>

class Move;
class Character;

class MoveExecuter
{
public:
	MoveExecuter(const std::vector<Character*>& PCs, const std::vector<Character*>& NPCs);
	MoveExecuter();
	~MoveExecuter();

	void Step(bool forceContinue = false);
	const bool Done();

private:
	void addCharacterWithSpeed(unsigned int i, const std::vector<Character*>& PCs, const std::vector<Character*>& NPCs);
	static unsigned int characterCount(const std::vector<Character*>& PCs, const std::vector<Character*>& NPCs);

	std::deque<Character*> _charactersInOrder;

	bool _done = false;
	unsigned int _delay;
};

