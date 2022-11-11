#pragma once
#include "Character.hpp"

class Mage :
    public Character
{
public:
    Mage(unsigned int rockPower, unsigned int paperPower, unsigned int scissorPower, unsigned int move1, unsigned int  move2, bool NPC = false);
    virtual Move* GetMove(unsigned int i) override;
};

