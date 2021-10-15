#include "UpdateManager.hpp"

UpdateManager::UpdateManager()
{
}

UpdateManager::~UpdateManager()
{
}


void UpdateManager::Update(GameObject* game)
{
	update(game);
}

void UpdateManager::SetRenderer(Renderer& renderer)
{
	_renderer = &renderer;
}

void UpdateManager::update(GameObject* toUpdate)
{
	toUpdate->Update();

	std::vector<sf::Sprite*> sprites;
	//int parentRenderLayer = toUpdate->GetRenderLayer();
	Vec2 transformation = GameObject::GetAllTransformations(toUpdate);

	for (int i = toUpdate->GetChildren().size() - 1; i >= 0; --i) {
		GameObject* gameObject = toUpdate->GetChildren()[i];

		this->update(gameObject);

		if (gameObject->canRender)
		{
			sf::Sprite* sprite = gameObject->GetSprite();

			sprite->setPosition(transformation.x + gameObject->localPosition.x, transformation.y + gameObject->localPosition.y);

			int currentRenderLayer = gameObject->GetRenderLayer();
			//if (parentRenderLayer == currentRenderLayer) sprites.push_back(sprite);
			_renderer->ToRender(sprite, currentRenderLayer);
			continue;
		}
	}

	//_renderer->ToRender(sprites, parentRenderLayer);
}
