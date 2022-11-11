#include "Arena.hpp"
#include "Characters/Fighter.hpp"
#include "Characters/Brawler.hpp"
#include "Characters/Mage.hpp"
#include "Moves/Move.hpp"
#include "Moves/RockPaperSissorsElements.hpp"

#include "../KrokEngine/Util/FileIO.hpp"
#include "../KrokEngine/Util/StringUtil.hpp"

Arena::Arena() : Scene("Arena"), _textBoxText(), _moveExecuter()
{
	this->_rounds = 0;
	this->textBox = nullptr;
	this->_roundsCounter = nullptr;
}

Arena::~Arena()
{
	delete _moveExecuter;
	delete textBox;
	delete _roundsCounter;
}

void Arena::OnLoad()
{
	textBox = new UIElement("Textbox", 400, 450);
	textBox->SetScale(0.35f);
	ui->AddElement(textBox);

	_roundsCounter = new UIElement("RoundsCounter", 1200, 20, 20, 10);
	ui->AddElement(_roundsCounter);

	PrintText("Game start!");

	ImageGameObject* background = new ImageGameObject("Background", 0, 0, 0);
	background->SetScale(1.35f);
	this->AddChild(background);

	arenaState = ArenaState::Prepare;

	{
		Button* backButton = new Button("Default Button", 20, 20);

		backButton->setButtonAction([this] {
			this->sceneManager->GoToScene(0);
	});

		backButton->SetText("Back", 30);
		backButton->SetScale(0.25f);
		ui->AddElement(backButton);
	}

	this->_rounds = 0;

	for (int i = 0; i < 4; i++)
	{
		this->_PCs[i] = nullptr;
		this->_NPCs[i] = nullptr;
	}
}

Character* Arena::GetNPC(unsigned int i)
{
	return _NPCs[i];
}

Character* Arena::GetPC(unsigned int i)
{
	return _PCs[i];
}

void Arena::SetNPC(Character* character, unsigned int i, bool load)
{
	if (i > 3) return;

	_NPCs[i] = character;

	if (character == nullptr) return;

	AddChild(character);
	character->localPosition = points[4 + i];		
	character->SetScale(-0.75f, 0.75f);
	character->arena = this;

	if (load)
	{
		character->name = "NPC:" + std::to_string(i+1) + " " + character->name;
		character->SetScene(this);
		character->OnLoad();
		loadChildren(character);
	}
}

void Arena::SetPC(Character* character, unsigned int i, bool load)
{
	if (i > 3) return;

	_PCs[i] = character;

	if (character == nullptr) return;

	AddChild(character);
	character->localPosition = points[i];
	character->SetScale(0.75f);
	character->arena = this;

	if (load)
	{
		character->name = "PC:" + std::to_string(i+1) + " " + character->name;
		character->SetScene(this);
		character->OnLoad();
		loadChildren(character);
	}
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

void Arena::Update()
{
	updateTextBox();

	switch (arenaState)
	{
	case ArenaState::Prepare:
		randomizeField();
		_roundsCounter->SetText("Round: " + std::to_string(_rounds), 5u);
		arenaState = ArenaState::NPCSelectMoves;
		return;

	case ArenaState::NPCSelectMoves:
		setSelectorsVisible(true);

		for (unsigned int i = 0u; i < 4; i++)
		{
			if (_NPCs[i] == nullptr) break;
			_NPCs[i]->SelectRandomMove();
		}

		arenaState = ArenaState::PCSelectMoves;
		return;

	case ArenaState::PCSelectMoves:
		if (_PCs[0] == nullptr) return;

		for (unsigned int i = 0u; i < 4; i++)
		{
			if (_PCs[i] == nullptr)
			{
				break;
			}

			if (!_PCs[i]->MoveSelected())
			{
				if(sceneManager->GetGame()->ButtonDown(sf::Keyboard::R)) _PCs[i]->SelectRandomMove();
				return;
			}
		}

		setSelectorsVisible(false);
		delete _moveExecuter;
		_moveExecuter = new MoveExecuter(_PCs, _NPCs);
		arenaState = ArenaState::ExecuteMoves;
		return;

	case ArenaState::ExecuteMoves:
		if (_moveExecuter->Done())
		{
			arenaState = ArenaState::CheckWinConditions;
			return;
		}
		_moveExecuter->Step(sceneManager->GetGame()->ButtonDown(sf::Keyboard::Space));
		return;

	case ArenaState::CheckWinConditions:
		handleDeadCharacters(_PCs);
		handleDeadCharacters(_NPCs);
		fixPositionsOfCharacters();
		PrintText("");

		if (_PCs[0] == nullptr)
		{
			arenaState = ArenaState::NPCSelectMoves;
			lose();
			return;
		}

		if (_NPCs[0] == nullptr)
		{
			arenaState = ArenaState::Prepare;
			win();
			return;
		}

		arenaState = ArenaState::NPCSelectMoves;
		return;

	default:
		return;
	}
}

void Arena::PrintText(std::string line)
{
	_textBoxText.push_back(line);
	
	if (_textBoxText.size() > 20) _textBoxText.pop_front();
}

void Arena::updateTextBox()
{
	std::string out;

	for (std::string line : _textBoxText)
	{
		out += line + '\n';
	}

	textBox->SetText(out, 6u);
}

void Arena::setSelectorsVisible(bool visible)
{
	for (unsigned int i = 0u; i < 4; i++)
	{
		if (_NPCs[i] == nullptr) break;
		_NPCs[i]->SetMovesVisible(visible);
	}

	for (unsigned int i = 0u; i < 4; i++)
	{
		if (_PCs[i] == nullptr) break;
		_PCs[i]->SetMovesVisible(visible);
	}
}

bool Arena::ready()
{
	for (unsigned int i = 0u; i < 4; i++)
	{
		if (_PCs[i] == nullptr) break;
		if (!_PCs[i]->MoveSelected()) return false;
	}

	return true;
}

void Arena::randomizeField()
{
	if (_PCs[0] == nullptr)
	{
		_rounds = 1;

		for (int i = 0; i < 4; i++)
		{
			SetPC(randomCharacter(9u, i, false), i, true);
		}
	}

	unsigned int amountOfEnemies = rand() % 4u + 1u;
	unsigned int enemyStrength = ((_rounds * 2)/ amountOfEnemies) + 3u;

	for (unsigned int i = 0; i < amountOfEnemies; i++)
	{
		SetNPC(randomCharacter(enemyStrength, i, true), i, true);
	}
}

Character* Arena::randomCharacter(unsigned int power, unsigned int position, bool NPC)
{
	unsigned int rockPower = 1;
	unsigned int paperPower = 1; 
	unsigned int scissorPower = 1;

	if (power < 3) power = 3;
	power -= 3;

	for (unsigned int i = 0; i < power; i++)
	{
		unsigned int random = rand() % 3 + 1;

		switch (random)
		{
		case 1:
			rockPower++;
			break;

		case 2:
			paperPower++;
			break;

		case 3:
			scissorPower++;
			break;

		default:
			break;
		}
	}

	if ((rand() % 4u) > position)
	{
		return new Brawler(rockPower, paperPower, scissorPower, rand() % 3, rand() % 3, NPC);
	}

	if (position > 2u)
	{
		return new Mage(rockPower, paperPower, scissorPower, 0, rand() % 3 + 1, NPC);
	}

	unsigned int move1 = rand() % 3;
	unsigned int move2 = rand() % 3;

	while (move1 == move2)
	{
		move2 = rand() % 3;
	}

	return new Fighter(rockPower, paperPower, scissorPower, move1, move2, NPC);
}

void Arena::win()
{
	_rounds++;
	_roundsCounter->SetText("Round: " + _rounds, 8u);
	PrintText("");
	PrintText("Round: " + std::to_string(_rounds) + ".");
}

void Arena::handleDeadCharacters(std::vector<Character*>& characters)
{
	unsigned int i = 0;

	while (i < characters.size())
	{
		Character* character = characters[i];

		if (character == nullptr)
		{
			characters.erase(characters.begin() + i);
			continue;
		}

		if (character->health->GetHealth() <= 0)
		{
			PrintText(character->name + " perished.");
			characters[i] = nullptr;
			delete character;
			continue;
		}

		i++;
	}

	if (characters.size() == 4) return;

	while (characters.size() < 4)
	{
		characters.push_back(nullptr);
	}
}


void Arena::lose()
{
	PrintText("");
	PrintText("GAME OVER");
	PrintText("Rounds lasted: " + std::to_string(_rounds));

	Button* reloadbutton = new Button("Default Button", 980, 430);

	reloadbutton->setButtonAction([this] {
		sceneManager->reloadCurrentScene();
		});

	reloadbutton->SetText("Restart", 12);
	reloadbutton->SetScale(0.5f);
	ui->AddElement(reloadbutton);

	std::vector<std::string> scoreValues = FileIO::GetFileLines(highScoreFileName);
	std::vector<int> scores;

	for (std::string scoreValue : scoreValues)
	{
		//scoreValue = StringUtil::Substring(scoreValue, 6, 0);
		scores.push_back(stoi(scoreValue));
	}

	scores.push_back(_rounds);

	std::sort(scores.begin(), scores.end());

	scoreValues = std::vector<std::string>();

	for (int i = scores.size() - 1; i >= 0; --i)
	{
		if (scoreValues.size() > 4) break;
		scoreValues.push_back(std::to_string(scores[i]));
	}

	FileIO::WriteToFile(highScoreFileName, scoreValues);
}

void Arena::fixPositionsOfCharacters()
{
	for (unsigned int i = 0; i < 4u; i++)
	{
		SetPC(_PCs[i], i);
		SetNPC(_NPCs[i], i);
	}
}
