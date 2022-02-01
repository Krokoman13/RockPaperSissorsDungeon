#include "Game/Arena.hpp"
#include <iostream>

int main()
{
	ImageGameObject::ASSET_PATH = "Assets/";
	UIElement::ASSET_PATH = "Assets/UI/";
	UIElement::DEFAULT_FONT.loadFromFile("arial.ttf");

	Game myGame("Rock-Paper-Sissors-Dungeon", 1920 / 2, 1080 / 2, 60);

	Arena* arena = new Arena();
	myGame.AddScene(arena);

	{
		Button* StartGameButton = new Button("Default Button", 300, 200);

		StartGameButton->setButtonAction([&myGame, &arena] {
			myGame.GoToScene(arena);
			});

		StartGameButton->SetText("Start Game");
		StartGameButton->SetScale(0.5f);
		myGame.GetScene(0)->ui->AddElement(StartGameButton);
	}

	myGame.Run();

	return 0;
}
