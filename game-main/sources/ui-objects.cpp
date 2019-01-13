#include "ui-objects.h"

UI_ObjectImage::UI_ObjectImage()
{
}

UI_ObjectImage::UI_ObjectImage(int ID)
{
	globalID = GetUID();
	localID = ID;
}

void UI_ObjectImage::draw()
{
	UI_Image::draw();
}

void UI_ObjectImage::setPosition(int x, int y)
{
	UI_Image::setPosition(x, y);
}

void UI_ObjectImage::setSize(int width, int heigh)
{
	UI_Image::setSize(width, heigh);
}
