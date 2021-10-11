#pragma once
#include "../../Essentials/GameObject.hpp"

class ImageGameObject :
    public GameObject
{

public:
    ImageGameObject(std::string path, float x = 0, float y = 0);
    ~ImageGameObject();

    void SetWidth(float width);
    void SetHeight(float height);
    void SetSize(float width, float height);

    sf::Sprite* GetSprite() override;
    void CenterImageAround(Vec2 position);

private:
    float width = 0;
    float height = 0;

    sf::Texture texture;
    sf::Sprite sprite;
};

