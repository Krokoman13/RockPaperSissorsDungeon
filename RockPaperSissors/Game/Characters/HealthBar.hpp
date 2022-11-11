#pragma once
#include "../../KrokEngine/KrokEngine.hpp"

class HealthBar :
    public GameObject
{
public:
    HealthBar(float x, float y, int maxHealth);
    virtual ~HealthBar();

    void SetHealth(const int amount);
    int GetHealth();
    void AddHealth(const unsigned int amount);
    void SubstractHealth(const unsigned int amount);

    const unsigned int GetCurrentHealth() const;
    const unsigned int GetMaxHealth() const;

    virtual void Update() override;
    virtual void OnLoad() override;

private:
    int _maxHealth;
    int _currentHealth;

    UIElement* _bar;
    UIElement* _counter;
};

