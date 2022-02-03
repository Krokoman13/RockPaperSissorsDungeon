#pragma once
#include "../../KrokEngine/Core/UI/Clickable.hpp"

class MoveSelector;
class Move;

class MoveButton :
    public Clickable
{
public:
    MoveButton(Move* move, MoveSelector* moveSelector,  float x, float y);
    virtual ~MoveButton() = default;

    virtual void OnClick() override;

private:
    MoveSelector* _moveSelector = nullptr;
    Move* _move = nullptr;
};

