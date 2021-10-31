#pragma once
#include "RenderLayer.hpp"

class Renderer
{
public :
	Renderer(std::string name, unsigned int width, unsigned int height);
	~Renderer();

	void Render();
	bool IsWindowActive();

	void ToRender(std::vector<sf::Drawable*>& sprites, int layer);
	void ToRender(sf::Drawable* sprite, int layer);

private :
	sf::RenderWindow _window;
	std::vector<RenderLayer> _renderLayers;
};

