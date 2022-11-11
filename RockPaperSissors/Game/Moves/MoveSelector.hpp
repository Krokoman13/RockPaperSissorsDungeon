#pragma once
#include "../../KrokEngine/Essentials/GameObject.hpp"

class UIElement;
class Move;

class MoveSelector :
    public GameObject
{
public:
    MoveSelector(Move* move1, Move* move2, float x, float y, bool NPC = false);
    virtual ~MoveSelector();

    void Select(const Move* clicked);
    void Select(unsigned int moveNr);

    void Reset();

    virtual void OnLoad() override;
    virtual void Update() override;

    void SetVisible(bool visible);

    Move* selectedMove = nullptr;

private:
    Move* _move1 = nullptr;
    UIElement* _moveButton1 = nullptr;

    Move* _move2 = nullptr;
    UIElement* _moveButton2 = nullptr;

    Vec2 offset;

    bool _NPC;
};

