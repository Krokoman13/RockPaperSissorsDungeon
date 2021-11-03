#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "Vec2.hpp"

class Scene;

class GameObject
{
public:
	GameObject(Vec2 position = Vec2(0,0), std::string name = "GameObject", GameObject* parent = nullptr);
	GameObject(float x, float y, std::string name = "GameObject", GameObject* parent = nullptr);
	GameObject(const GameObject& other);
	GameObject& operator=(const GameObject& other);
	virtual GameObject* Copy();
	~GameObject();

	std::string name;

	GameObject* GetParent();
	void SetParent(GameObject& parent);
	void SetParent(GameObject* parent);

	void ClearParent();

	const std::vector <GameObject*> GetChildren();
	GameObject* GetChild(unsigned int i);

	void AddChild(GameObject& toAdd);
	void AddChild(GameObject* toAdd);
	void RemoveChild(GameObject& toRemove);
	void RemoveChild(GameObject* toRemove);

	const Vec2 GetGlobaPosition();
	void SetGlobalPosition(Vec2 position);

	static const Vec2 GetAllTransformations(GameObject* parent, Vec2 transformation = Vec2(0, 0));

	Vec2 localPosition;

	static const Vec2 GetAllScaleing(GameObject* parent, Vec2 startScale = Vec2(1, 1));

	virtual void SetScale(float xScale, float yScale);
	void SetScale(float uniformScale = 1.0f);
	Vec2 GetScale();

	int GetRenderLayer();
	void SetRenderLayer(int renderLayer);
	bool canRender = false;

	virtual sf::Sprite* GetSprite();
	//void RenerateSprites(std::vector<sf::Sprite*>& sprites, Vec2 pos = Vec2(0, 0), Vec2 scale = Vec2(1, 1));
	virtual void Update();

protected:
	int _renderLayer = -1;

	GameObject* _parent = nullptr;
	std::vector <GameObject*> _children;

	int getPositionAsChild(GameObject& toFind);

	Vec2 _scale = Vec2(1.0f, 1.0f);

	Scene* getCurrentScene();
};

