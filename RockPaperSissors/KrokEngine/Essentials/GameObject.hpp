#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "Vec2.hpp"

class GameObject
{
public:
	GameObject(Vec2 position);
	GameObject(float x, float y);
	~GameObject();

	std::string name;

	GameObject* GetParent();
	void SetParent(GameObject& parent);

	const std::vector <GameObject*> GetChildren();
	GameObject* GetChild(unsigned int i);

	void AddChild(GameObject& toAdd);
	void AddChild(GameObject* toAdd);
	void RemoveChild(GameObject& toRemove);
	void RemoveChild(GameObject* toRemove);

	const Vec2 GetGlobaPosition();
	void SetGlobalPosition(Vec2 position);

	const Vec2 GetLocalPosition();
	void SetLocalPosition(Vec2 position);

	virtual const sf::Sprite* Render();

protected:
	Vec2 _position;

	Vec2 parentTransformations();

	GameObject* _parent = nullptr;
	std::vector <GameObject*> _children;
	int getPositionAsChild(GameObject& toFind);
};

