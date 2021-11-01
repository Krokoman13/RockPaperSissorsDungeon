#pragma once
#include "RenderLayer.hpp"

class Renderer
{
public :
	Renderer(std::string name, sf::RenderWindow& _window);
	~Renderer();

	void Render();

	void ToRender(std::vector<sf::Drawable*>& sprites, int layer);
	void ToRender(sf::Drawable* sprite, int layer);

private :
	sf::RenderWindow* _window;
	std::vector<RenderLayer> _renderLayers;
};

