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
    ~UIElement();

    std::string name;
    int x;
    int y;

    static std::string ASSET_PATH;
    static std::string FILE_TYPE;
    static sf::Font DEFAULT_FONT;

    void SetText(std::string text, int characterSize = 24, sf::Uint32 style = sf::Text::Style::Regular, sf::Color fillColor = sf::Color::Black);
    void SetText(std::string text, sf::Font& font, int characterSize = 24, sf::Uint32 style = sf::Text::Style::Regular, sf::Color fillColor = sf::Color::Black);

    void SetWidth(float width);
    void SetHeight(float height);
    void SetSize(float width, float height);
    void SetScale(float xScale, float yScale);
    void SetScale(float uniformScale);

    float GetWidth();
    float GetHeight();

    void SetUI(UI* ui);

    std::vector<sf::Drawable*> GetDrawables();

private:
    UI* _ui;

    std::string _fullpath;

    float _originalWidth = 0;
    float _originalHeight = 0;
    int _originalTextCharacterSize;

    float _xScale = 1;
    float _yScale = 1;

    sf::Texture _texture;
    sf::Sprite _sprite;
    sf::Text _sfTtext;

    void loadTexture(std::string path);
};

