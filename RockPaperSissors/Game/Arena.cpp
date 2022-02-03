#include "Arena.hpp"
#include "Characters/Fighter.hpp"
#include "Moves/Move.hpp"
#include "Moves/RockPaperSissorsElements.hpp"

Arena::Arena() : Scene("Arena")
{
}

void Arena::OnLoad()
{
	this->AddChild(new ImageGameObject("Background", 0, 0, 0));

	Character* character = new Fighter(3, 3, 3, 0, 1);
	character->localPosition.SetXY(200, 150);
	character->SetScale(0.75f);
	this->AddChild(character);

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
		Button* reloadbutton = new Button("Default Button", 480, 430);

		reloadbutton->setButtonAction([this] {
			this->sceneManager->reloadCurrentScene();
			});

		reloadbutton->SetText("Reload", 12);
		reloadbutton->SetScale(0.5f);
		this->ui->AddElement(reloadbutton);
	}
}

Character* Arena::GetNPC(int i)
{
	return _NPCs[i];
}

Character* Arena::GetPC(int i)
{
	return _PCs[i];
}

void Arena::SetNPC(Character* character, int i)
{
	if (i > 3 || i < 0) return;

	_NPCs[i] = character;
	character->arena = this;
}

void Arena::SetPC(Character* character, int i)
{
	if (i > 3 || i < 0) return;

	_PCs[i] = character;
	character->arena = this;
}

void Arena::RemoveCharacter(Character* character)
{
	for (int i = 0; i < 4; i++)
	{
		if (_NPCs[i] == character)
		{
			_NPCs[i] = nullptr;
			character->arena = nullptr;
			return;
		}

		if (_PCs[i] == character)
		{
			_PCs[i] = nullptr;
			character->arena = nullptr;
			return;
		}
	}
}
