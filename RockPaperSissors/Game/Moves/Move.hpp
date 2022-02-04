#pragma once
#include "RockPaperSissorsElements.hpp"
#include <string>
#include <vector>

class Character;
class Arena;

class Move
{
public:
	enum Type { Attack, Shield, Boost, Debuff };

	Move(Element element, Type type, unsigned int strength, std::string iconName);
	virtual ~Move() = default;

	Element element;

	Type type;

	unsigned int power = 1;
	std::string iconName;

	std::string explanation;

	virtual void ExecuteMove(Character& moveUser);
	virtual void SetTargets(Arena* arena, bool NPC = true) = 0;

protected: 
	virtual void executeMove(Character& moveUser) = 0;
	std::vector<Character*> _targets = {};
};



