#pragma once
#include "../KrokEngine/KrokEngine.hpp"

class HealthBar :
    public GameObject
{
public:
    HealthBar(int x, int y, int maxHealth);
    HealthBar(const HealthBar& other);
    HealthBar& operator=(const HealthBar& other);
    virtual GameObject* Copy() override;
    virtual ~HealthBar();

    void SetHealth(int amount);
    void AddHealth(int amount);
    void SubstractHealth(int amount);

    virtual void Update() override;
    virtual void OnLoad() override;

private:
    int _maxHealth;
    int _currentHealth;

    UIElement _bar;
    UIElement _counter;
};

