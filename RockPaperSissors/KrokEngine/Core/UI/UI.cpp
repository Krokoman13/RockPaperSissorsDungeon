#include "UI.hpp"
#include <iostream>

UI::~UI()
{
    while (_elements.size() > 0)
    {
        UIElement* element = _elements.back();
        _elements.pop_back();
        element->SetUI(nullptr);

        delete element;
    }
}

std::vector<sf::Drawable*> UI::GetDrawables()
{
    std::vector<sf::Drawable*> out;

    for (UIElement* uiElement : _elements)
    {
        if (!uiElement->IsVisible()) continue;

        for (sf::Drawable* drawable : uiElement->GetDrawables())
        {
            out.push_back(drawable);
        }
    }

    return out;
}

std::vector<Hoverable*> UI::GetHoverables()
{
    std::vector<Hoverable*> hoverables;

    for (UIElement* uiElement : _elements)
    {
        Hoverable* hoverable = dynamic_cast<Hoverable*>(uiElement);

        if (hoverable != nullptr)
        {
            hoverables.push_back(hoverable);
        }
    }

    return hoverables;
}

void UI::SetDefaultFont(sf::Font font)
{
    UIElement::DEFAULT_FONT = font;
}

void UI::SetDefaultFont(std::string fontFile)
{
    sf::Font temp;
    
    if (temp.loadFromFile(fontFile))
    {
        SetDefaultFont(temp);
    }
}

void UI::AddElement(UIElement* uiElement)
{
    uiElement->SetUI(this);
    _elements.push_back(uiElement);
}

void UI::RemoveElement(UIElement* uiElement)
{
    for (unsigned int i = 0; i < this->_elements.size(); i++)
    {
        if (this->_elements[i] == uiElement)
        {
            this->_elements[i]->SetUI(nullptr);
            this->_elements.erase(this->_elements.begin() + i);
            continue;
        }
    }
}

const std::vector<UIElement*> UI::GetElements()
{
    return _elements;
}
