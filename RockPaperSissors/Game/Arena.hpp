#pragma once
#include <Vector>
#include "../KrokEngine/KrokEngine.hpp"

class Character;

class Arena : public Scene
{
public:
	Arena();
	~Arena();

	virtual void OnLoad() override;

	Character* GetNPC(int i);
	Character* GetPC(int i);

	void SetNPC(Character* character, int i);
	void SetPC(Character* character, int i);

	void RemoveCharacter(Character* character);

private:
	Character* _NPCs[4] = {nullptr, nullptr, nullptr, nullptr};
	Character* _PCs[4] = { nullptr, nullptr, nullptr, nullptr };
};
