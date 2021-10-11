#include "Renderer.hpp"
#include <iostream>

Renderer::Renderer(std::string name, unsigned int width, unsigned int height)
{
	this->_window.create(sf::VideoMode(width, height), name);

	_renderLayers.push_back(RenderLayer(0));

	std::cout << "Renderer initialized.\n";
}

Renderer::~Renderer()
{
}

void Renderer::Render()
{
	sf::Event event;

	while (this->_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			this->_window.close();
			return;
		}
	}

	this->_window.clear();

	for (RenderLayer& renderLayer : _renderLayers)
	{
		//std::cout << renderLayer.layer << ": " << renderLayer.sprites.size() << '\n';

		while (renderLayer.sprites.size() > 0)
		{
			sf::Sprite* sprite = renderLayer.sprites[renderLayer.sprites.size() - 1];

			_window.draw(*sprite);

			renderLayer.sprites.pop_back();
		}
	}

	this->_window.display();
}

bool Renderer::IsWindowActive()
{
	return _window.isOpen();
}

void Renderer::ToRender(std::vector<sf::Sprite*>& sprites, int layer)
{
	if (sprites.size() < 1) return;
	if (layer < 0) layer = 1;

	if (layer > this->_renderLayers[this->_renderLayers.size() - 1].layer)
	{
		RenderLayer newLayer(layer, sprites);

		_renderLayers.push_back(newLayer);
		return;
	}

	for (std::vector<RenderLayer>::iterator it = _renderLayers.begin(); it != _renderLayers.end(); ++it)
	{
		if (it->layer == layer)
		{
			it->Add(sprites);
			return;
		}

		if (it->layer > layer)
		{
			RenderLayer newLayer(layer, sprites);
			_renderLayers.insert(it, newLayer);

			return;
		}
	}
}

void Renderer::ToRender(sf::Sprite* sprite, int layer)
{
	if (layer < 0) layer = 1;

	if (layer > this->_renderLayers[this->_renderLayers.size() - 1].layer)
	{
		RenderLayer newLayer(layer, sprite);

		_renderLayers.push_back(newLayer);
		return;
	}

	for (std::vector<RenderLayer>::iterator it = _renderLayers.begin(); it != _renderLayers.end(); ++it)
	{
		if (it->layer == layer)
		{
			it->Add(sprite);
			return;
		}

		if (it->layer > layer)
		{
			RenderLayer newLayer(layer, sprite);
			_renderLayers.insert(it, newLayer);

			return;
		}
	}
}
