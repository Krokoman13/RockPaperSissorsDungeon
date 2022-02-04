#pragma once
#include <deque>
#include <vector>

class Move;
class Character;

class MoveExecuter
{
public:
	MoveExecuter(std::vector<Character*>& PCs, std::vector<Character*>& NPCs);
	MoveExecuter();
	~MoveExecuter();

	void Step();
	const bool Done();

private:
	void addCharacterWithSpeed(unsigned int i, std::vector<Character*>& PCs, std::vector<Character*>& NPCs);
	static unsigned int characterCount(std::vector<Character*>& PCs, std::vector<Character*>& NPCs);

	std::deque<Character*> _charactersInOrder;

	bool _done = false;
	unsigned int _delay;
};

