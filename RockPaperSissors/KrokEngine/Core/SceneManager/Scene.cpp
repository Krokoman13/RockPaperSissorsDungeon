#include "Scene.hpp"

Scene::Scene(std::string Name, bool reloadOnOpen) : GameObject(0, 0, "Scene")
{
	this->name = Name;
	this->_reloadOnOpen = reloadOnOpen;
}

void Scene::Load()
{
	load();
	loaded = true;
}

void Scene::Close()
{
	close();
	if (_reloadOnOpen) loaded = false;

}

void Scene::load()
{
}

void Scene::close()
{
}
