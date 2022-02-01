#include "ImageGameObject.hpp"

std::string ImageGameObject::ASSET_PATH = "";
std::string ImageGameObject::FILE_TYPE = ".png";

ImageGameObject::ImageGameObject(std::string name, std::string path, float x, float y, int renderlayer) : GameObject(Vec2(x, y), name)
{
	this->name = name;
	this->_renderLayer = renderlayer;

	if (path[path.size() - 1] == '/')
	{
		path += name;

		if (path.size() < 4) path += FILE_TYPE;
		else if (path[path.size() - 4] != '.') path += FILE_TYPE;;
	}

	this->loadTexture(path);
}

ImageGameObject::ImageGameObject(std::string name, float x, float y, int renderlayer) : ImageGameObject(name, ASSET_PATH, x, y, renderlayer)
{
}

void ImageGameObject::loadTexture(std::string path)
{
	if (this->_texture.loadFromFile(path))
	{
		this->_sprite.setTexture(_texture);

		this->canRender = true;
		this->_fullpath = path;

		this->_width = (float)_sprite.getTextureRect().width;
		this->_height = (float)_sprite.getTextureRect().height;
		return;
	}
}

void ImageGameObject::SetWidth(float width)
{
	this->SetSize(width, this->_height);
}

void ImageGameObject::SetHeight(float height)
{
	this->SetSize(this->_width, height);
}

void ImageGameObject::SetSize(float width, float height)
{
	if (width < 0 || height < 0) return;

	this->SetScale(width / this->_width, height / this->_height);
}

float ImageGameObject::GetWidth()
{
	return this->_width * this->_scale.x;
}

float ImageGameObject::GetHeight()
{
	return this->_height * this->_scale.y;
}

sf::Sprite* ImageGameObject::GetSprite()
{
	return &this->_sprite;
}

void ImageGameObject::CenterImageAround(Vec2 position)
{
	this->localPosition.SetXY(position.x - _width / 2, position.y - _height / 2);
}

const std::string ImageGameObject::GetFullPath()
{
	return this->_fullpath;
}