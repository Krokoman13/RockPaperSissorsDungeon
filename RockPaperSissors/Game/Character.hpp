#pragma once
#include "../KrokEngine/Core/Graphics/ImageGameObject.hpp"
#include "HealthBar.hpp"
#include "RockPaperSissorsElements.hpp"
#include <vector>

class Move;
class Healthbar;
class Arena;

class Character :
    public ImageGameObject
{
public:
    Character(unsigned int rockPower, unsigned int paperPower, unsigned int scissorPower, Move* move1, Move* move2);
    virtual ~Character() override;

    HealthBar* health;
    Arena* arena = nullptr;

    void RecieveDamage(unsigned int amount, Element type, std::string sourceName);
    void SetShield(Element shieldElement);

    unsigned int GetModifier(Element element);

private:
    unsigned int _rockModifier;
    unsigned int _paperModifier;
    unsigned int _scissorModifier;

    const ImageGameObject _rock = ImageGameObject("Rock", "Assets/", 50, 100);
    const ImageGameObject _paper = ImageGameObject("Paper", "Assets/", 90, 60);
    const ImageGameObject _scissor = ImageGameObject("Scissor", "Assets/", 0, 50);

    Element _shield;
};

