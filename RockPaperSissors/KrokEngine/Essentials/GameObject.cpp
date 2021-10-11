#include "GameObject.hpp"

GameObject::GameObject(Vec2 position)
{
	this->_position = position;
	this->name = "GameObject";
}

GameObject::GameObject(float x, float y) : GameObject (Vec2(x, y))
{

}

GameObject::~GameObject()
{
}

const sf::Sprite* GameObject::Render()
{
	return nullptr;
}

int GameObject::getPositionAsChild(GameObject& toFind)
{
	for (int i = 0; i < _children.size(); i++)
	{
		if (_children[i] == &toFind)
		{
			return i;
		}
	}

	throw std::invalid_argument("Could not find a non-existent child");
}

GameObject* GameObject::GetParent()
{
	return _parent;
}

void GameObject::SetParent(GameObject& parent)
{
	parent.AddChild(this);
}

const std::vector<GameObject*> GameObject::GetChildren()
{
	return _children;
}

GameObject* GameObject::GetChild(unsigned int i)
{
	if (i > _children.size()-1) return nullptr;

	return _children[i];
}

void GameObject::AddChild(GameObject& toAdd)
{
	GameObject* temp = &toAdd;
	AddChild(temp);
}

void GameObject::AddChild(GameObject* toAdd)
{
	GameObject* parent = toAdd->GetParent();

	if (parent != nullptr)
	{
		parent->RemoveChild(toAdd);
	}

	_children.push_back(toAdd);
	toAdd->_parent = this;
}

void GameObject::RemoveChild(GameObject& toRemove)
{
	RemoveChild(&toRemove);
}

void GameObject::RemoveChild(GameObject* toRemove)
{
	for (int i = 0; i < _children.size(); i++)
	{
		if (_children[i] == toRemove)
		{
			_children.erase(_children.begin()+i);
			toRemove->_parent = nullptr;
			return;
		}
	}

	throw std::invalid_argument("Could not remove a non-existent child");
}
