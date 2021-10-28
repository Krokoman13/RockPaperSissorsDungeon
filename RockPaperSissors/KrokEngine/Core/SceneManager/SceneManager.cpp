#include "SceneManager.hpp"

Scene::Scene(std::string Name) : GameObject(0, 0, "Scene")
{
	this->name = Name;
}

Scene* SceneManager::GetCurrentScene()
{
	if (currentScene == nullptr)
	{
		currentScene = scenes[0];
	}

	return currentScene;
}

Scene* SceneManager::GetScene(std::string SceneName)
{
	return GetScene(findIdentifier(SceneName));
}

Scene* SceneManager::GetScene(unsigned int SceneIdentifier)
{
	if (SceneIdentifier >= scenes.size()) return nullptr;
	return scenes[SceneIdentifier];
}

void SceneManager::GoToScene(std::string SceneName)
{
	GoToScene(findIdentifier(SceneName));
}

void SceneManager::GoToScene(unsigned int SceneIdentifier)
{
	currentScene = GetScene(SceneIdentifier);
}

void SceneManager::AddScene(Scene& scene)
{
	if (scene.identifier == scenes.size())
	{
		scenes.push_back(&scene);
		return;
	}

	if (scene.identifier > scenes.size())
	{
		scenes.push_back(nullptr);
		AddScene(scene);
		return;
	}

	if (scenes[scene.identifier] == nullptr)
	{
		scenes[scene.identifier] = &scene;
		return;
	}

	scene.identifier++;
	AddScene(scene);
}

unsigned int SceneManager::findIdentifier(std::string name)
{
	for (Scene* scene : scenes)
	{
		if (scene == nullptr) continue;

		if (scene->name == name) return scene->identifier;
	}

	return 0;
}
