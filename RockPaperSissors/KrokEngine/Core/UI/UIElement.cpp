#include "UIElement.hpp"

std::string UIElement::ASSET_PATH = "";
std::string UIElement::FILE_TYPE = ".png";
sf::Font UIElement::DEFAULT_FONT = sf::Font();

UIElement::UIElement(std::string name, std::string path, float x, float y)
{
	this->name = name;
	this->x = x;
	this->y = y;

	if (path[path.size() - 1] == '/')
	{
		path += name;

		if (path.size() < 4) path += FILE_TYPE;
		else if (path[path.size() - 4] != '.') path += FILE_TYPE;;
	}

	loadTexture(path);
}

UIElement::UIElement(std::string name, float x, float y) : UIElement(name, ASSET_PATH, x, y)
{
}

UIElement::UIElement(const UIElement& other)
{
	operator=(other);
}

UIElement& UIElement::operator=(const UIElement& other)
{
	this->name = other.name;
	this->x = other.x;
	this->y = other.y;

	this->loadTexture(other._fullpath);
	return *this;
}

void UIElement::setText(std::string text, int characterSize, sf::Uint32 style, sf::Color fillColor)
{
	this->setText(text, UIElement::DEFAULT_FONT, characterSize, style, fillColor);
}

void UIElement::setText(std::string text, sf::Font font, int characterSize, sf::Uint32 style, sf::Color fillColor) 
{
	this->_sfTtext.setString(text);
	this->_sfTtext.setFont(font);
	this->_sfTtext.setCharacterSize(characterSize);
	this->_sfTtext.setStyle(style);
	this->_sfTtext.setFillColor(fillColor);
}

void UIElement::SetWidth(float width)
{
	SetSize(width, this->_originalHeight);
}

void UIElement::SetHeight(float height)
{
	SetSize(this->_originalWidth, height);
}

void UIElement::SetSize(float width, float height)
{
	if (width < 0 || height < 0) return;

	this->SetScale(width / this->_originalWidth, height / this->_originalHeight);
}

void UIElement::SetScale(float xScale, float yScale)
{
	this->_xScale = xScale;
	this->_yScale = yScale;
}

void UIElement::SetScale(float uniformScale)
{ 
	this->SetScale(uniformScale, uniformScale);
}

float UIElement::GetWidth()
{
	return this->_originalWidth * this->_xScale;
}

float UIElement::GetHeight()
{
	return this->_originalHeight * this->_yScale;
}

std::vector<sf::Drawable*> UIElement::GetDrawables()
{
	std::vector<sf::Drawable*> out;

	_sprite.setOrigin(x, y);
	_sprite.scale(_xScale, _yScale);
	out.push_back(&this->_sprite);
	
	if (_sfTtext.getString() != "")
	{
		_sfTtext.setOrigin(x, y);
		_sfTtext.scale(_xScale, _yScale);
		out.push_back(&_sfTtext);
	}

	return out;
}

void UIElement::loadTexture(std::string path)
{
	if (this->_texture.loadFromFile(path))
	{
		this->_sprite.setTexture(_texture);

		this->_fullpath = path;

		this->_originalWidth = (float)_sprite.getTextureRect().width;
		this->_originalHeight = (float)_sprite.getTextureRect().height;
		return;
	}
}
