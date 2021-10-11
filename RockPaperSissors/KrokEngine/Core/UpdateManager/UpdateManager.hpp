#pragma once
#include "../Graphics/Renderer.hpp"

class UpdateManager
{
public:
	UpdateManager();
	~UpdateManager();

	void Update(GameObject* game);
	void SetRenderer(Renderer& renderer);

private:
	Renderer* _renderer = nullptr;
	void update(GameObject* toUpdate);
};

