#include "KrokEngine/KrokEngine.hpp"
#include <iostream>

#include "Game/Character.hpp"

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

	Character character(3, 3, 3);
	character.localPosition.SetXY(200, 150);
	arena.AddChild(character);

	{
		Button StartGameButton("Default Button", 0, 0);

		StartGameButton.setButtonAction([&arena, &myGame] {
			myGame.GoToScene(arena);
			});

		StartGameButton.SetText("Start Game", 50);
		StartGameButton.SetScale(0.5f);
		myGame.GetCurrentScene()->ui.AddElement(new Button(StartGameButton));
	}

	{
		Button backButton("Default Button", 0, 0);

		backButton.setButtonAction([&myGame] {
			myGame.GoToScene(0);
			});

		backButton.SetText("Default Button", 50);
		backButton.SetScale(0.5f);
		arena.ui.AddElement(new Button(backButton));
	}

	{
		Button damageButton("Default Button", 500, 400);

		damageButton.setButtonAction([&character] {
			character.health.SubstractHealth(1);
			});

		damageButton.SetText("Deal 1 damage to character", 25);
		damageButton.SetScale(0.5f);
		arena.ui.AddElement(new Button(damageButton));
	}


	myGame.Run();

	return 0;
}
