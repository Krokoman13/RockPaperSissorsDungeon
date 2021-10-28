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

	int parentRenderLayer = toUpdate->GetRenderLayer();
	Vec2 transformation = GameObject::GetAllTransformations(toUpdate);
	Vec2 scaleTransf = GameObject::GetAllScaleing(toUpdate);

	for (int i = toUpdate->GetChildren().size() - 1; i >= 0; --i) {
		GameObject* gameObject = toUpdate->GetChildren()[i];

		this->update(gameObject);

		if (gameObject->canRender)
		{
			sf::Sprite* sprite = gameObject->GetSprite();

			Vec2 newScale = Vec2(gameObject->GetScale().x * scaleTransf.x, gameObject->GetScale().y * scaleTransf.y);
			Vec2 newPos = Vec2(transformation.x + gameObject->localPosition.x * scaleTransf.x, transformation.y + gameObject->localPosition.y * scaleTransf.y);

			sprite->setScale(newScale.x, newScale.y);
			sprite->setPosition(newPos.x, newPos.y);

			//std::cout << gameObject->name;
			//std::cout << ", Position: " << (transformation.x + gameObject->localPosition.x, transformation.y + gameObject->localPosition.y);
			//std::cout << ", Scale: " << (gameObject->GetScale().x * scaleTransf.x, gameObject->GetScale().y * scaleTransf.y) << '\n';

			int currentRenderLayer = gameObject->GetRenderLayer();

			if (parentRenderLayer == currentRenderLayer) sprites.push_back(sprite);
			_renderer->ToRender(sprite, currentRenderLayer);
			continue;
		}
	}

	_renderer->ToRender(sprites, parentRenderLayer);
}
