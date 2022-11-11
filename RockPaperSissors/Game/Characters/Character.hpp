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
    void HealDamage(const unsigned int amount, const std::string sourceName);
    void SetShield(Element shieldElement);
    const Element GetShield() const;

    unsigned int GetModifier(Element element) const;
    const bool MoveSelected() const;

    void SelectRandomMove();
    void SetMovesVisible(bool visible);

    const unsigned int GetRockModifier() const;
    const unsigned int GetPaperModifier() const;
    const unsigned int GetScissorModifier() const;

    const bool IsDamaged() const;

    void ExecuteMove();

    bool NPC = false;
    virtual Move* GetMove(unsigned int i) = 0;

protected:
    unsigned int _rockModifier;
    unsigned int _paperModifier;
    unsigned int _scissorModifier;

    ImageGameObject* getImageShield(Element element);

    UIElement* _stats;

    ImageGameObject* _currentShield;
    Element _shield = Element::NONE;
    MoveSelector* selector;
};

