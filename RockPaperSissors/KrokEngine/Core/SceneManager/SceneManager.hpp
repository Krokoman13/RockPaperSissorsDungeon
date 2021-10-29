#pragma once
#include <vector>
#include <string>
#include "Scene.hpp"

class SceneManager
{
public:
	Scene* GetCurrentScene();

	Scene* GetScene(std::string SceneName);
	Scene* GetScene(unsigned int SceneIdentifier);

	void GoToScene(std::string SceneName);
	void GoToScene(unsigned int ScineIdentifier);

	void AddScene(Scene& scene);

private:
	unsigned int findIdentifier(std::string name);
	std::vector<Scene*> scenes = {new Scene("StartScreen")};
	Scene* currentScene;
};

