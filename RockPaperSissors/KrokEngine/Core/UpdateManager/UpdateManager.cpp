#include "UpdateManager.hpp"
#include "../../Essentials/GameObject.hpp"

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

	std::vector<sf::Drawable*> drawables;

	int parentRenderLayer = toUpdate->GetRenderLayer();
	Vec2 transformation = GameObject::GetAllTransformations(toUpdate);
	Vec2 scaleTransf = GameObject::GetAllScaleing(toUpdate);

	for (int i = toUpdate->GetChildren().size() - 1; i >= 0; --i) {
		GameObject* gameObject = toUpdate->GetChildren()[i];
		gameObject->globalScale = Vec2(gameObject->GetScale().x * scaleTransf.x, gameObject->GetScale().y * scaleTransf.y);
		gameObject->globalPosition = Vec2(transformation.x + gameObject->localPosition.x * scaleTransf.x, transformation.y + gameObject->localPosition.y * scaleTransf.y);

		this->update(gameObject);

		if (gameObject->canRender)
		{
			sf::Sprite* sprite = gameObject->GetSprite();

			sprite->setScale(gameObject->globalScale.x, gameObject->globalScale.y);
			sprite->setPosition(gameObject->globalPosition.x, gameObject->globalPosition.y);

			int currentRenderLayer = gameObject->GetRenderLayer();

			if (parentRenderLayer == currentRenderLayer) drawables.push_back(sprite);
			_renderer->ToRender(sprite, currentRenderLayer);
			continue;
		}
	}

	_renderer->ToRender(drawables, parentRenderLayer);
}
