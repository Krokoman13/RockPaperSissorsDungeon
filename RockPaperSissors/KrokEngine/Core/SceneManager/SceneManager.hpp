#pragma once
#include <vector>
#include <string>
#include "Scene.hpp"

class SceneManager
{
public:
	SceneManager(Scene* startScene);
	~SceneManager();

	Scene* GetCurrentScene();

	Scene* GetScene(Scene* scene);
	Scene* GetScene(std::string SceneName);
	Scene* GetScene(int SceneIdentifier);

	void GoToScene(Scene* scene);
	void GoToScene(std::string SceneName);
	void GoToScene(int ScineIdentifier);

	void AddScene(Scene* scene);
	
	void reloadCurrentScene();

protected:
	void closeScene(Scene* scene);
	void openScene(Scene* scene);

private:
	unsigned int findIdentifier(std::string name);
	std::vector<Scene*> _scenes = {};
	Scene* _currentScene;
};

