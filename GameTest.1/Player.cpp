#include "Player.h"

Player::Player()	:
	posX(0),
	posY(0),
	sizeOutside(0),
	sizeInside(0),
	speed(0)
{
}

Player::~Player()
{
}

void Player::init()
{
	posX = Game::kScreenWidth / 2;
	posY = 600;
	sizeOutside = 40;
	sizeInside = 25;

	speed = 6;

}

void Player::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);


	if (padState & PAD_INPUT_LEFT)
	{
		posX -= speed;
		if ((posX - sizeOutside) < 0)	posX = sizeOutside;
	}
	if (padState & PAD_INPUT_RIGHT)
	{
		posX += speed;
		if (posX > Game::kScreenWidth - sizeOutside)	posX = (Game::kScreenWidth - sizeOutside);
	}
	if (padState & PAD_INPUT_UP)
	{
		posY -= speed;
		if ((posY - sizeOutside) < 0)	posY = sizeOutside;
	}
	if (padState & PAD_INPUT_DOWN)
	{
		posY += speed;
		if (posY > Game::kScreenHeight - sizeOutside)	posY = (Game::kScreenHeight - sizeOutside);
	}
	




}

void Player::draw()
{
	DrawCircle(posX, posY, sizeOutside, GetColor(0, 255, 255), false);
	DrawCircle(posX, posY, sizeInside, GetColor(0, 255, 0), true);
}