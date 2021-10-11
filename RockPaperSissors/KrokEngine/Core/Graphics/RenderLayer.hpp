#pragma once
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

struct RenderLayer
{
	int layer = -1;
	std::vector<sf::Sprite*> sprites;

	RenderLayer(int layer)
	{
		this->layer = layer;

		std::cout << "New layer created: "<< this->layer <<".\n";
	}

	RenderLayer(int layer, std::vector<sf::Sprite*>& sprites) : RenderLayer(layer)
	{
		this->sprites.insert(this->sprites.end(), sprites.begin(), sprites.end());
	}

	RenderLayer(int layer, sf::Sprite* sprite) : RenderLayer(layer)
	{
		this->sprites.push_back(sprite);
	}

	void Add(std::vector<sf::Sprite*>& toAdd)
	{
		this->sprites.insert(this->sprites.end(), toAdd.begin(), toAdd.end());
	}

	void Add(sf::Sprite* toAdd)
	{
		this->sprites.push_back(toAdd);
	}
};

