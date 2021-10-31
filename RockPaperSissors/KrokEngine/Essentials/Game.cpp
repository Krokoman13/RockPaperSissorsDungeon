#include <iostream>
#include "Game.hpp"

Game::Game(std::string name, unsigned int width, unsigned int height, unsigned int targetFPS) : SceneManager(new Scene("StartScreen")), _renderer(name, width, height), _updateManger()
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
		if (_renderer.PollEvent()) 
		_updateManger.Update(GetCurrentScene());

		std::vector<sf::Drawable*> drawables = GetCurrentScene()->ui.GetDrawables();
		_renderer.ToRender(drawables, INT_MAX);

		_renderer.Render();
	}
}
