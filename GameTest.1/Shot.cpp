#include "Shot.h"

Shot::Shot()	:
	posX(0),
	posY(0),
	size(0),
	speed(0),
	Dead(true)
{
}

Shot::~Shot()
{
}

void Shot::init()
{
	
}

void Shot::update()
{
	if (Dead)	return;

	posY += speed;
	if (posY < 0)	Dead = true;

}

void Shot::draw()
{
	if (Dead)	return;

	DrawCircle(posX, posY, size, GetColor(255, 255, 0), true);
}
