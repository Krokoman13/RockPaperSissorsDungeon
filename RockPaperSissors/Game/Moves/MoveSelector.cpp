#pragma once
#include "MoveSelector.hpp"
#include "MoveButton.hpp"
#include "Move.hpp"
#include "../../KrokEngine/Core/SceneManager/Scene.hpp"

MoveSelector::MoveSelector(Move* move1, Move* move2, int x, int y, bool NPC) : GameObject(x, y, "MoveSelector")
{
	_move1 = move1;
	_move2 = move2;

	this->_NPC = NPC;
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
	if (clicked == selectedMove)
	{
		Reset();
		return;
	}

	if (clicked == _move1)
	{
		selectedMove = _move1;
		_moveButton2->SetVisible(false);
		return;
	}

	if (clicked == _move2)
	{
		selectedMove = _move2;
		_moveButton1->SetVisible(false);
	}
}

void MoveSelector::Select(unsigned int moveNr)
{
	switch (moveNr)
	{
	case 1:
		Select(_move1);
		return;

	case 2:
		Select(_move2);
		return;

	default:
		SetVisible(false);
		selectedMove = nullptr;
		return;
	}
}

void MoveSelector::Reset()
{
	_moveButton1->SetVisible(true);
	_moveButton2->SetVisible(true);

	selectedMove = nullptr;
}

void MoveSelector::OnLoad()
{
	if (_NPC)
	{
		_moveButton1 = new UIElement(_move1->iconName, globalPosition.x, globalPosition.y);
		_moveButton2 = new UIElement(_move2->iconName, globalPosition.x + 80, globalPosition.y);
	}
	else
	{
		_moveButton1 = new MoveButton(_move1, this, globalPosition.x, globalPosition.y);
		_moveButton2 = new MoveButton(_move2, this, globalPosition.x + 80, globalPosition.y);
	}

	offset = Vec2(_moveButton2->x - _moveButton1->x, _moveButton2->y - _moveButton1->y);

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

void MoveSelector::SetVisible(bool visible)
{
	_moveButton1->SetVisible(visible);
	_moveButton2->SetVisible(visible);
}
