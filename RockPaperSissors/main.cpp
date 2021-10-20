#include "KrokEngine/Essentials/Game.hpp"
#include <iostream>

int main()
{
	ImageGameObject::ASSET_PATH = "Assets/";
	Game myGame("Rock-Paper-Sissors-Dungeon", 1920 / 2, 1080 / 2, 60);

	ImageGameObject background("Background", myGame, 0, 0, 0);

	ImageGameObject character("Fighter", "Assets/Blank Fighter - without arm.png", myGame, 200, 150, 1);
	ImageGameObject scissor("Scissor", character, 0, 50);
	ImageGameObject arm("R - Arm", "Assets/Blank Fighter - arm.png", character);

	myGame.Run();

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
