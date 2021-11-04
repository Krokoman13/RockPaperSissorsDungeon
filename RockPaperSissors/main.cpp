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
		Button defaultButton("Default Button", 0, 0);

		defaultButton.setButtonAction([&arena, &myGame] {
			myGame.GoToScene(arena);
			});

		defaultButton.SetText("Start Game", 50);
		defaultButton.SetScale(0.5f);
		myGame.GetCurrentScene()->ui.AddElement(new Button(defaultButton));
	}

	myGame.Run();

	return 0;
}
