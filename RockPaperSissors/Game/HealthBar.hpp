#pragma once
#include "../KrokEngine/Essentials/GameObject.hpp"

class UIElement;

class HealthBar :
    public GameObject
{
public:
    HealthBar(int x, int y, int maxHealth);

    void SetHealth(int amount);
    void AddHealth(int amount);
    void SubstractHealth(int amount);

    virtual void Update() override;

private:
    int _maxHealth;
    int _currentHealth;

    UIElement* _bar;
    UIElement* _counter;
};

