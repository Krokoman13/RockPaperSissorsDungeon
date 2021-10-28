#include <iostream>
#include "Game.hpp"

Game::Game(std::string name, unsigned int width, unsigned int height, unsigned int targetFPS) : _renderer(name, width, height), _updateManger()
{
	_updateManger.SetRenderer(_renderer);

	std::cout << "Game initialized.\n";
}

Game::~Game()
{
}

void Game::Run()
{
	while (_renderer.IsWindowActive())
	{
		//sceneManager.currentscene.Update();
		_updateManger.Update(GetCurrentScene());
		_renderer.Render();
	}
}
