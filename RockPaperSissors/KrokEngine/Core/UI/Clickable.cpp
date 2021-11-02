#include "Clickable.hpp"

Clickable::Clickable(std::string name, std::string path, float x, float y) : UIElement(name, path, x, y)
{
}

Clickable::Clickable(std::string name, float x, float y) : UIElement(name, x, y)
{
}

void Clickable::OnClick()
{
}

void Clickable::StartHover()
{
}

void Clickable::StopHover()
{
}

const bool Clickable::IsInside(const int x, const int y)
{
	return (x >= this->x && x <= this->x + this->GetWidth() && y >= this->y && y <= this->y + this->GetHeight());
}
