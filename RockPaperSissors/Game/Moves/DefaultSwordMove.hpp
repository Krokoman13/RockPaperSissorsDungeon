#pragma once
#include "Move.hpp"

class DefaultSwordMove : public Move
{
public:
	DefaultSwordMove(Element element, unsigned int power);

	virtual void SetTargets(Arena* arena, bool NPC = true) override;

protected:
	virtual void executeMove(Character& moveUser) override;
};
