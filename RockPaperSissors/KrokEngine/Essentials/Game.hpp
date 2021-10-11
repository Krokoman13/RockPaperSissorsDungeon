#pragma once
#include <string>
#include "../Core/Graphics/Renderer.hpp"


class Game : public GameObject
{
public:
	Game(std::string name, unsigned int width, unsigned int height, unsigned int targetFPS);
	Game(const Game& game);
	~Game();

	void Start();

private:
	Renderer _renderer;
	//UpdateManager _updateManger;
};

