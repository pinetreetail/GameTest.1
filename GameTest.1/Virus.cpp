#include "Virus.h"

namespace
{
	bool resize = true;
}

Virus::Virus()	:
	posX(0),
	posY(0),
	sizeOutside(0),
	sizeInside(0),
	speed(0),
	ColorOutside(0),
	ColorInside(0),
	Dead(true)
{
}

Virus::~Virus()
{
}

void Virus::init()
{
	posX = GetRand(Game::kScreenWidth - sizeOutside);
	posY = 0;
	sizeOutside = 60;
	sizeInside = 20;

	speed = 4;

	ColorOutside = GetColor(255, 0, 0);
	ColorInside = GetColor(0, 0, 255);

	Dead = false;
}

void Virus::update()
{
	if (Dead)	return;

	if (resize)
	{
		sizeInside--;
		if (sizeInside == 10)	resize = false;
	}
	else if (resize == false)
	{
		sizeInside++;
		if (sizeInside == 20)	resize = true;
	}

	posY += speed;

	if (posY > Game::kScreenHeight - sizeOutside)	Dead = true;
}

void Virus::draw()
{
	if (Dead)	return;

	DrawBox(posX, posY, posX + sizeOutside, posY + sizeOutside,
		ColorOutside, false);
	DrawCircle(posX + (sizeOutside / 2), posY + (sizeOutside / 2),
		sizeInside, ColorInside, true);
}
