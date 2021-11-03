#pragma once
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class UI;

class UIElement
{
public:
    UIElement(std::string name, std::string path, float x = 0, float y = 0);
    UIElement(std::string name, float x = 0, float y = 0);
    UIElement(const UIElement& other);
    UIElement& operator=(const UIElement& other);
    virtual ~UIElement();

    std::string name;
    int x;
    int y;

    static std::string ASSET_PATH;
    static std::string FILE_TYPE;
    static sf::Font DEFAULT_FONT;

    void SetText(const std::string text, const int characterSize = 24, const sf::Uint32 style = sf::Text::Style::Regular, const sf::Color fillColor = sf::Color::Black);
    void SetText(const std::string text, const sf::Font& font, const int characterSize = 24, const sf::Uint32 style = sf::Text::Style::Regular, const sf::Color fillColor = sf::Color::Black);

    void SetWidth(float width);
    void SetHeight(float height);
    void SetSize(float width, float height);
    void SetScale(float xScale, float yScale);
    void SetScale(float uniformScale);

    float GetWidth();
    float GetHeight();

    void SetUI(UI* ui);

    std::vector<sf::Drawable*> GetDrawables();

protected:
    virtual sf::Sprite* getSprite();

    std::string _fullpath;

private:
    sf::Texture _texture;
    sf::Sprite _sprite;
    sf::Text _sfTtext;

    void loadTexture(std::string path);

    UI* _ui;

    float _originalWidth = 0;
    float _originalHeight = 0;
    int _originalTextCharacterSize;

    float _xScale = 1;
    float _yScale = 1;
};

