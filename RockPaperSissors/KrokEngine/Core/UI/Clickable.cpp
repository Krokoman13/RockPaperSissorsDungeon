#include "Clickable.hpp"

Clickable::Clickable(std::string name, std::string path, float x, float y) : Hoverable(name, path, x, y)
{
}

Clickable::Clickable(std::string name, float x, float y) : Hoverable(name, x, y)
{
}

void Clickable::OnClick()
{
}
