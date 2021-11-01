#include <iostream>
#include "Game.hpp"

Game::Game(std::string name, unsigned int width, unsigned int height, unsigned int targetFPS) : SceneManager(new Scene("StartScreen")),  _renderer(_renderWindow), _updateManger()
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
	while (_renderWindow.isOpen())
	{
		sf::Event event;

		while (this->_renderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				this->_renderWindow.close();
				return;
			}
		}

		_updateManger.Update(GetCurrentScene());

		{
			std::vector<sf::Drawable*> drawables = GetCurrentScene()->ui.GetDrawables();
			_renderer.ToRender(drawables, INT_MAX);
		}

		_renderer.Render();
	}
}
