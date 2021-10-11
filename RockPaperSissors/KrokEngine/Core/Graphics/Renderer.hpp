#pragma once
#include "ImageGameObject.hpp"

class Renderer
{
public :
	Renderer(std::string name, unsigned int width, unsigned int height);
	~Renderer();

	void Render();
	bool IsWindowActive();

private :
	sf::RenderWindow window;
};

