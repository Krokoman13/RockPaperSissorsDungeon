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

		loadTexture(path);
		return;
	}

	loadTexture(path);
}

ImageGameObject::ImageGameObject(std::string name, float x, float y, int renderlayer) : ImageGameObject(name, ASSET_PATH, x, y, renderlayer)
{
}

ImageGameObject::ImageGameObject(const ImageGameObject& other)
{
	operator=(other);
}

ImageGameObject ImageGameObject::operator=(const ImageGameObject& other)
{
	return ImageGameObject(other.name, other.fullpath, other.localPosition.x, other.localPosition.y, other._renderLayer);
}

void ImageGameObject::loadTexture(std::string path)
{
	if (_texture.loadFromFile(path))
	{
		_sprite.setTexture(_texture);

		canRender = true;
		fullpath = path;

		_width = (float)_sprite.getTextureRect().width;
		_height = (float)_sprite.getTextureRect().height;
		return;
	}
}

ImageGameObject::~ImageGameObject()
{
}

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

	this->SetScale(width / this->_width, height / this->_height);

	//sf::IntRect rect(0, 0, (int)width, (int)height);
	//_sprite.setTextureRect(rect);
}

float ImageGameObject::GetWidth()
{
	return _width * _scale.x;
}

float ImageGameObject::GetHeight()
{
	return _height * _scale.y;
}

sf::Sprite* ImageGameObject::GetSprite()
{
	return &_sprite;
}

void ImageGameObject::CenterImageAround(Vec2 position)
{
	_sprite.setPosition(position.x - _width / 2, position.y - _height / 2);
}

const std::string ImageGameObject::GetFullPath()
{
	return fullpath;
}
