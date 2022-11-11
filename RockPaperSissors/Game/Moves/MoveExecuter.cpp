#include "MoveExecuter.hpp"
#include "../Characters/Character.hpp"

MoveExecuter::MoveExecuter(const std::vector<Character*>& PCs, const std::vector<Character*>& NPCs)
{
	unsigned int count = characterCount(PCs, NPCs);

	unsigned int i = 0;

	while (_charactersInOrder.size() < count)
	{
		addCharacterWithSpeed(i, PCs, NPCs);
		i++;
	}
}

MoveExecuter::MoveExecuter() : _charactersInOrder()
{
	this->_delay = 0u;
}

MoveExecuter::~MoveExecuter()
{
	_charactersInOrder.clear();
}

void MoveExecuter::Step(bool forceContinue)
{
	if (_done) return;
	
	if (_charactersInOrder.size() == 0)
	{
		_done = true;
		return;
	}

	if (_delay < 1000u && !forceContinue)
	{
		_delay++;
		return;
	}

	_charactersInOrder.back()->ExecuteMove();
	_charactersInOrder.pop_back();
	_delay = 0u;
}

const bool MoveExecuter::Done()
{
	return _done;
}

void MoveExecuter::addCharacterWithSpeed(unsigned int value, const std::vector<Character*>& PCs, const std::vector<Character*>& NPCs)
{
	for (int i = 0; i < 4; i++)
	{
		Character* pc = PCs[i];
		Character* npc = NPCs[i];

		if (pc == nullptr)
		{
			if (npc == nullptr) return;
		}
		else
		{
			if (pc->GetPaperModifier() == value) _charactersInOrder.push_back(pc);
		}

		if (npc != nullptr)
		{
			if (npc->GetPaperModifier() == value) _charactersInOrder.push_back(npc);
		}
	}
}

unsigned int MoveExecuter::characterCount(const std::vector<Character*>& PCs, const std::vector<Character*>& NPCs)
{
	unsigned int count = 0;

	for (int i = 0; i < 4; i++)
	{
		if (PCs[i] == nullptr) break;
		count++;
	}

	for (int i = 0; i < 4; i++)
	{
		if (NPCs[i] == nullptr) break;
		count++;
	}

	return count;
}
