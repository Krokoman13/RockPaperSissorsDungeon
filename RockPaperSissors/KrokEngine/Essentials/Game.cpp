#include <iostream>
#include "Game.hpp"

Game::Game(std::string name, unsigned int width, unsigned int height, unsigned int targetFPS) : _renderer(name, width, height), GameObject(0, 0)
{
	std::cout << "Game initialized.\n";
}

Game::~Game()
{
}

void Game::Start()
{
	while (_renderer.IsWindowActive())
	{
		//sceneManager.currentscene.Update();
	    //updateManager.Update();
		_renderer.Render();
	}
}
