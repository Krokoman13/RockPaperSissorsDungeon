#include "GameObject.hpp"

GameObject::GameObject(Vec2 position, std::string name)
{
	this->localPosition = position;
	this->name = name;
}

GameObject::GameObject(float x, float y, std::string name) : GameObject(Vec2(x, y))
{
}

GameObject::~GameObject()
{
}

sf::Sprite* GameObject::GetSprite()
{
	return nullptr;
}

void GameObject::Update()
{
}

int GameObject::getPositionAsChild(GameObject& toFind)
{
	for (unsigned int i = 0; i < _children.size(); i++)
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
	this->SetParent(&parent);
}

void GameObject::SetParent(GameObject* newParent)
{
	if (newParent == nullptr)
	{
		ClearParent();
		return;
	}

	newParent->AddChild(this);
}

void GameObject::ClearParent()
{
	if (_parent != nullptr)
	{
		_parent->RemoveChild(this);
	}
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
	if (toAdd == nullptr) throw std::invalid_argument("Cannot add a non-existing GameObject");

	toAdd->ClearParent();

	if (toAdd == this) throw std::invalid_argument("Cannot add a GameObject to itself");

	_children.push_back(toAdd);
	toAdd->_parent = this;
}

void GameObject::RemoveChild(GameObject& toRemove)
{
	RemoveChild(&toRemove);
}

void GameObject::RemoveChild(GameObject* toRemove)
{
	for (unsigned int i = 0; i < _children.size(); i++)
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

const Vec2 GameObject::GetGlobaPosition()
{
	return GameObject::GetAllTransformations(this->_parent) + localPosition;
}

void GameObject::SetGlobalPosition(Vec2 position)
{
	Vec2 transformation = GetAllTransformations(this->_parent);
	this->localPosition = position - transformation;
}

const Vec2 GameObject::GetAllTransformations(GameObject* parent, Vec2 transformation)
{
	if (parent == nullptr) return transformation;

	GameObject* nextParent = parent->GetParent();

	if (nextParent == nullptr) return transformation + parent->localPosition;
	return GetAllTransformations(nextParent, transformation + parent->localPosition);
}

int GameObject::GetRenderLayer()
{
	GameObject* parent = this->_parent;

	if (this->_renderLayer >= 0 || parent == nullptr) return this->_renderLayer;

	return this->_parent->GetRenderLayer();
}

void GameObject::SetRenderLayer(int renderLayer)
{
	if (renderLayer < -1) renderLayer = -1;
	this->_renderLayer = renderLayer;
}

