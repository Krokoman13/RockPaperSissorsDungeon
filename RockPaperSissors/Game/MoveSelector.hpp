#pragma once
#include "../KrokEngine/Essentials/GameObject.hpp"

class MoveButton;
class Move;

class MoveSelector :
    public GameObject
{
public:
    MoveSelector(Move* move1, Move* move2, int x, int y);
    virtual ~MoveSelector() override;

    void Select(Move* clicked);

    virtual void OnLoad() override;
    virtual void Update() override;

private:
    Move* _move1 = nullptr;
    MoveButton* _moveButton1 = nullptr;

    Move* _move2 = nullptr;
    MoveButton* _moveButton2 = nullptr;

    Move* _selectedMove = nullptr;
};

