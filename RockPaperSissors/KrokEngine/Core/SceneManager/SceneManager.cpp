#include "SceneManager.hpp"

SceneManager::SceneManager(Scene* startScene, Game* game = nullptr)
{
	_scenes.push_back(startScene);
	openScene(startScene);
	_game = game;
}

SceneManager::~SceneManager()
{
	for (Scene* scene : _scenes)
	{
		delete scene;
	}

	_scenes.clear();
}

Scene* SceneManager::GetCurrentScene()
{
	if (_currentScene == nullptr)
	{
		_currentScene = _scenes[0];
	}

	return _currentScene;
}

Scene* SceneManager::GetScene(Scene* scene)
{
	return GetScene(scene->identifier);
}

Scene* SceneManager::GetScene(std::string SceneName)
{
	return GetScene(findIdentifier(SceneName));
}

Scene* SceneManager::GetScene(int SceneIdentifier)
{
	if (SceneIdentifier >= (int)_scenes.size()) return nullptr;
	return _scenes[SceneIdentifier];
}

void SceneManager::GoToScene(Scene* scene)
{
	GoToScene(scene->identifier);
}

void SceneManager::GoToScene(std::string SceneName)
{
	GoToScene(findIdentifier(SceneName));
}

void SceneManager::GoToScene(int SceneIdentifier)
{
	Scene* nextScene = GetScene(SceneIdentifier);
	if (_currentScene == nextScene) return;

	closeScene(_currentScene);
	_currentScene = nextScene;
	openScene(_currentScene);
}

void SceneManager::AddScene(Scene* scene)
{
	scene->sceneManager = this;

	if (scene->identifier == _scenes.size())
	{
		_scenes.push_back(scene);
		return;
	}

	if (scene->identifier > _scenes.size())
	{
		_scenes.push_back(nullptr);
		AddScene(scene);
		return;
	}

	if (_scenes[scene->identifier] == nullptr)
	{
		_scenes[scene->identifier] = scene;
		return;
	}

	scene->identifier++;
	AddScene(scene);
}

void SceneManager::reloadCurrentScene()
{
	GetCurrentScene()->Close();
	GetCurrentScene()->Load();
}

Game* SceneManager::GetGame()
{
	return _game;
}

void SceneManager::closeScene(Scene* scene)
{
	std::cout << "Closing scene: " << scene->name << '\n';
	scene->Close();
	_currentScene = nullptr;
}

void SceneManager::openScene(Scene* scene)
{
	std::cout << "Opening scene: " << scene->name << '\n';

	if (!scene->loaded)
	{
		scene->Load();
		std::cout << scene->name << " loaded\n";
	}

	_currentScene = scene;
}

unsigned int SceneManager::findIdentifier(std::string name)
{
	for (Scene* scene : _scenes)
	{
		if (scene == nullptr) continue;

		if (scene->name == name) return scene->identifier;
	}

	return 0;
}
