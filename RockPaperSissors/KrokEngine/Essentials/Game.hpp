#pragma once
#include <string>
#include "../Core/UpdateManager/UpdateManager.hpp"
#include "../Core/SceneManager/SceneManager.hpp"

class Game : public SceneManager
{
public:
	Game(std::string name, unsigned int width, unsigned int height, unsigned int targetFPS);
	~Game();

	void Run();

private:
	Renderer _renderer;
	UpdateManager _updateManger;

	sf::RenderWindow _renderWindow;
};

