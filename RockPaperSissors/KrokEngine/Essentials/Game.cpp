#include <iostream>
#include "Game.hpp"

Game::Game(std::string name, unsigned int width, unsigned int height, unsigned int targetFPS) 
	: SceneManager(new Scene("StartScreen")), EventHandeler(_renderWindow), _renderer(_renderWindow), _updateManger()
{
	_renderWindow.create(sf::VideoMode(width, height), name);
	_updateManger.SetRenderer(_renderer);

	std::cout << "Game initialized.\n";
}

Game::~Game()
{
}

void Game::Run()
{
	sf::Event event;
	sf::Clock timer;

	while (_renderWindow.isOpen())
	{
		while (this->_renderWindow.pollEvent(event))
		{
			HandleEvent(event);
		}

		if (!Focus()) continue;

		std::cout << MousePosition() << "\n";

		_updateManger.Update(GetCurrentScene());

		{
			std::vector<sf::Drawable*> drawables = GetCurrentScene()->ui.GetDrawables();
			_renderer.ToRender(drawables, INT_MAX);
		}

		_renderer.Render();
	}
}
