#pragma once
#include "../../Essentials/GameObject.hpp"

class Scene : public GameObject
{
public:
	Scene(std::string Name = "Scene", bool reloadOnOpen = false);
	bool loaded = false;
	unsigned int identifier = 0;

	void Load();
	void Close();

protected:
	virtual void load();
	virtual void close();

private:
	bool _reloadOnOpen;
};

