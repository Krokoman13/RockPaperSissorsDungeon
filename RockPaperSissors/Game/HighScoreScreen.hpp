#pragma once
#include "../KrokEngine/KrokEngine.hpp"

class HighscoreScreen : public Scene
{
public:
	HighscoreScreen(const std::string &pFileName);
	virtual void OnLoad() override;

private:
	std::string _fileName;
};

