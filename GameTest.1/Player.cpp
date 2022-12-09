#include "Player.h"

namespace
{
	int space = 0;
	int ShotStop = 30;
}

Player::Player()	:
	posX(0),
	posY(0),
	sizeOutside(0),
	sizeInside(0),
	speedMax(0),
	Acc(0),
	currSpeedX(0),
	currSpeedY(0),
	Dead(true)
{
}

Player::~Player()
{
}

void Player::init()
{
	sizeOutside = 70;
	sizeInside = 20;

	posX = (Game::kScreenWidth / 2) - (sizeOutside / 2);
	posY = (Game::kScreenHeight / 2) - (sizeOutside / 2);

	speedMax = 7;
	Acc = 4;

	Dead = false;
}

void Player::update(Shot shot)
{
	if (Dead)	return;

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	{
		if (padState & PAD_INPUT_LEFT)
		{
			currSpeedX -= Acc;
			if (currSpeedX < -speedMax)	currSpeedX = -speedMax;
		}
		else if (padState & PAD_INPUT_RIGHT)
		{
			currSpeedX += Acc;
			if (currSpeedX > speedMax)	currSpeedX = speedMax;
		}
		if (padState & PAD_INPUT_UP)
		{
			currSpeedY -= Acc;
			if (currSpeedY < -speedMax)	currSpeedY = -speedMax;
		}
		else if (padState & PAD_INPUT_DOWN)
		{
			currSpeedY += Acc;
			if (currSpeedY > speedMax)	currSpeedY = speedMax;
		}
		else
		{
			currSpeedX *= 0.9f;
			currSpeedY *= 0.9f;
		}

		posX += currSpeedX;
		posY += currSpeedY;

		if (posX < 0)	posX = 0;
		if (posX > Game::kScreenWidth - sizeOutside)	posX = (Game::kScreenWidth - sizeOutside);
		if (posY < 0)	posY = 0;
		if (posY > Game::kScreenHeight - sizeOutside)	posY = (Game::kScreenHeight - sizeOutside);
	}

	ShotStop--;

	if (padState & PAD_INPUT_START && ShotStop == 0)
	{
		if (space > 0)
		{
			space = -1;
			for (int i = 0; i < 10; i++)
			{





			}

			ShotStop = 30;
		}
		else
		{
			space = 0;
		}
	}

}

void Player::draw()
{
	if (Dead)	return;

	DrawCircle(posX + (sizeOutside / 2), posY + (sizeOutside / 2),
		sizeInside, GetColor(0, 255, 0), true);

	DrawBox(posX, posY, posX + sizeOutside, posY + sizeOutside,
		GetColor(0, 255, 255), false);
}