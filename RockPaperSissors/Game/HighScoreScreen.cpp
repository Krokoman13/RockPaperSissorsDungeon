#include "HighScoreScreen.hpp"
#include "../KrokEngine/Util/FileIo.hpp"
#include "../KrokEngine/Util/StringUtil.hpp"

HighscoreScreen::HighscoreScreen(const std::string& pFileName) : Scene("HighscoreScreen", true)
{
	this->_fileName = pFileName;
	_reloadOnOpen = true;
}

void HighscoreScreen::OnLoad()
{
	{
		Button* backButton = new Button("Default Button", 20, 20);

		backButton->setButtonAction([this] {
			this->sceneManager->GoToScene(0);
			});

		backButton->SetText("Back", 30);
		backButton->SetScale(0.25f);
		ui->AddElement(backButton);
	}

	{
		Button* backButton = new Button("Default Button", 1000, 20);

		backButton->setButtonAction([this] {
			FileIO::WriteToFile(this->_fileName, "");
			this->sceneManager->reloadCurrentScene();
			});

		backButton->SetText("Clear", 30);
		backButton->SetScale(0.25f);
		ui->AddElement(backButton);
	}

	{
		Button* backButton = new Button("Default Button", 20, 20);

		backButton->setButtonAction([this] {
			this->sceneManager->GoToScene(0);
			});

		UIElement* scoreBoard = new UIElement("ScoreboardText", 0, -300, (float)sceneManager->GetGame()->GetWitdth(), (float)sceneManager->GetGame()->GetHeight());

		std::string fullText = FileIO::ReadFile(_fileName);

		scoreBoard->SetText(fullText, 17U, 0U, sf::Color::White);
		ui->AddElement(scoreBoard);

	}
}
