#include "ImageGameObject.hpp"

ImageGameObject::ImageGameObject(std::string path, float x, float y) : GameObject(Vec2(x, y))
{
	this->name = "ImageGameObject";

	if (texture.loadFromFile(path))
	{
		sprite.setTexture(texture);
		
		canRender = true;

		width = (float)sprite.getTextureRect().width;
		height = (float)sprite.getTextureRect().height;
	}
}

ImageGameObject::~ImageGameObject()
{
}

void ImageGameObject::SetWidth(float width)
{
	SetSize(width, this->height);
}

void ImageGameObject::SetHeight(float height)
{
	SetSize(this->width, height);
}

void ImageGameObject::SetSize(float width, float height)
{
	if (width < 0 || height < 0) return;

	sf::IntRect rect(0, 0, (int)width, (int)height);
	sprite.setTextureRect(rect);
}

sf::Sprite* ImageGameObject::GetSprite()
{
	return &sprite;
}

void ImageGameObject::CenterImageAround(Vec2 position)
{
	sprite.setPosition(position.x - width / 2, position.y - height / 2);
}
