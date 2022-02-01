#pragma once
#include <string>

enum Element;
class Character;

class Move
{
public:
	enum Type { Attack, Shield, Boost };

	Move(Element element, Type type, unsigned int strength, std::string iconName);

	Element element;

	Type type;

	unsigned int strength = 1;
	std::string iconName;
	void SetTarget(Character* target);

	std::string explanation;

	//virtual void ExecuteMove() = 0;

private: 
	Character* _target = nullptr;
};

