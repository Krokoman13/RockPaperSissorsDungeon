#include "Hoverable.hpp"
#include "UI.hpp"

Hoverable::Hoverable(std::string name, std::string path, float x, float y) : UIElement(name, path, x, y)
{
}

Hoverable::Hoverable(std::string name, float x, float y) : UIElement(name, x, y)
{
}

//void Hoverable::ClearUI()
//{
//	if (_ui != nullptr)
//	{
//		_ui->RemoveHoverable(this);
//		_ui->RemoveUIElement(this);
//	}
//}
//
//Hoverable::~Hoverable()
//{
//	ClearUI();
//}

const bool Hoverable::IsInside(const float x, const float y)
{
	return (x >= this->x && x <= this->x + this->GetWidth() && y >= this->y && y <= this->y + this->GetHeight());
}
