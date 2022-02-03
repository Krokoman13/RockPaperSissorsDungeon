#pragma once
#include "../../KrokEngine/Essentials/GameObject.hpp"

class UIElement;
class Move;

class MoveSelector :
    public GameObject
{
public:
    MoveSelector(Move* move1, Move* move2, int x, int y, bool NPC = false);
    virtual ~MoveSelector();

    void Select(const Move* clicked);

    virtual void OnLoad() override;
    virtual void Update() override;

private:
    Move* _move1 = nullptr;
    UIElement* _moveButton1 = nullptr;

    Move* _move2 = nullptr;
    UIElement* _moveButton2 = nullptr;

    Move* _selectedMove = nullptr;

    Vec2 offset;
};

