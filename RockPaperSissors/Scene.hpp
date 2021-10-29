#pragma once
#include "../../Essentials/GameObject.hpp"

class Scene : public GameObject
{
public:
	Scene(std::string Name = "Scene");
	unsigned int identifier = 0;
};

