#pragma once
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class UIElement
{
public:
    UIElement(std::string name, std::string path, float x = 0, float y = 0);
    UIElement(std::string name, float x = 0, float y = 0);
    UIElement(const UIElement& other);
    UIElement& operator=(const UIElement& other);

    std::string name;
    int x;
    int y;

    static std::string ASSET_PATH;
    static std::string FILE_TYPE;
    static sf::Font DEFAULT_FONT;

    void setText(std::string text, int characterSize = 12, sf::Uint32 style = sf::Style::Default, sf::Color fillColor = sf::Color::Black);
    void setText(std::string text, sf::Font font, int characterSize = 12, sf::Uint32 style = sf::Style::Default, sf::Color fillColor = sf::Color::Black);

    void SetWidth(float width);
    void SetHeight(float height);
    void SetSize(float width, float height);
    void SetScale(float xScale, float yScale);
    void SetScale(float uniformScale);

    float GetWidth();
    float GetHeight();

    std::vector<sf::Drawable*> GetDrawables();

private:
    std::string _fullpath;

    float _originalWidth = 0;
    float _originalHeight = 0;

    float _xScale = 1;
    float _yScale = 1;

    sf::Texture _texture;
    sf::Sprite _sprite;
    sf::Text _sfTtext;

    void loadTexture(std::string path);
};

