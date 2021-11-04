#include "Scene.hpp"

Scene::Scene(std::string Name, bool reloadOnOpen) : GameObject(0, 0, "Scene")
{
	this->name = Name;
	this->_reloadOnOpen = reloadOnOpen;
}

void Scene::Load()
{
	OnLoad();
	loadChildren(this);
	loaded = true;
}

void Scene::Close()
{
	OnClose();
	if (_reloadOnOpen) loaded = false;
}

void Scene::OnClose()
{
}

void Scene::loadChildren(GameObject* gameObject)
{
	for (GameObject* child : gameObject->GetChildren())
	{
		child->SetScene(this);
		child->OnLoad();
		loadChildren(child);
	}
}
