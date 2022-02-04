#pragma once
#include "Move.hpp"

class DefaultShieldMove :
    public Move
{
public:
	DefaultShieldMove(Element element);

	virtual void SetTargets(Arena* arena, bool NPC = true) override;

protected:
	virtual void executeMove(Character& moveUser) override;
};

