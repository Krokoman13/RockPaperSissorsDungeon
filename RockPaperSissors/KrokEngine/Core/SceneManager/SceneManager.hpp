#pragma once
#include <vector>
#include <string>
#include "../../Essentials/GameObject.hpp"

class Scene : public GameObject
{
public:
	Scene(std::string Name = "Scene");
	unsigned int identifier = 0;
};

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

