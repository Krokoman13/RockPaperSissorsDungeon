#include "UIElement.hpp"
#include "UI.hpp"

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

//UIElement& UIElement::operator=(const UIElement& other)
//{
//	this->name = other.name;
//	this->x = other.x;
//	this->y = other.y;
//
//	this->loadTexture(other._fullpath);
//	this->SetText(other._sfTtext.getString(), *other._sfTtext.getFont(), other._sfTtext.getCharacterSize(), other._sfTtext.getStyle(), other._sfTtext.getFillColor());
//
//	this->_xScale = other._xScale;
//	this->_yScale = other._yScale;
//
//	this->_originalTextSize = other._originalTextSize;
//
//	return *this;
//}

UIElement::~UIElement()
{
	ClearUI();
}

void UIElement::SetText(const std::string text, unsigned int textSize, const sf::Uint32 style, const sf::Color fillColor)
{
	this->SetText(text, UIElement::DEFAULT_FONT, textSize, style, fillColor);
}

void UIElement::SetText(const std::string text, const sf::Font& font, unsigned int textSize, const sf::Uint32 style, const sf::Color fillColor)
{
	this->_sfTtext.setFont(font);
	this->_sfTtext.setString(text);
	this->_originalTextSize = textSize;

	this->_sfTtext.setStyle(style);
	this->_sfTtext.setFillColor(fillColor);}

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

void UIElement::SetUI(UI* ui)
{
	this->_ui = ui;
}

void UIElement::ClearUI()
{
	if (_ui == nullptr) return;

	_ui->RemoveElement(this);
	_ui = nullptr;
}

void UIElement::SetVisible(bool pVisible)
{
	this->visible = pVisible;
}

bool UIElement::IsVisible()
{
	return this->visible;
}

std::vector<sf::Drawable*> UIElement::GetDrawables()
{
	std::vector<sf::Drawable*> out;

	if (_sfTtext.getString() != "")
	{
		this->_sfTtext.setCharacterSize(this->_originalTextSize);
		//this->_sfTtext.setScale(_xScale * _originalTextSize, _xScale * _originalTextSize);
		this->_sfTtext.setOrigin(this->_sfTtext.getLocalBounds().width / 2., this->_sfTtext.getLocalBounds().height / 2.);
		this->_sfTtext.setPosition(GetWidth() / 2 + x, GetHeight() / 2 -_sfTtext.getCharacterSize()/4 + y );
		out.push_back(&_sfTtext);
	}

	this->getSprite()->setScale(_xScale, _yScale);
	//this->_sprite.setOrigin(GetWidth()/2, GetHeight()/2);
	this->getSprite()->setPosition(x, y);

	out.push_back(this->getSprite());

	return out;
}

sf::Sprite* UIElement::getSprite()
{
	return &_sprite;
}

void UIElement::loadTexture(std::string path)
{
	if (this->_texture.loadFromFile(path))
	{
		this->_sprite.setTexture(_texture);

		this->_fullpath = path;

		this->_originalWidth = (float)_sprite.getTextureRect().width;
		this->_originalHeight = (float)_sprite.getTextureRect().height;

		this->_sprite.setOrigin(0, 0);
		return;
	}
}
