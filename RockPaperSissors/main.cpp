#include "KrokEngine/KrokEngine.hpp"
#include <iostream>

#include "Game/HealthBar.hpp"

int main()
{
	ImageGameObject::ASSET_PATH = "Assets/";
	UIElement::ASSET_PATH = "Assets/UI/";
	UIElement::DEFAULT_FONT.loadFromFile("arial.ttf");

	Game myGame("Rock-Paper-Sissors-Dungeon", 1920 / 2, 1080 / 2, 60);

	Scene arena("Arena");
	myGame.AddScene(arena);

	ImageGameObject background("Background");
	arena.AddChild(background);

	{
		ImageGameObject character("Fighter", "Assets/Blank Fighter - without arm.png", 200, 150, 1);
		character.AddChild(new ImageGameObject("Scissor", "Assets/", 0, 50));
		character.AddChild(new ImageGameObject("R - Arm", "Assets/Blank Fighter - arm.png"));
		arena.AddChild(new ImageGameObject(character));
	}
	
	Button defaultButton("Default Button", 0, 0);

	defaultButton.setButtonAction([&arena, &myGame] {
		myGame.GoToScene(arena);
		});

	defaultButton.SetText("Start Game", 50);
	defaultButton.SetScale(0.5f);

	myGame.GetCurrentScene()->AddChild(new HealthBar(0, 0, 10));
	myGame.GetCurrentScene()->ui.AddElement(defaultButton);

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
