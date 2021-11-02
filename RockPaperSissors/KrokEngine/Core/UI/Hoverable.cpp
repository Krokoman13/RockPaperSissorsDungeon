#include "Hoverable.hpp"

Hoverable::Hoverable(std::string name, std::string path, float x, float y) : UIElement(name, path, x, y)
{
}

Hoverable::Hoverable(std::string name, float x, float y) : UIElement(name, x, y)
{
}

const bool Hoverable::IsInside(const int x, const int y)
{
	return (x >= this->x && x <= this->x + this->GetWidth() && y >= this->y && y <= this->y + this->GetHeight());
}
