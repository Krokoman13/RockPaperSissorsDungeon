#pragma once
#include <vector>
#include <string>
#include "Scene.hpp"

class SceneManager
{
public:
	SceneManager(Scene* startScene);
	SceneManager(Scene& startScene);
	Scene* GetCurrentScene();

	Scene* GetScene(Scene& scene);
	Scene* GetScene(std::string SceneName);
	Scene* GetScene(unsigned int SceneIdentifier);

	void GoToScene(Scene& scene);
	void GoToScene(std::string SceneName);
	void GoToScene(unsigned int ScineIdentifier);

	void AddScene(Scene& scene);

protected:
	void closeScene(Scene* scene);
	void openScene(Scene* scene);

private:
	unsigned int findIdentifier(std::string name);
	std::vector<Scene*> scenes = {};
	Scene* _currentScene;
};

