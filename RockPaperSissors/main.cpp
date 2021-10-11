#include "KrokEngine/Essentials/Game.hpp"
#include <iostream>
#include "main.h"

int main()
{
	Game myGame("Rock-Paper-Sissors-Dungeon", 1920 / 2, 1080 / 2, 60);

	ImageGameObject background("Assets/Background.png");
	background.SetRenderLayer(0);
	background.name = "background";
	myGame.AddChild(background);

	ImageGameObject character("Assets/Blank Fighter - without arm.png", 200, 150);
	character.SetRenderLayer(2);
	myGame.AddChild(character);

	ImageGameObject arm("Assets/Blank Fighter - arm.png");
	arm.SetRenderLayer(2);
	character.AddChild(arm);

	ImageGameObject scissor("Assets/Scissor.png", 0, 50);
	scissor.SetRenderLayer(1);
	character.AddChild(scissor);

	myGame.Start();

	return 0;
}

void HiarcyTest()
{
	GameObject gameObjectA(1, 1, "A");
	GameObject gameObjectB(10, 10, "B");
	GameObject gameObjectC(100, 100, "C");
	GameObject gameObjectD(-5, -5, "D");

	//myGame.AddChild(gameObjectA);
	std::cout << gameObjectA.GetGlobaPosition();

	gameObjectB.AddChild(gameObjectA);
	std::cout << gameObjectA.GetGlobaPosition();

	gameObjectC.AddChild(gameObjectA);
	std::cout << gameObjectA.GetGlobaPosition();

	gameObjectD.AddChild(gameObjectA);
	std::cout << gameObjectA.GetGlobaPosition();

	gameObjectB.AddChild(gameObjectC);
	gameObjectC.AddChild(gameObjectD);
	gameObjectD.AddChild(gameObjectA);
	std::cout << gameObjectA.GetGlobaPosition();
}
