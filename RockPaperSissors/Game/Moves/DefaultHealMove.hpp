#pragma once
#include "Move.hpp"

class DefaultHealMove :
    public Move
{
public:
	DefaultHealMove(Element element, unsigned int power);

	virtual void SetTargets(Arena* arena, bool NPC = true) override;
	virtual void ExecuteMove(Character& moveUser) override;

protected:
	virtual void executeMove(Character& moveUser) override;
};

