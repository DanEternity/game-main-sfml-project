#pragma once

#include "base-ui.h"
#include "ui-text.h"
#include "game-enviroment.h"


class UI_ObjectImage : public UI_Image
{
public:
	int globalID;
	int localID;

	UI_ObjectImage();
	UI_ObjectImage(int ID);

	virtual void draw() override;
	virtual void setPosition(int x, int y) override;
	virtual void setSize(int width, int heigh) override;
protected:

};