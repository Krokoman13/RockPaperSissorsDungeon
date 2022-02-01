#include "Move.hpp"
#include "RockPaperSissorsElements.hpp"

Move::Move(Element element, Type type, unsigned int strength, std::string iconName)
{
	this->element = element;
	this->type = type;
	this->strength = strength;
	this->iconName = iconName;
}
