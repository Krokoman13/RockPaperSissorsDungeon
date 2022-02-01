#pragma once
#include "MoveSelector.hpp"
#include "MoveButton.hpp"
#include "../KrokEngine/Core/SceneManager/Scene.hpp"

MoveSelector::MoveSelector(Move* move1, Move* move2, int x, int y) : GameObject(x, y, "MoveSelector")
{
	this->_move1 = move1;
	this->_move2 = move2;

	this->_moveButton1 = new MoveButton(move1, this, x, y);
	this->_moveButton2 = new MoveButton(move2, this, x + 80, y);
}

MoveSelector::~MoveSelector()
{
	GameObject::~GameObject();

	delete _move1;
	delete _move2;

	delete _moveButton1;
	delete _moveButton2;
}

void MoveSelector::Select(Move* clicked)
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
	Vec2 pos = this->GetGlobaPosition();
	Vec2 offset = Vec2(_moveButton2->x - _moveButton1->x, _moveButton2->y - _moveButton1->y);

	_moveButton1->x = pos.x;
	_moveButton1->y = pos.y;

	_moveButton2->x = pos.x + offset.x;
	_moveButton2->y = pos.y + offset.y;

	Vec2 scale = this->GetScale();

	_moveButton1->SetScale(scale.x, scale.y);
	_moveButton2->SetScale(scale.x, scale.y);
}
