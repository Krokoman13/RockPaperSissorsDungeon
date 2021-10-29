#include "SceneManager.hpp"

SceneManager::SceneManager(Scene* startScene)
{
	scenes.push_back(startScene);
	openScene(startScene);
}

SceneManager::SceneManager(Scene& startScene) : SceneManager(&startScene)
{
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
	Scene* nextScene = GetScene(SceneIdentifier);
	if (currentScene == nextScene) return;

	currentScene = nextScene;
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

void SceneManager::closeScene(Scene* scene)
{
	if (currentScene != scene) return;

	std::cout << "Closing scene: " << scene->name << '\n';
	scene->Close();
	currentScene = nullptr;
}

void SceneManager::openScene(Scene* scene)
{
	std::cout << "Opening scene: " << scene->name << '\n';

	if (!scene->loaded)
	{
		scene->Load();
		std::cout << scene->name << " loaded\n";
	}

	currentScene = scene;
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
