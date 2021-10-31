#pragma once
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

struct RenderLayer
{
	int layer = -1;
	std::vector<sf::Drawable*> drawables;

	RenderLayer(int layer)
	{
		this->layer = layer;

		std::cout << "New layer created: " << this->layer << ".\n";
	}

	RenderLayer(int layer, std::vector<sf::Drawable*>& sprites) : RenderLayer(layer)
	{
		this->drawables.insert(this->drawables.end(), sprites.begin(), sprites.end());
	}

	RenderLayer(int layer, sf::Drawable* sprite) : RenderLayer(layer)
	{
		this->drawables.push_back(sprite);
	}

	void Add(std::vector<sf::Drawable*>& toAdd)
	{
		this->drawables.insert(this->drawables.end(), toAdd.begin(), toAdd.end());
	}

	void Add(sf::Drawable* toAdd)
	{
		this->drawables.push_back(toAdd);
	}
};

