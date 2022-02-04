#pragma once
#include "../../KrokEngine/Core/Graphics/ImageGameObject.hpp"
#include "HealthBar.hpp"
#include "../Moves/RockPaperSissorsElements.hpp"
#include <vector>

class Move;
class Healthbar;
class Arena;
class MoveSelector;

class Character :
    public ImageGameObject
{
public:
    Character(bool NPC, unsigned int rockPower, unsigned int paperPower, unsigned int scissorPower, Move* move1, Move* move2, std::string name, std::string path);
    virtual ~Character();

    virtual void OnLoad() override;
    virtual void Update() override;

    HealthBar* health;
    Arena* arena = nullptr;

    void RecieveDamage(unsigned int amount, Element type, std::string sourceName);
    void SetShield(Element shieldElement);
    const Element GetShield();

    unsigned int GetModifier(Element element);
    bool MoveSelected();

    void SelectRandomMove();
    void SetMovesVisible(bool visible);

    const unsigned int GetRockModifier() const;
    const unsigned int GetPaperModifier() const;
    const unsigned int GetScissorModifier() const;

    void ExecuteMove();

    bool NPC = false;

protected:
    unsigned int _rockModifier;
    unsigned int _paperModifier;
    unsigned int _scissorModifier;

    virtual Move* SelectMove(unsigned int i) = 0;

    ImageGameObject* getImageShield(Element element);

    UIElement* _stats;

    ImageGameObject* _currentShield;
    Element _shield = Element::NONE;
    MoveSelector* selector;
};

