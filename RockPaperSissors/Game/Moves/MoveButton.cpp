#include "MoveButton.hpp"
#include "Move.hpp"
#include "MoveSelector.hpp"

MoveButton::MoveButton(Move* move, MoveSelector* moveSelector, float x, float y) : Clickable(move->iconName, UIElement::ASSET_PATH, x, y)
{
	this->_moveSelector = moveSelector;
	this->_move = move;
}

void MoveButton::OnClick()
{
	this->_moveSelector->Select(this->_move);
}
