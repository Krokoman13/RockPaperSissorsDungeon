#include "ImageGameObject.hpp"

ImageGameObject::ImageGameObject(std::string name, std::string path, GameObject* parent, float x, float y, int renderlayer) : GameObject(Vec2(x, y), name, parent)
{
	this->name = name;
	this->_renderLayer = renderlayer;

	if (path[path.size() - 1] == '/')
	{
		path += name;

		if (path.size() < 4) path += FILE_TYPE;
		else if (path[path.size() - 4] != '.') path += FILE_TYPE;;

		loadTexture(path);
		return;
	}

	loadTexture(path);
}

ImageGameObject::ImageGameObject(std::string name, GameObject* parent, float x, float y, int renderlayer) : ImageGameObject(name, ASSET_PATH, parent, x, y, renderlayer)
{
}

ImageGameObject::ImageGameObject(std::string name, GameObject& parent, float x, float y, int renderlayer) : ImageGameObject(name, ASSET_PATH, &parent, x, y, renderlayer)
{
}

ImageGameObject::ImageGameObject(std::string name, float x, float y) : ImageGameObject(name, ASSET_PATH, nullptr, x, y)
{
}

void ImageGameObject::loadTexture(std::string path)
{
	if (_texture.loadFromFile(path))
	{
		_sprite.setTexture(_texture);

		canRender = true;

		_width = (float)_sprite.getTextureRect().width;
		_height = (float)_sprite.getTextureRect().height;
		return;
	}
}

ImageGameObject::~ImageGameObject()
{
}

std::string ImageGameObject::ASSET_PATH = "";
std::string ImageGameObject::FILE_TYPE = ".png";

void ImageGameObject::SetWidth(float width)
{
	SetSize(width, this->_height);
}

void ImageGameObject::SetHeight(float height)
{
	SetSize(this->_width, height);
}

void ImageGameObject::SetSize(float width, float height)
{
	if (width < 0 || height < 0) return;

	sf::IntRect rect(0, 0, (int)width, (int)height);
	_sprite.setTextureRect(rect);
}

sf::Sprite* ImageGameObject::GetSprite()
{
	return &_sprite;
}

void ImageGameObject::CenterImageAround(Vec2 position)
{
	_sprite.setPosition(position.x - _width / 2, position.y - _height / 2);
}
