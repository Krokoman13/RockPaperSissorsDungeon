#include "UI.hpp"
#include <iostream>

std::vector<sf::Drawable*> UI::GetDrawables()
{
    std::vector<sf::Drawable*> out;

    for (UIElement* uiElement : _elements)
    {
        for (sf::Drawable* drawable : uiElement->GetDrawables())
        {
            out.push_back(drawable);
        }
    }

    return out;
}

std::vector<Hoverable*> UI::GetHoverables()
{
    return _hoverables;
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

void UI::AddElement(UIElement& uiElement)
{
    AddElement(&uiElement);
}

void UI::AddElement(UIElement* uiElement)
{
    uiElement->SetUI(this);
    _elements.push_back(uiElement);

    Hoverable* hoverable = dynamic_cast<Hoverable*>(uiElement);

    if (hoverable)
    {
        _hoverables.push_back(hoverable);
    }
}

void UI::RemoveElement(UIElement& uiElement)
{
    RemoveElement(&uiElement);
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

    Hoverable* hoverable = dynamic_cast<Hoverable*>(uiElement);

    if (!hoverable)
    {
        return;
    }

    for (unsigned int i = 0; i < this->_hoverables.size(); i++)
    {
        if (this->_hoverables[i] == uiElement)
        {
            this->_hoverables.erase(this->_hoverables.begin() + i);
            std::cout << _hoverables.size() << "\n";
            return;
        }
    }
}

std::vector<UIElement*> UI::GetElements()
{
    return _elements;
}
