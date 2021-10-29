#pragma once
#include "../../Essentials/GameObject.hpp"

class ImageGameObject :
    public GameObject
{

public:
    ImageGameObject(std::string name, std::string path, float x = 0, float y = 0, int renderlayer = -1);
    ImageGameObject(std::string name, float x = 0, float y = 0, int renderlayer = -1);
    ImageGameObject(const ImageGameObject& other);
    ImageGameObject& operator=(const ImageGameObject& other);
    virtual GameObject* Copy() override;

    static std::string ASSET_PATH;
    static std::string FILE_TYPE;

    void SetWidth(float width);
    void SetHeight(float height);
    void SetSize(float width, float height);

    float GetWidth();
    float GetHeight();

    sf::Sprite* GetSprite() override;
    void CenterImageAround(Vec2 position);
    const std::string GetFullPath();

private:
    std::string _fullpath;

    float _width = 0;
    float _height = 0;

    sf::Texture _texture;
    sf::Sprite _sprite;

    void loadTexture(std::string path);
};

