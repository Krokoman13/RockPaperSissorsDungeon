#pragma once
#include "ImageGameObject.hpp"
#include "RenderLayer.hpp"

class Renderer
{
public :
	Renderer(std::string name, unsigned int width, unsigned int height);
	~Renderer();

	void Render();
	bool IsWindowActive();

	void ToRender(std::vector<sf::Sprite*>& sprites, int layer);
	void ToRender(sf::Sprite* sprite, int layer);

private :
	sf::RenderWindow _window;
	std::vector<RenderLayer> _renderLayers;
};

