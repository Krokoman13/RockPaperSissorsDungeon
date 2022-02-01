#include "GameObject.hpp"
#include "Game.hpp"

GameObject::GameObject(Vec2 position, std::string name, GameObject* parent)
{
	this->localPosition = position;
	this->name = name;

	if (parent != nullptr)
	{
		parent->AddChild(new GameObject(*this));
	}
}

GameObject::GameObject(float x, float y, std::string name, GameObject* parent) : GameObject(Vec2(x, y), name, parent)
{
}

GameObject::~GameObject()
{
	if (_parent != nullptr)
	{
		_parent->RemoveChild(this);
	}

	ClearChildren();
}

void GameObject::ClearChildren()
{
	while (_children.size() > 0)
	{
		delete _children.back();
	}
}

sf::Sprite* GameObject::GetSprite()
{
	return nullptr;
}

void GameObject::Update()
{
}

void GameObject::OnLoad()
{
}

void GameObject::SetScene(Scene* scene)
{
	this->_scene = scene;
}

GameObject* GameObject::GetParent()
{
	return _parent;
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

void GameObject::AddChild(GameObject* toAdd)
{
	if (toAdd == nullptr) throw std::invalid_argument("Cannot add a non-existing GameObject");

	toAdd->ClearParent();

	if (toAdd == this) throw std::invalid_argument("Cannot add a GameObject to itself");

	_children.push_back(toAdd);
	toAdd->_parent = this;
}

void GameObject::RemoveChild(GameObject* toRemove)
{
	if (toRemove == nullptr) return;

	for (unsigned int i = 0; i < this->_children.size(); i++)
	{
		if (this->_children[i] == toRemove)
		{
			this->_children.erase(this->_children.begin()+i);
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

const Vec2 GameObject::GetAllScaleing(GameObject* parent, Vec2 scaling)
{
	if (parent == nullptr) return scaling;

	GameObject* nextParent = parent->GetParent();

	if (nextParent == nullptr) return scaling * parent->GetScale();
	return GetAllTransformations(nextParent, scaling * parent->GetScale());
}

void GameObject::SetScale(float xScale, float yScale)
{
	this->_scale.SetXY(xScale, yScale);
}

void GameObject::SetScale(float uniformScale)
{
	this->SetScale(uniformScale, uniformScale);
}

Vec2 GameObject::GetScale()
{
	return this->_scale;
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
