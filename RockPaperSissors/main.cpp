#include "Game/Arena.hpp"
#include "Game/HighScoreScreen.hpp"
//#include <iostream>

int main()
{
	ImageGameObject::ASSET_PATH = "Assets/";
	UIElement::ASSET_PATH = "Assets/UI/";
	UIElement::DEFAULT_FONT.loadFromFile("arial.ttf");

	Game myGame("Rock-Paper-Sissors-Dungeon", 1280, 720, 60);

	Arena* arena = new Arena();
	arena->highScoreFileName = "Highscores.cmgt";
	myGame.AddScene(arena);

	HighscoreScreen* scoreScreen = new HighscoreScreen(arena->highScoreFileName);
	myGame.AddScene(scoreScreen);

	{
		Button* startGameButton = new Button("Default Button", 300, 200);

		startGameButton->setButtonAction([&myGame, &arena] {
			myGame.GoToScene(arena);
			});

		startGameButton->SetText("Start Game", 12);
		startGameButton->SetScale(0.5f);
		myGame.GetScene(0)->ui->AddElement(startGameButton);
	}

	{
		Button* goToHighscoreButton = new Button("Default Button", 300, 500);

		goToHighscoreButton->setButtonAction([&myGame, &scoreScreen] {
			myGame.GoToScene(scoreScreen);
			});

		goToHighscoreButton->SetText("HighScores", 12);
		goToHighscoreButton->SetScale(0.5f);
		myGame.GetScene(0)->ui->AddElement(goToHighscoreButton);
	}

	myGame.Run();

	return 0;
}
