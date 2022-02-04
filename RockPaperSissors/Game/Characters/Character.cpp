#include "Character.hpp"
#include "../Moves/MoveSelector.hpp"
#include "../Arena.hpp"
#include "../Moves/RockPaperSissorsElements.hpp"
#include "../Moves/Move.hpp"

Character::Character(bool NPC, unsigned int rockPower, unsigned int paperPower, unsigned int scissorPower, Move* move1, Move* move2, std::string name, std::string path)
	: ImageGameObject(name, path, 0, 0, 1)
{
	this->NPC = NPC;
	_rockModifier = rockPower;
	_paperModifier = paperPower;
	_scissorModifier = scissorPower;

	health = new HealthBar(-25, -60, rockPower * 10);
	health->SetScale(0.17f);
	AddChild(health);

	SetShield(Element::NONE);

	selector = new MoveSelector(move1, move2, -10, -125, NPC);
	AddChild(selector);
}

Character::~Character()
{
	delete _stats;
}

void Character::OnLoad()
{
	_stats = new UIElement("BorderBar", "Assets/UI/HealthBar/", -20, -30);
	_scene->ui->AddElement(_stats);
}

void Character::Update()
{
	Vec2 pos = globalPosition;
	Vec2 scale = globalScale * 0.17f;

	_stats->x = pos.x -145 * scale.x;
	_stats->y = pos.y -145 * scale.y;

	_stats->SetScale(scale.x, scale.y);
	_stats->SetText("R: "+ std::to_string(_rockModifier)+"   P: "+ std::to_string(_paperModifier)+"   S: "+ std::to_string(_scissorModifier));
}

void Character::RecieveDamage(unsigned int amount, Element type, std::string sourceName)
{
	if (health->GetHealth() <= 0)
	{
		arena->PrintText(sourceName + "Failed, " + name + " is already dead.");
		return;
	}

	if (_shield == CounterTo(type))
	{
		SetShield(Element::NONE);
		arena->PrintText(name + " blocked damage from: " + sourceName + " via shield.");
		return;
	}

	if (_shield == type)
	{
		SetShield(Element::NONE);
		health->SubstractHealth(amount/2);
		arena->PrintText(name + " recieved " + std::to_string(amount/2) + " damage from: " + sourceName + " (halved via shield).");
		return;
	}

	SetShield(Element::NONE);
	arena->PrintText(name + " recieved " + std::to_string(amount) + " damage from: " + sourceName + ".");
	health->SubstractHealth(amount);
}

void Character::SetShield(Element shieldElement)
{
	if (_shield != Element::NONE)
	{
		RemoveChild(_currentShield);
		delete _currentShield;
	}

	_shield = shieldElement;

	if (_shield != Element::NONE)
	{
		_currentShield = getImageShield(_shield);
		AddChild(_currentShield);
		arena->PrintText(name + " recieved a " + ToString(shieldElement) + " shield.");
	}
}

const Element Character::GetShield()
{
	return _shield;
}

unsigned int Character::GetModifier(Element element)
{
	switch (element)
	{
	case Rock:
		return _rockModifier;
	case Paper:
		return _paperModifier;
	case Scissors:
		return _scissorModifier;
	default:
		return 0;
	}
}

bool Character::MoveSelected()
{
	return selector->selectedMove != nullptr;
}

void Character::SelectRandomMove()
{
	if ((rand() % 20) == 1)
	{
		selector->Select(3);
		return;
	}

	selector->Select(rand() % 2 + 1);
}

void Character::SetMovesVisible(bool visible)
{
	selector->SetVisible(visible);
}

const unsigned int Character::GetPaperModifier() const
{
	return _paperModifier;
}

void Character::ExecuteMove()
{
	if (selector->selectedMove == nullptr) return;

	if (health->GetHealth() <= 0) return;

	selector->selectedMove->ExecuteMove(*this);
	selector->Reset();
}

ImageGameObject* Character::getImageShield(Element element)
{
	switch (element)
	{
	case Rock:
		return new ImageGameObject("RockShield", "Assets/", 0, 0);

	case Scissors:
		return new ImageGameObject("ScissorShield", "Assets/", 0, 0);

	case Paper:
		return new ImageGameObject("PaperShield", "Assets/", 0, 0);

	default:
		return nullptr;
	}
}
