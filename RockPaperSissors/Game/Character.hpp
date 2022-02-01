#pragma once
#include "../KrokEngine/Core/Graphics/ImageGameObject.hpp"
#include "Healthbar.hpp"
#include <vector>

class Move;
class Healthbar;

class Character :
    public ImageGameObject
{
public:
    Character(unsigned int rockPower, unsigned int paperPower, unsigned int scissorPower, Move* move1, Move* move2);
    virtual ~Character() override;
    HealthBar* health;

private:
    unsigned int _rockModifier;
    unsigned int _paperModifier;
    unsigned int _scissorModifier;

    GameObject* _currentWeapon;

    const ImageGameObject _rock = ImageGameObject("Rock", "Assets/", 50, 100);
    const ImageGameObject _paper = ImageGameObject("Paper", "Assets/", 90, 60);
    const ImageGameObject _scissor = ImageGameObject("Scissor", "Assets/", 0, 50);

    void equipWeapon(const ImageGameObject& weapon);
};

