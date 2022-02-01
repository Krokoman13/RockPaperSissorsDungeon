#pragma once
#include "../KrokEngine/KrokEngine.hpp"
#include "Character.hpp""
#include "Move.hpp"
#include "RockPaperSissorsElements.hpp"

class Arena 
	: public Scene
{
public:
	Arena() : Scene("Arena")
	{
	}

	virtual void OnLoad() override
	{
		this->AddChild(new ImageGameObject("Background", 0, 0, 0));

		Character* character = new Character(3, 3, 3, new Move(Element::Paper, Move::Type::Attack, 1, "PaperSwordAttack"), new Move(Element::Rock, Move::Type::Attack, 1, "StoneSwordAttack"));
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
};
