#include "Renderer.hpp"
#include <iostream>

Renderer::Renderer(std::string name, unsigned int width, unsigned int height)
{
	this->window.create(sf::VideoMode(width, height), name);

	std::cout << "Renderer initialized.\n";
}

Renderer::~Renderer()
{
}

void Renderer::Render()
{
	sf::Event event;

	while (this->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			this->window.close();
			return;
		}
	}

	this->window.clear();

	//for each layer, for each sprite, display.

	this->window.display();
}

bool Renderer::IsWindowActive()
{
	return window.isOpen();
}
