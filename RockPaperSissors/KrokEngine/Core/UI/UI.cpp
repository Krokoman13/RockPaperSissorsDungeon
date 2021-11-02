#include "UI.hpp"

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

std::vector<Clickable*> UI::GetClickables()
{
    return _clickables;
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

    Clickable* clickable = dynamic_cast<Clickable*>(uiElement);

    if (clickable)
    {
        _clickables.push_back(clickable);
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
            return;
        }
    }

    Clickable* clickable = dynamic_cast<Clickable*>(uiElement);

    if (!clickable)
    {
        return;
    }

    for (unsigned int i = 0; i < this->_clickables.size(); i++)
    {
        if (this->_clickables[i] == uiElement)
        {
            this->_clickables.erase(this->_clickables.begin() + i);
            return;
        }
    }
}
