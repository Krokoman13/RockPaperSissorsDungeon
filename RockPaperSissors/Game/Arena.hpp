#pragma once
#include <vector>
#include <deque>
#include "../KrokEngine/KrokEngine.hpp"
#include "Moves/MoveExecuter.hpp"

class Character;

class Arena : public Scene
{
public:
	Arena();
	~Arena();

	std::string highScoreFileName = "";

	virtual void OnLoad() override;

	Character* GetNPC(unsigned int i);
	Character* GetPC(unsigned int i);

	void SetNPC(Character* character, unsigned int i, bool load = false);
	void SetPC(Character* character, unsigned int i, bool load = false);

	void RemoveCharacter(Character* character);

	virtual void Update() override;

	void PrintText(std::string line);

	UIElement* textBox;

private:
	int _rounds;
	UIElement* _roundsCounter;

	void updateTextBox();
	std::deque<std::string> _textBoxText;

	void setSelectorsVisible(bool visible);

	bool ready();
	void randomizeField();
	Character* randomCharacter(unsigned int power, unsigned int position, bool NPC);

	void handleDeadCharacters(std::vector<Character*>& character);
	void fixPositionsOfCharacters();

	void win();
	void lose();

	MoveExecuter* _moveExecuter;

	enum class ArenaState {Prepare, NPCSelectMoves, PCSelectMoves, ExecuteMoves, CheckWinConditions};
	ArenaState arenaState = ArenaState::Prepare;

	std::vector<Character*> _NPCs = {nullptr, nullptr, nullptr, nullptr};
	std::vector<Character*> _PCs = {nullptr, nullptr, nullptr, nullptr};

	const Vec2 points[8] = { Vec2(500, 200), Vec2(350, 200), Vec2(200, 200), Vec2(50, 200), Vec2(775, 200), Vec2(925, 200), Vec2(1075, 200), Vec2(1225, 200)};
};
