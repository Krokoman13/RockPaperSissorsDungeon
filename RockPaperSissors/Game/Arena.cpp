#include "Arena.hpp"
#include "Characters/Character.hpp"
#include "Moves/Move.hpp"
#include "Moves/RockPaperSissorsElements.hpp"

Arena::Arena() : Scene("Arena")
{
}

void Arena::OnLoad()
{
	this->AddChild(new ImageGameObject("Background", 0, 0, 0));

	Character* character = new Character(3, 3, 3, new DefaultSwordMove(Element::Paper, 2), new DefaultSwordMove(Element::Rock, 2));
	character->localPosition.SetXY(200, 150);
	this->AddChild(character);

	{
		Button* backButton = new Button("Default Button", 20, 20);

		backButton->setButtonAction([this] {
			this->sceneManager->GoToScene(0);
			});

		backButton->SetText("Back", 40);
		backButton->SetScale(0.25f);
		ui->AddElement(backButton);
	}

	{
		Button* damageButton = new Button("Default Button", 20, 430);

		damageButton->setButtonAction([character] {
			character->health->SubstractHealth(1);
			});

		damageButton->SetText("Deal 1 damage to character", 15);
		damageButton->SetScale(0.5f);
		this->ui->AddElement(damageButton);
	}

	{
		Button* damageButton = new Button("Default Button", 280, 430);

		damageButton->setButtonAction([character] {
			character->health->AddHealth(1);
			});

		damageButton->SetText("Heal character with 1", 15);
		damageButton->SetScale(0.5f);
		this->ui->AddElement(damageButton);
	}

	{
		Button* reloadbutton = new Button("Default Button", 480, 430);

		reloadbutton->setButtonAction([this] {
			this->sceneManager->reloadCurrentScene();
			});

		reloadbutton->SetText("Reload", 15);
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
