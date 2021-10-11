#include "KrokEngine/Essentials/Game.hpp"
#include <iostream>

int main()
{
	Game myGame("Rock-Paper-Sissors-Dungeon", 1920 / 2, 1080 / 2, 60);

	ImageGameObject background("Assets/Backgrounds/RockPaperDungeon.png");
	background.name = "background";

	myGame.AddChild(background);

	GameObject fillerObject(0,0);
	fillerObject.name = "Please write this!";
	myGame.AddChild(fillerObject);
	myGame.RemoveChild(background);

	std::cout << myGame.GetChildren().size();
	//std::cout << &background <<'\n';
	//std::cout << myGame.getChild(0) << '\n';
	//std::cout << myGame.getChild(0)->name;
	//myGame.Start();

	return 0;
}