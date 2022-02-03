#pragma once
#include "MoveSelector.hpp"
#include "MoveButton.hpp"
#include "Move.hpp"
#include "../../KrokEngine/Core/SceneManager/Scene.hpp"

MoveSelector::MoveSelector(Move* move1, Move* move2, int x, int y, bool NPC) : GameObject(x, y, "MoveSelector")
{
	_move1 = move1;
	_move2 = move2;

	if (NPC)
	{
		_moveButton1 = new UIElement(move1->iconName, x, y);
		_moveButton2 = new UIElement(move2->iconName, x + 80, y);
		return;
	}

	_moveButton1 = new MoveButton(move1, this, x, y);
	_moveButton2 = new MoveButton(move2, this, x + 80, y);

	offset = Vec2(_moveButton2->x - _moveButton1->x, _moveButton2->y - _moveButton1->y);
}

MoveSelector::~MoveSelector()
{
	delete _move1;
	delete _move2;

	delete _moveButton1;
	delete _moveButton2;
}

void MoveSelector::Select(const Move* clicked)
{
	if (clicked == _selectedMove)
	{
		_moveButton1->SetVisible(true);
		_moveButton2->SetVisible(true);

		_selectedMove = nullptr;
		return;
	}

	if (clicked == _move1)
	{
		_selectedMove = _move1;
		_moveButton2->SetVisible(false);
		return;
	}

	if (clicked == _move2)
	{
		_selectedMove = _move2;
		_moveButton1->SetVisible(false);
	}
}

void MoveSelector::OnLoad()
{
	this->_scene->ui->AddElement(this->_moveButton1);
	this->_scene->ui->AddElement(this->_moveButton2);
}

void MoveSelector::Update()
{
	Vec2 pos = globalPosition;
	Vec2 scale = globalScale;

	_moveButton1->x = pos.x;
	_moveButton1->y = pos.y;

	_moveButton2->x = pos.x + offset.x * scale.x;
	_moveButton2->y = pos.y + offset.y * scale.y;

	_moveButton1->SetScale(scale.x, scale.y);
	_moveButton2->SetScale(scale.x, scale.y);
}
