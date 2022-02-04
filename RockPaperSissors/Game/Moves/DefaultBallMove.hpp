#pragma once
#include "Move.hpp"

class DefaultBallMove : public Move
{
public:
	DefaultBallMove(Element element, unsigned int power);

	virtual void SetTargets(Arena* arena, bool NPC = true) override;

protected:
	virtual void executeMove(Character& moveUser) override;
};

